#include "worldObj.h"
#include "currentScreen.h"
#include <iostream>
#include <string>
#include <random>

void WorldObj::init(std::string myType, std::vector<sf::Texture *> textures, sf::RenderWindow &window)
{
    type = myType;
    if (type == "planete")
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range of the random numbers
        std::uniform_int_distribution<> distr(0, textures.size() - 1);

        int randomIndex = distr(gen);
        if (randomIndex < 0 || randomIndex >= textures.size())
        {
            std::cerr << "Random index out of bounds: " << randomIndex << std::endl;
            return;
        }

        sf::Texture *texture = textures[randomIndex];
        // Create a sprite
        sprite.setTexture(*texture);

        std::uniform_int_distribution<> rndS(0, 20);
        int myNum[21] = {40, 90, 110, 150, 180, 200, 260, 320, 390, 900, 40, 90, 110, 150, 180, 200, 260, 320, 390, 900, 1830};

        size = myNum[rndS(gen)] * 1.5f;
        screenSize = size;
        // Define the range of the random numbers
        std::uniform_int_distribution<> rndH(-500000, 500000);
        std::uniform_int_distribution<> rndW(-500000, 500000);
        posX = rndH(gen);
        posY = rndW(gen);
        screenPosX = posX;
        screenPosY = posY;
        sprite.setPosition(sf::Vector2f(screenPosY, screenPosX));

        textureSize = texture->getSize();

        // Calculate the scaling factors
        float scale = screenSize / textureSize.x;

        // Set the scale of the sprite
        sprite.setScale(scale, scale);
    }
    else if (type == "tree")
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range of the random numbers
        std::uniform_int_distribution<> distr(0, textures.size() - 1);

        int randomIndex = distr(gen);
        if (randomIndex < 0 || randomIndex >= textures.size())
        {
            std::cerr << "Random index out of bounds: " << randomIndex << std::endl;
            return;
        }

        sf::Texture *texture = textures[randomIndex];
        // Create a sprite
        sprite.setTexture(*texture);

        size = 100.0f;
        screenSize = size;
        // Define the range of the random numbers
        std::uniform_int_distribution<> rndH(-20000, 20000);
        std::uniform_int_distribution<> rndW(-20000, 20000);
        posX = rndH(gen);
        posY = rndW(gen);
        screenPosX = posX;
        screenPosY = posY;
        sprite.setPosition(sf::Vector2f(screenPosY, screenPosX));

        textureSize = texture->getSize();

        // Calculate the scaling factors
        float scale = screenSize / textureSize.x;

        // Set the scale of the sprite
        sprite.setScale(scale, scale);
    }
    else
    {
        std::cout << "Unknown type: " << type << std::endl;
    }
}

void WorldObj::resize()
{
    float scale = screenSize / textureSize.x;

    sprite.setScale(scale, scale);
}

void WorldObj::interact(CurrentScreen *currentScreen)
{
    if (type == "planete")
    {
        currentScreen->setScreen("planet");
        std::cout << type << std::endl;
    }
    else if (type == "tree")
    {
        /* code */
    }

    std::cout << "Entering ..." << std::endl;
}

void WorldObj::zoomIn(sf::RenderWindow &window)
{
    screenSize = screenSize * 2;
    resize();

    screenPosX = screenPosX * 2 - window.getSize().x / 2;
    screenPosY = screenPosY * 2 - window.getSize().y / 2;
    sprite.setPosition(sf::Vector2f(screenPosX, screenPosY));
}

void WorldObj::zoomOut(sf::RenderWindow &window)
{
    screenSize = screenSize / 2;
    resize();

    screenPosX = screenPosX / 2 + window.getSize().x / 4;
    screenPosY = screenPosY / 2 + window.getSize().y / 4;
    sprite.setPosition(sf::Vector2f(screenPosX, screenPosY));
}
