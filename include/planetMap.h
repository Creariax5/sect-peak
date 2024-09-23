#ifndef PLANET_MAP_H
#define PLANET_MAP_H

#include <SFML/Graphics.hpp>
#include "map.h"

class PlanetMap : public Map
{
public:
    void create(int seed, std::vector<sf::Texture *> textures, sf::RenderWindow &window);
};

#endif // PLANET_MAP_H
