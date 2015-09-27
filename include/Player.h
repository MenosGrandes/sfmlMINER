#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"
class Player
{
public:
    Player()
    {
        x = 0;
        y = 0;

        // in this case, every loop, it will walk 2 pixels.
        //if u put 50 as movespeed, it will walk 1 pixel each loop
        movespeed = 0.5f;

        for(int i = 0; i < 4; ++i) //initialize the all move booleans to false
            move[i] = false;

        walking = false;
        myrect.setSize(sf::Vector2f(32,32)); //size 50 by 50, same as every tile
    }


    float x;
    float y;
    float movespeed; //sets the movespeed

    enum MOVE {UP,DOWN,LEFT,RIGHT}; //enums instead of remember numbers
    bool move[4]; //deciding if u move up/down/left/right
    bool walking;
    int nextspot; //the next tilespot of the map

    sf::RectangleShape myrect;


void keymove()
{
    /*keymove() and moving() functions are working together*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(walking == false)
        {
            /*if you click up, the the nextspot will of course be 50
            pixels above yourself, so thats why nextspot = y - tilsize*/
            nextspot = y - 32;
            /*this is gonna make sure you cant have move[UP] and move[LEFT]
            true on the same time so u wont walk 45 degrees*/
            move[UP] = true;
            walking = true;

        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(walking == false)
        {
            nextspot = y + 32;
            move[DOWN] = true;
            walking = true;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(walking == false)
        {
            nextspot = x - 32;
            move[LEFT] = true;
            walking = true;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(walking == false)
        {
            nextspot = x + 32;
            move[RIGHT] = true;
            walking = true;
        }
    }


}
void update(TileMap *map,Map*m)
{
        keymove();
        moving();
        myrect.setPosition(x,y);
        int tileNumber=m->getNode(sf::Vector2i(x/32,y/32))->getType();
        map->changeToGround(sf::Vector2i(x/32,y/32));


}
void moving()
{
    if(walking == true)
    {
        if(move[UP] == true)
        {
            y -= movespeed;

            /* i do <= and not just == because maybe your movespeed has a
            decimalpoint and then it wont become the same number as nextspot*/
            if(y <= nextspot)
            {
                y = nextspot;
                walking = false;
                move[UP] = false;
            }
        }

        if(move[DOWN] == true)
        {
            y += movespeed;
            if(y >= nextspot)
            {
                y = nextspot;
                walking = false;
                move[DOWN] = false;
            }
        }
        if(move[LEFT] == true)
        {
            x -= movespeed;
            if(x <= nextspot)
            {
                x = nextspot;
                walking = false;
                move[LEFT] = false;
            }
        }
        if(move[RIGHT] == true)
        {
            x += movespeed;
            if(x >= nextspot)
            {
                x = nextspot;
                walking = false;
                move[RIGHT] = false;
            }
        }
    }
}

};

#endif // PLAYER_H
