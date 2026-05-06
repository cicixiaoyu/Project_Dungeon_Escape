#include "Room.h"
#include <iostream>
using namespace std;

// Destructor
Room::~Room() 
{
    if (grid) 
    {
        for (int i = 0; i < rows; i++) 
        {
            delete[] grid[i];
        }
        delete[] grid;
    }
}

// Reads all room data from standard input and creates Room objects
void readRooms(Room* &rooms, int &numRooms) 
{
    cin >> numRooms;
    rooms = new Room[numRooms];
    
    // Process each room one by one
    for (int i = 0; i < numRooms; i++) 
    {
        int rows, cols;
        cin >> rows >> cols;
        rooms[i].rows = rows;
        rooms[i].cols = cols;
        rooms[i].grid = new char*[rows];
        
        for (int r = 0; r < rows; r++) 
        {
            rooms[i].grid[r] = new char[cols + 1]; // +1 for null terminator
        }
        
        for (int r = 0; r < rows; r++) 
        {
            string line;
            cin >> line;
            for (int c = 0; c < cols; c++) 
            {
                rooms[i].grid[r][c] = line[c];
                if (line[c] == 'I') 
                {
                    rooms[i].startX = r;
                    rooms[i].startY = c;
                }
            }
        }
    }
}