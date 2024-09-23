#include "map.h"
#include "worldObj.h"
#include <iostream>

void Map::switchMapLevel(int i)
{

    mapLevel = mapLevel - i;

    int min = 0;
    int max = 100000;

    if (mapLevel < min || mapLevel > max)
    {
        mapLevel = mapLevel + i;
    }

    std::cout << "map level: " << mapLevel << std::endl;
}

void Map::draw(sf::RenderWindow &window)
{

    for (WorldObj &obj : worldObjs)
    {
        window.draw(obj.sprite);
    }
}

void Map::save(std::string src)
{
}

void Map::load(std::string src)
{
}
