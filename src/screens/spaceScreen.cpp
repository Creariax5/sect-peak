#include "spaceScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "select.h"

void SpaceScreen::init(sf::RenderWindow &window)
{
    loadTextures();

    map.create(100, textures, window);
}

void SpaceScreen::render(sf::RenderWindow &window, Player &player, Select &select)
{
    map.draw(window);
}

void SpaceScreen::loadTextures()
{
    int nbTextures = 4;
    textures.reserve(nbTextures);

    for (int i = 1; i < nbTextures + 1; i++)
    {
        sf::Texture *texture = new sf::Texture;
        if (!texture->loadFromFile("./assets/textures/planete/" + std::to_string(i) + ".png"))
        {
            std::cerr << "Could not load texture " << i << std::endl;
            return;
        }
        texture->setSmooth(true);
        textures.push_back(texture);
    }

    if (textures.empty())
    {
        std::cerr << "No textures were loaded successfully." << std::endl;
        return;
    }
}

void SpaceScreen::handleEvent(sf::RenderWindow &window, sf::Event event, Player &player, Select &select)
{
    switch (event.type)
    {
    case sf::Event::MouseWheelMoved:
        select.selected = false;
        if (event.mouseWheel.delta == -1 && map.mapLevel >= 0)
        {
            player.screenSize = player.screenSize / 2;
            player.center(window);

            for (WorldObj &obj : map.worldObjs)
            {
                obj.zoomOut(window);
            }
        }
        else if (map.mapLevel > 0)
        {
            player.screenSize = player.screenSize * 2;
            player.center(window);

            for (WorldObj &obj : map.worldObjs)
            {
                obj.zoomIn(window);
            }
        }

        map.switchMapLevel(event.mouseWheel.delta);

        break;

    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            select.selected = false;
            for (WorldObj &obj : map.worldObjs)
            {
                int x1 = obj.screenPosX;
                int y1 = obj.screenPosY;
                int x2 = x1 + obj.screenSize;
                int y2 = y1 + obj.screenSize;
                if (event.mouseWheel.x > x1 && event.mouseWheel.x < x2 && event.mouseWheel.y > y1 && event.mouseWheel.y < y2)
                {
                    select.selectAnObj(obj);
                }
            }
        }

    // we don't process other types of events
    default:
        break;
    }
}
