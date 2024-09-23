#include "planetScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "select.h"

void PlanetScreen::init(sf::RenderWindow &window)
{
    loadTextures();

    map.create(100, textures, window);
}

void PlanetScreen::render(sf::RenderWindow &window, Player &player, Select &select)
{
    window.clear(sf::Color(50, 200, 50, 255));

    map.draw(window);

    if (map.mapLevel == 10)
    {
        screen = "space";
        select.selected = false;
        map.mapLevel = 9;

        player.screenSize = player.screenSize * 2;
        player.center(window);

        for (WorldObj &obj : map.worldObjs)
        {
            obj.zoomIn(window);
        }
    }
}

void PlanetScreen::loadTextures()
{
    int nbTextures = 4;
    textures.reserve(nbTextures);

    for (int i = 1; i < nbTextures + 1; i++)
    {
        sf::Texture *texture = new sf::Texture;
        if (!texture->loadFromFile("./assets/textures/set/tree/" + std::to_string(i) + ".png"))
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

void PlanetScreen::handleEvent(sf::RenderWindow &window, sf::Event event, Player &player, Select &select)
{
    switch (event.type)
    {
    case sf::Event::MouseWheelMoved:
        select.selected = false;
        if (map.mapLevel >= 0)
        {
            if (event.mouseWheel.delta == -1)
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
