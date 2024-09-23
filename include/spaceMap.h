#ifndef SPACE_MAP_H
#define SPACE_MAP_H

#include <SFML/Graphics.hpp>
#include "map.h"

class SpaceMap : public Map
{
public:
    void create(int seed, std::vector<sf::Texture *> textures, sf::RenderWindow &window);
};

#endif // SPACE_MAP_H
