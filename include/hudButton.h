#ifndef HUD_BUTTON_H
#define HUD_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class HudButton
{
public:
    void init(sf::RenderWindow &window, int id);
    void render(sf::RenderWindow &window);
    bool isSelected(int mouseX, int mouseY);
    int id;

private:
    int layout = 5;
    int size = 64;
    int x;
    int y;
    bool selected = false;
};

#endif // HUD_BUTTON_H
