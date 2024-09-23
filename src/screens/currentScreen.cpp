#include "currentScreen.h"
#include <iostream>

void CurrentScreen::init(sf::RenderWindow &window)
{
    spaceScreen.init(window);
    planetScreen.init(window);
}

void CurrentScreen::render(sf::RenderWindow &window, Player &player, Select &select)
{
    if (screen == "space")
    {
        spaceScreen.render(window, player, select);
    }
    else if (screen == "planet")
    {
        planetScreen.render(window, player, select);
    }
}

void CurrentScreen::handleEvent(sf::RenderWindow &window, sf::Event event, Player &player, Select &select)
{
    if (screen == "space")
    {
        spaceScreen.handleEvent(window, event, player, select);
    }
    else if (screen == "planet")
    {
        planetScreen.handleEvent(window, event, player, select);
    }
}

void CurrentScreen::handleSreenSwitch()
{
    if (spaceScreen.screen == planetScreen.screen)
    {
        screen = spaceScreen.screen;
        spaceScreen.screen = "space";
        planetScreen.screen = "planet";
        changeScreen = true;
    }
}

void CurrentScreen::setScreen(std::string name)
{
    screen = name;
    changeScreen = true;
}

bool CurrentScreen::isNewSreen()
{
    if (changeScreen)
    {
        changeScreen = false;
        return true;
    }
    return false;
}

std::vector<WorldObj> *CurrentScreen::getWorldObjs()
{
    if (screen == "space")
    {
        return &spaceScreen.map.worldObjs;
    }
    else
    {
        return &planetScreen.map.worldObjs;
    }
}
