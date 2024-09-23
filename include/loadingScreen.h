#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H
#include <SFML/Graphics.hpp>

class LoadingScreen
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // LOADING_SCREEN_H
