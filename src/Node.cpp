#include "../include/Node.h"
#include <iostream>
Node::Node(int posX,int posY,NODETYPE type):positionX(posX),positionY(posY),type(type)
{}
Node::Node()
{}
Node::~Node()
{}

int Node::getPositionX()
{
    return positionX;
}
int Node::getPositionY()
{
    return positionY;
}
void Node::setType(NODETYPE type)
{
    this->type=type;
}
NODETYPE Node::getType()
{
    return type;
}
void Node::setPositionX(int positionX)
{
    this->positionX=positionX;
}

void Node::setPositionY(int positionY)
{
    this->positionY=positionY;

}
///OVERLOADED OPERATOR
bool Node::operator ==( const Node & v )
{
    if(( this->positionX == v.positionX ) &&( this->positionY == v.positionY ) )
        return true;
    else
        return false;

}
bool Node::operator !=( const Node & v )
{
    if(( this->positionX == v.positionX ) &&( this->positionY == v.positionY ) )
        return false;
    else
        return true;

}


