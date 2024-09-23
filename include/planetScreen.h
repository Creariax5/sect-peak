#ifndef PLANET_SCREEN_H
#define PLANET_SCREEN_H
#include <SFML/Graphics.hpp>
#include "planetMap.h"
#include "worldObj.h"
// #include "player.h"
// #include "select.h"

class Player;
class Select;

class PlanetScreen
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window, Player &player, Select &select);
    void handleEvent(sf::RenderWindow &window, sf::Event event, Player &player, Select &select);
    std::string screen = "planet";
    PlanetMap map;

private:
    void loadTextures();
    std::vector<sf::Texture *> textures;
};

#endif // PLANET_SCREEN_H
