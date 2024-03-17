#include <cmath>
#include "map.h"
#define ANGLE_LEFT M_PI/2
#define ANGLE_RIGHT -M_PI/2
#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1
class Car
{
private:
    int xPos;
    int yPos;
    int heading [2];
    Map *map;
    int rotate(float angle);
    int move(int delta);
public:
    Car(int x, int y, char head, Map *input_map);
    int get_position(int *pos);
    int get_heading(char *head);
    int execute_command(char input);
};