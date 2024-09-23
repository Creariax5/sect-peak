#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <string>
#include "hudButton.h"
#include "player.h"

class HUD
{
public:
    void init(sf::RenderWindow &window);
    void render(sf::RenderWindow &window, Player player);
    void handleEvent(sf::RenderWindow &window, sf::Event event, Player &player);

private:
    std::vector<HudButton> hudButtons;
};

#endif // HUD_H
