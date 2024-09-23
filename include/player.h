#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"

class Player : public Entity
{
public:
    void init(sf::RenderWindow &window);
    void center(sf::RenderWindow &window);

private:
};

#endif // PLAYER_H
