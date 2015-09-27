#ifndef NODE_H
#define NODE_H
#include <stdint.h>
#include <vector>
#include <stdint.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits>
#include <iterator>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
enum NODETYPE
{
    ROCK=4,COAL=2,CRYSTAL=26,SILVER=2,GOLD=0,COOPER=3,GROUND=5,
};


class Node
{
public:
    Node(int,int,NODETYPE);
    Node();
    virtual ~Node();

    int getPositionX();
    int getPositionY();
    NODETYPE getType();
    ///Setters

    void setPositionX(int positionX);
    void setPositionY(int positionY);
    void setType(NODETYPE type);
    void showMy();


    ///override operators
    bool operator==(const Node& n);
    bool operator !=(const Node &n);

private:
    int positionX,positionY;
    NODETYPE type;
};

#endif // NODE_H
