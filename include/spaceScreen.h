#ifndef SPACE_SCREEN_H
#define SPACE_SCREEN_H
#include <SFML/Graphics.hpp>
#include "spaceMap.h"
#include "worldObj.h"
// #include "player.h"
// #include "select.h"

class Player;
class Select;

class SpaceScreen
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window, Player &player, Select &select);
    void handleEvent(sf::RenderWindow &window, sf::Event event, Player &player, Select &select);
    std::string screen = "space";
    SpaceMap map;

private:
    void loadTextures();
    std::vector<sf::Texture *> textures;
};

#endif // SPACE_SCREEN_H
