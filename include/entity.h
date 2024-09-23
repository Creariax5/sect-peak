#ifndef LIVING_ENTITY_H
#define LIVING_ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "worldObj.h"

class Select;

class Entity : public WorldObj
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    int walk(int direction, std::vector<WorldObj> *worldObjs, Select *select);
    int walkTo(float x, float y, std::vector<WorldObj> *worldObjs, Select *select);
    int interact(std::vector<WorldObj> *worldObjs, Select *select, CurrentScreen *currentScreen);
    int goTo(std::vector<WorldObj> *worldObjs, Select *select);

    int state = 0;
    float health;
    float maxHealth;
    float qi;
    float maxQi;
};

#endif // LIVING_ENTITY_H
