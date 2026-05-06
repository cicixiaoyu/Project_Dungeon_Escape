#ifndef ROOM_H
#define ROOM_H

struct Room {
    int rows, cols;
    char** grid;
    int startX, startY;
    
    Room() : rows(0), cols(0), grid(nullptr), startX(-1), startY(-1) {}
    ~Room();
};

void readRooms(Room* &rooms, int &numRooms);

#endif
