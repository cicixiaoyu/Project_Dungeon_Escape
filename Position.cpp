#include "Position.h"

Position::Position(int startX, int startY, string movePath)
{
    x = startX;
    y = startY;
    path = movePath; // Store the sequence of moves taken to reach this position
}