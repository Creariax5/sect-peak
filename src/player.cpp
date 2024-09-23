#include "player.h"
#include <iostream>
#include <string>
#include <random>
#include "var.h"
#include <cmath>

void Player::init(sf::RenderWindow &window)
{
    if (!texture.loadFromFile("./assets/textures/set/1.png"))
    {
        std::cout << "could not load texture" << std::endl;
        return;
    }

    sprite.setTexture(texture);
    screenSpeed = 4;
    size = 100;
    screenSize = size;

    center(window);

    health = 30;
    maxHealth = 50;
    qi = 200;
    maxQi = 500;
}

void Player::center(sf::RenderWindow &window)
{
    sf::Vector2u textureSize = texture.getSize();

    float scale = screenSize / textureSize.x;
    sprite.setScale(scale, scale);

    textureSize = texture.getSize();

    sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - scale * textureSize.x / 2, window.getSize().y / 2 - scale * textureSize.x / 2));
}
