#include "planetMap.h"

void PlanetMap::create(int seed, std::vector<sf::Texture *> textures, sf::RenderWindow &window)
{
    mapLevel = 0;
    for (int i = 0; i < 10000; i++)
    {
        WorldObj worldObj;
        worldObj.init("tree", textures, window);
        worldObjs.push_back(worldObj);
    }

    for (int i = 0; i < 1000; i++)
    {

        Entity entity;
        entity.init(window);
        entities.push_back(entity);
    }
}