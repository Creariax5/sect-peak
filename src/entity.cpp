#include "entity.h"
#include <iostream>
#include <string>
#include <random>
#include "var.h"
#include <cmath>
#include "select.h"

void Entity::init(sf::RenderWindow &window)
{
    if (!texture.loadFromFile("./assets/textures/set/entity/1.png"))
    {
        std::cout << "could not load texture" << std::endl;
        return;
    }

    sprite.setTexture(texture);
    screenSpeed = 4;
    size = 100;
    screenSize = size;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> rndH(-20000, 20000);
    std::uniform_int_distribution<> rndW(-20000, 20000);
    posX = rndH(gen);
    posY = rndW(gen);
    screenPosX = posX;
    screenPosY = posY;
    sprite.setPosition(sf::Vector2f(screenPosY, screenPosX));

    textureSize = texture.getSize();

    // Calculate the scaling factors
    float scale = screenSize / textureSize.x;

    // Set the scale of the sprite
    sprite.setScale(scale, scale);

    health = 30;
    maxHealth = 50;
    qi = 200;
    maxQi = 500;
}

void Entity::render(sf::RenderWindow &window)
{
    window.draw(sprite);

    if (state == 1)
    {
        if (health < maxHealth)
        {
            health += 0.005f;
        }
    }
    else if (state == 2)
    {
        if (qi < maxQi)
        {
            qi += 0.01f;
        }
    }
}

int Entity::walk(int direction, std::vector<WorldObj> *worldObjs, Select *select)
{
    if (state == 1 || state == 2)
    {
        state = 0;
    }
    if (direction == Var::Direction::Left)
    {
        for (WorldObj &obj : *worldObjs)
        {
            obj.screenPosX += screenSpeed;
            obj.sprite.setPosition(obj.screenPosX, obj.screenPosY);
        }
        if (select->selected)
        {
            select->selecting.setPosition(select->selecting.getPosition().x + screenSpeed, select->selecting.getPosition().y);
        }
    }
    if (direction == Var::Direction::Right)
    {
        for (WorldObj &obj : *worldObjs)
        {
            obj.screenPosX -= screenSpeed;
            obj.sprite.setPosition(obj.screenPosX, obj.screenPosY);
        }
        if (select->selected)
        {
            select->selecting.setPosition(select->selecting.getPosition().x - screenSpeed, select->selecting.getPosition().y);
        }
    }
    if (direction == Var::Direction::Up)
    {
        for (WorldObj &obj : *worldObjs)
        {
            obj.screenPosY += screenSpeed;
            obj.sprite.setPosition(obj.screenPosX, obj.screenPosY);
        }
        if (select->selected)
        {
            select->selecting.setPosition(select->selecting.getPosition().x, select->selecting.getPosition().y + screenSpeed);
        }
    }
    if (direction == Var::Direction::Down)
    {
        for (WorldObj &obj : *worldObjs)
        {
            obj.screenPosY -= screenSpeed;
            obj.sprite.setPosition(obj.screenPosX, obj.screenPosY);
        }
        if (select->selected)
        {
            select->selecting.setPosition(select->selecting.getPosition().x, select->selecting.getPosition().y - screenSpeed);
        }
    }
    return 0;
}

int Entity::walkTo(float x, float y, std::vector<WorldObj> *worldObjs, Select *select)
{
    if (state == 1 || state == 2)
    {
        state = 0;
    }
    x = -x;
    y = -y;

    for (WorldObj &obj : *worldObjs)
    {
        obj.screenPosX += x * screenSpeed;
        obj.screenPosY += y * screenSpeed;
        obj.sprite.setPosition(obj.screenPosX, obj.screenPosY);
    }
    if (select->selected)
    {
        select->selecting.setPosition(select->selecting.getPosition().x + x * screenSpeed, select->selecting.getPosition().y + y * screenSpeed);
    }

    return 0;
}

int Entity::goTo(std::vector<WorldObj> *worldObjs, Select *select)
{
    if (1 == 1)
    {
        float x = (select->selecting.getPosition().x + select->selectedObj.size / 2) - (sprite.getPosition().x);
        float y = (select->selecting.getPosition().y + select->selectedObj.size / 2) - (sprite.getPosition().y);
        Var::log(std::to_string(select->selectedObj.size));

        // Calculate the norm of the vector (x, y)
        float norm = std::sqrt(x * x + y * y);
        if (norm <= select->selectedObj.size / 2)
        {
            return 1;
        }

        // Avoid division by zero by checking if norm is not zero
        if (norm != 0)
        {
            // Normalize the vector
            x /= norm;
            y /= norm;
        }

        walkTo(x, y, worldObjs, select);
    }

    return 0;
}

int Entity::interact(std::vector<WorldObj> *worldObjs, Select *select, CurrentScreen *currentScreen)
{
    if (goTo(worldObjs, select) == 1)
    {
        if (select->selected)
        {
            select->selectedObj.interact(currentScreen);
            select->selected = false;
        }
    }

    return 0;
}