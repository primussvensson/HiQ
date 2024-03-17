#include "car.h"

int Car::get_position(int *pos)
{
    *(pos) = xPos;
    *(pos + 1) = yPos;
    return 1;
}

int Car::get_heading(char *head)
{
     
    if(heading[0] == 0)
    {
        *(head) = (heading[1]) ? 'N' : 'S';
    }
    else
    {
        *(head) = (heading[0]) ? 'E' : 'W';
    }
    return 1;
}

Car::Car(int x, int y, char head, Map *input_map)
{
    xPos = x;
    yPos = y;
    map = input_map;
    switch (head)
    {
    case 'n':
        heading[0] = 0;
        heading[1] = 1;
        break;
    case 's':
        heading[0] = 0;
        heading[1] = -1;
        break;
    case 'w':
        heading[0] = -1;
        heading[1] = 0;
        break;
    case 'e':
        heading[0] = 1;
        heading[1] = 0;
        break;
    }
}

int Car::rotate(float angle)
{
    float x_temp = heading[0];
    float y_temp = heading[1];
    heading[0] = x_temp * cos(angle) - y_temp * sin(angle);
    heading[1] = x_temp * sin(angle) + y_temp * cos(angle);
    return 1;
}

int Car::move(int delta)
{
    xPos += delta * heading[0];
    yPos += delta * heading[1];
    return map->verify_coordinates(xPos, yPos);
}


int Car::execute_command(char input)
{
    if (input == 'l' || input == 'r')
    {
        return (input == 'l') ? rotate(ANGLE_LEFT) : rotate(ANGLE_RIGHT);
    }
    else
    {   
        return (input == 'f') ? move(MOVE_FORWARD) : move(MOVE_BACKWARD);
    }  
}

