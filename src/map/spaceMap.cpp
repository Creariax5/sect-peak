#include "spaceMap.h"

void SpaceMap::create(int seed, std::vector<sf::Texture *> textures, sf::RenderWindow &window)
{
    mapLevel = 10;
    for (int i = 0; i < 10000; i++)
    {
        WorldObj worldObj;
        worldObj.init("planete", textures, window);
        worldObjs.push_back(worldObj);
    }
}