#ifndef MAP_H
#define MAP_H
#include <random>
#include "Node.h"
#include <deque>
class Map
{
public:
    Map(sf::Vector2i size);
    virtual ~Map();
    void showMap();
    Node * getNode(int x,int y);
    void setNode(Node * a);

    ///GETTERS
    sf::Vector2i getSize();
    std::deque<Node *> getWorld();
    Node * getNode(sf::Vector2i pos);
    ///SETTERS
    void setSize(sf::Vector2i _size);
    void setWorld(std::deque<Node *> world);


protected:
private:
    sf::Vector2i size;
    std::deque<Node *>world;


};

#endif // MAP_H
