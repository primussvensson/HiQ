#include "map.h"
int Map::verify_coordinates(int xPos, int yPos)
{
    return (xPos <= xBounds && yPos <= yBounds) ? 1 : 0;
}
Map::Map(int xMax, int yMax)
{
    xBounds = xMax;
    yBounds = yMax;
}


