#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "map.h"
#include "worldObj.h"
#include "loadingScreen.h"
#include "currentScreen.h"
#include "hud.h"
#include "select.h"
#include "var.h"

class MyApp
{
public:
    void run()
    {
        initWindow();
        initApp();
        mainLoop();
        cleanup();
    }

private:
    sf::RenderWindow window;
    LoadingScreen loadingScreen;
    HUD hud;
    CurrentScreen currentScreen;
    Player player;
    Select select;

    void initWindow()
    {
        // Create the main window
        window.create(sf::VideoMode(1900, 800), "SFML window");
    }

    void initApp()
    {
        loadingScreen.init(window);
        loadingScreen.render(window);
        hud.init(window);

        player.init(window);
        select.init(window);

        currentScreen.init(window);

        std::vector<WorldObj> *worldObjs = currentScreen.getWorldObjs();
        player.walk(Var::Direction::Down, worldObjs, &select);
    }

    void mainLoop()
    {
        // Main loop
        while (window.isOpen() && !currentScreen.changeScreen)
        {
            handleEvent();

            currentScreen.handleSreenSwitch();

            render();
        }
    }

    void handleEvent()
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            hud.handleEvent(window, event, player);
            currentScreen.handleEvent(window, event, player, select);
        }

        keyAction();
    }

    void keyAction()
    {
        std::vector<WorldObj> *worldObjs = currentScreen.getWorldObjs();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.walk(Var::Direction::Left, worldObjs, &select);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.walk(Var::Direction::Right, worldObjs, &select);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player.walk(Var::Direction::Up, worldObjs, &select);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player.walk(Var::Direction::Down, worldObjs, &select);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            if (select.selected)
            {
                player.interact(worldObjs, &select, &currentScreen);
            }
        }
    }

    void render()
    {
        window.clear(sf::Color(0, 0, 0, 255));

        currentScreen.render(window, player, select);
        player.render(window);
        select.render(window);

        hud.render(window, player);

        window.display();
    }

    void cleanup()
    {
        if (currentScreen.isNewSreen())
        {
            loadingScreen.render(window);
            // currentScreen.init(window);
            mainLoop();
            cleanup();
        }
    }
};

int main()
{
    MyApp app;
    app.run();

    return 0;
}
