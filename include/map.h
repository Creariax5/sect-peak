#ifndef MAP_H
#define MAP_H

#include <string>
#include <SFML/Graphics.hpp>
#include "worldObj.h"
#include "entity.h"

class Map
{
public:
    int mapLevel;
    std::vector<WorldObj> worldObjs;
    std::vector<Entity> entities;
    void switchMapLevel(int i);
    void draw(sf::RenderWindow &window);
    void save(std::string src);
    void load(std::string src);
};

#endif // MAP_H
