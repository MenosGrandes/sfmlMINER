#include "Map.h"

template< typename T >
struct array_deleter
{
    void operator ()( T const * p)
    {
        delete[] p;
    }
};
Map::Map(sf::Vector2i size)
{
    this->size=size;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 6);


    for (int i=0; i<this->size.x; i++)
    {

        for (int j=0; j<this->size.y; j++)
        {
            this->world.push_back( new Node(i,j,static_cast<NODETYPE>(dist(mt)))) ;

        }

    }
    std::cout<<"MAP DONE. SIZE:  "<<world.size()<<"\n";



}
Map::~Map()
{
    for (std::deque<Node*>::const_iterator it = world.begin(); it != world.end(); ++it)
    {
        delete *it;
    }
    world.clear();
    std::cout<<"swiat zniszczony!\n";
    std::cout<<world.size();
}



void Map::setSize(sf::Vector2i _size)
{
    this->size=_size;
}
sf::Vector2i Map::getSize()
{
    return this->size;
}
Node * Map::getNode(sf::Vector2i pos)
{

    return world.at(this->size.x * pos.x + pos.y);
}





