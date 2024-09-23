#include "loadingScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void LoadingScreen::init(sf::RenderWindow &window)
{
    if (!texture.loadFromFile("./assets/textures/loading.png"))
    {
        std::cout << "could not load texture" << std::endl;
        return;
    }

    // Create a sprite
    sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - textureSize.x / 2, window.getSize().y / 2 - textureSize.y / 2));
}

void LoadingScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color(180, 50, 50, 255));
    window.draw(sprite);
    window.display();
}
