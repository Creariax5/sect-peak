if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
{
    if (selected)
    {
        screen = "planet";
        selectedObj.interact();
        selected = false;
    }
}