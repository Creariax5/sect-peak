#include "hud.h"
#include <iostream>
#include "hudButton.h"
#include "player.h"

void HUD::init(sf::RenderWindow &window)
{
    for (int i = 1; i < 10; i++)
    {
        HudButton hudButton;
        hudButton.init(window, i);
        hudButtons.push_back(hudButton);
    }
}

void HUD::render(sf::RenderWindow &window, Player player)
{
    sf::RectangleShape maxHealthRectangle(sf::Vector2f(300, 20.f));
    maxHealthRectangle.setFillColor(sf::Color(150, 100, 100));

    sf::RectangleShape healthRectangle(sf::Vector2f(player.health / player.maxHealth * 300.0f, 20.f));
    healthRectangle.setFillColor(sf::Color(200, 50, 50));

    window.draw(maxHealthRectangle);
    window.draw(healthRectangle);

    sf::RectangleShape maxQiRectangle(sf::Vector2f(300, 20.f));
    maxQiRectangle.setFillColor(sf::Color(100, 100, 150));
    maxQiRectangle.setPosition(0, 20);

    sf::RectangleShape qiRectangle(sf::Vector2f(player.qi / player.maxQi * 300.0f, 20.f));
    qiRectangle.setFillColor(sf::Color(50, 50, 200));
    qiRectangle.setPosition(0, 20);

    window.draw(maxQiRectangle);
    window.draw(qiRectangle);

    for (HudButton &obj : hudButtons)
    {
        obj.render(window);
    }
}

void HUD::handleEvent(sf::RenderWindow &window, sf::Event event, Player &player)
{
    switch (event.type)
    {

    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
        {

            for (HudButton &obj : hudButtons)
            {
                if (obj.isSelected(event.mouseButton.x, event.mouseButton.y))
                {
                    player.state = obj.id;
                }
            }
        }

    // we don't process other types of events
    default:
        break;
    }
}
