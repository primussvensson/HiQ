#include <iostream>
#include <vector>
#include "map.h"
#include "car.h"
#define ROOM_MAX 500
#define ROOM_MIN 0
#define LOWER_CASE 32
using namespace std;
vector<string> split_string(string input)
{
    string cut = input;
    int first = 0;
    vector<string> output;
    for(int i=0; i<input.length(); i++)
    {
        if (input[i] == ' ')
        {
            output.push_back(input.substr(first, i-first));
            first = i+1;
        }
            
    }
    output.push_back(input.substr(first));
    return output;
    
}
int ask_room(int *map)
{
    int x, y;
    string input;
    cout << "Input the room size: ";
    getline(cin, input);
    vector<string> result = split_string(input);
    if(result.size() != 2)
        return 0;
    x = stoi(result[0]);
    y = stoi(result[1]);

    if (x < ROOM_MIN || y < ROOM_MIN || x > ROOM_MAX || y > ROOM_MAX)
        return 0;

    *(map) = x;
    *(map+1) = y;
    return 1;
}

int check_valid_char(char test, char *valid)
{
    int valid_arr_length = 4;
    for(int i=0; i<valid_arr_length; i++)
    {
        if (test == *(valid + i) || test == *(valid + i) + LOWER_CASE)
            return 1;
    }
    return 0;
}   

int ask_startPos(char *heading, int *startPos, int xMax, int yMax)
{
    int x, y;
    char head;
    char valid [4] = {69, 78, 87, 83};
    string input;

    cout << "Input start position & heading: ";
    getline(cin, input);
    vector<string> result = split_string(input);
    if(result.size() != 3)
        return 0;

    x = stoi(result[0]);
    y = stoi(result[1]);
    const char *conv = result[2].data();
    head = tolower(*(conv));

    if (x < ROOM_MIN || y < ROOM_MIN || x > xMax || y > yMax)
        return 0;
    
    if (!check_valid_char(head, valid))
        return 0;
    
    *(heading) = head;
    *(startPos) = x;
    *(startPos+1) = y;
        
    return 1;
}

int ask_cmd(vector<char> *cmds)
{
    string input;
    cout << "Input actions: ";
    getline(cin, input);
    char valid [4] = {66, 70, 76, 82};
    for (int i=0; i<input.length(); i++)
    {
        if (!check_valid_char(input.substr(i, 1)[0], valid))
            return 0;
        
        (*cmds).push_back(input.substr(i, 1)[0]);
    }
    return 1;
}

int main()
{

    int map [2];
    int startPos [2];
    char heading[1];
    vector<char> cmds;

    if(ask_room(map) && ask_startPos(heading, startPos, map[0], map[1]) && ask_cmd(&cmds))
    {
        Map deMap(map[0], map[1]);
        Car c1(startPos[0], startPos[1], heading[0], &deMap);
        int status;
        for(char ch : cmds)
        {
            status = c1.execute_command(tolower(ch));
            if(!status)
                break;   
        }
        c1.get_position(startPos);
        c1.get_heading(heading);
        
        string result = (status) ? "Simulation finished successfully at position " : "Simulation stopped due to a crash at position ";
        cout << result;
        cout << "(X, Y, H): " << startPos[0] << ", " << startPos[1] << ", " << heading[0] << "\n";
    }
    else
    {
        cout << "Input error: invalid input format \n";
    }
    
    
    return 0;
}