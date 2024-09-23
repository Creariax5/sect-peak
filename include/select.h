#ifndef SELECT_H
#define SELECT_H
#include <SFML/Graphics.hpp>
#include "spaceScreen.h"
#include "planetScreen.h"
#include "player.h"
#include "worldObj.h"

class Select
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void selectAnObj(WorldObj &obj);
    bool selected = false;
    sf::Sprite selecting;
    WorldObj selectedObj;

private:
    sf::Texture selectTexture;
};

#endif // SELECT_H
