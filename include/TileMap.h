#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Graphics.hpp>
#include "Map.h"
class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset,Map* map)
    {

        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(map->getSize().x * map->getSize().y * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < map->getSize().x; ++i)
            for (unsigned int j = 0; j < map->getSize().y; ++j)
            {
                // get the current tile number
                int tileNumber=map->getNode(sf::Vector2i(i,j))->getType();

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / 32);
                int tv = tileNumber / (m_tileset.getSize().x / 32);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * map->getSize().x) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * 32, j * 32);
                quad[1].position = sf::Vector2f((i + 1) * 32, j * 32);
                quad[2].position = sf::Vector2f((i + 1) * 32, (j + 1) * 32);
                quad[3].position = sf::Vector2f(i * 32, (j + 1) * 32);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * 32, tv * 32);
                quad[1].texCoords = sf::Vector2f((tu + 1) * 32, tv * 32);
                quad[2].texCoords = sf::Vector2f((tu + 1) * 32, (tv + 1) * 32);
                quad[3].texCoords = sf::Vector2f(tu * 32, (tv + 1) * 32);
            }

        return true;
    }
    void changeToGround(sf::Vector2i pos)
    {


                      // get the current tile number
                int tileNumber=GROUND;

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / 32);
                int tv = tileNumber / (m_tileset.getSize().x / 32);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(pos.x + pos.y * 50) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(pos.x * 32, pos.y * 32);
                quad[1].position = sf::Vector2f((pos.x + 1) * 32, pos.y * 32);
                quad[2].position = sf::Vector2f((pos.x + 1) * 32, (pos.y + 1) * 32);
                quad[3].position = sf::Vector2f(pos.x * 32, (pos.y + 1) * 32);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * 32, tv * 32);
                quad[1].texCoords = sf::Vector2f((tu + 1) * 32, tv * 32);
                quad[2].texCoords = sf::Vector2f((tu + 1) * 32, (tv + 1) * 32);
                quad[3].texCoords = sf::Vector2f(tu * 32, (tv + 1) * 32);

    }
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

#endif // TILEMAP_H
