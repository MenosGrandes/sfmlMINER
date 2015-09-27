#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "TileMap.h"
#include "Player.h"
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");

Player *p=new Player();
    p->myrect.setFillColor(sf::Color(255,255,0));

    Map* m= new Map(sf::Vector2i(50,250));
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tiles.png",m))
        return -1;
        sf::Clock clock;
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        p->update(&map,m);
        // draw the map
        window.clear();
        window.draw(map);
                window.draw(p->myrect);

        window.display();
    }

    return 0;
}
