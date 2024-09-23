#ifndef CURRENT_SCREEN_H
#define CURRENT_SCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "spaceScreen.h"
#include "planetScreen.h"
#include "player.h"
#include "worldObj.h"

class CurrentScreen
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window, Player &player, Select &select);
    void handleEvent(sf::RenderWindow &window, sf::Event event, Player &player, Select &select);
    void handleSreenSwitch();
    void setScreen(std::string name);
    bool isNewSreen();
    std::vector<WorldObj> *getWorldObjs();
    std::string screen = "planet";
    SpaceScreen spaceScreen;
    PlanetScreen planetScreen;
    bool changeScreen = false;

private:
};

#endif // CURRENT_SCREEN_H
