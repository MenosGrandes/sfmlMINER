#ifndef TILE_H
#define TILE_H
#include <SFML/System/Vector2.hpp>

class Tile
{
public:
    Tile(sf::Vector2i pos);
    virtual ~Tile();
protected:
private:
    sf::Vector2i _pos;
};

#endif // TILE_H
