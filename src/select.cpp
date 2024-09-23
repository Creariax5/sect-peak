#include "select.h"
#include <iostream>

void Select::init(sf::RenderWindow &window)
{
    if (!selectTexture.loadFromFile("./assets/textures/smoke-circle.png"))
    {
        std::cout << "could not load texture" << std::endl;
        return;
    }

    selecting.setTexture(selectTexture);
}

void Select::render(sf::RenderWindow &window)
{
    if (selected)
    {
        window.draw(selecting);
    }
}

void Select::selectAnObj(WorldObj &obj)
{
    if (!selected)
    {
        float scale = (obj.screenSize + 80) / selectTexture.getSize().x;
        selecting.setScale(scale, scale);
        selecting.setPosition(obj.screenPosX - 40, obj.screenPosY - 40);
        selectedObj = obj;
        selected = true;
    }
}
