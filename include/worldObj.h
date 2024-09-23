#ifndef WORLD_OBJ_H
#define WORLD_OBJ_H

#include <SFML/Graphics.hpp>
#include <string>

class CurrentScreen;

class WorldObj
{
public:
    sf::Sprite sprite;
    float size = 1;
    float screenSize = 1;
    int posX = 0;
    int posY = 0;
    float screenPosX = 0;
    float screenPosY = 0;
    float screenSpeed;
    sf::Vector2u textureSize;
    std::string type;

    void init(std::string myType, std::vector<sf::Texture *> textures, sf::RenderWindow &window);

    void interact(CurrentScreen *currentScreen);

    void zoomIn(sf::RenderWindow &window);
    void zoomOut(sf::RenderWindow &window);

    sf::Texture texture;
    void resize();

private:
};

#endif // WORLD_OBJ_H
