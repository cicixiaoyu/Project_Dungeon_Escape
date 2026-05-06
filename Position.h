#ifndef POSITION_H
#define POSITION_H

#include <string>
using namespace std;

class Position 
{
public:
    int x, y; // Coordinates
    string path; // Movement path
    Position(int startX = 0, int startY = 0, string movePath = "");
};

#endif
