#include "hudButton.h"
#include <iostream>

void HudButton::init(sf::RenderWindow &window, int givenID)
{
    id = givenID;
    x = window.getSize().x - id * (size + layout);
    y = window.getSize().y - size - layout;
}

void HudButton::render(sf::RenderWindow &window)
{
    sf::RectangleShape button(sf::Vector2f(size, size));
    button.setPosition(x, y);
    button.setFillColor(sf::Color(50, 50, 50));

    window.draw(button);
}

bool HudButton::isSelected(int mouseX, int mouseY)
{
    if (mouseX > x && mouseX < x + size && mouseY > y && mouseY < y + size)
    {
        std::cout << id << std::endl;
        return true;
    }
    return false;
}
