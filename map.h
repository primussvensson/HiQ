#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;
class Map
{
private:
    int xBounds;
    int yBounds;
public:
    Map(int xMax, int yMax);
    int verify_coordinates(int xPos, int yPos);
};
#endif