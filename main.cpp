#include <iostream>
#include <string>
#include "Room.h"
#include "Stack.h"
#include "Queue.h"
#include "Position.h"

using namespace std;

bool isValidMove(Room& room, int x, int y, bool** visited) 
{
    if (x < 0 || x >= room.rows) return false;
    if (y < 0 || y >= room.cols) return false;
    if (room.grid[x][y] == '@') return false;
    if (visited[x][y]) return false;
    return true;
}

string findPath(Room& room, bool useStack, bool isLastRoom) 
{
    int rows = room.rows;
    int cols = room.cols;
    
    bool** visited = new bool*[rows];
    for (int i = 0; i < rows; i++) {
        visited[i] = new bool[cols];
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }
    
    string result = "";
    int startX = room.startX;
    int startY = room.startY;
    
    // Directions in NSEW order
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char directions[] = {'N', 'S', 'E', 'W'};
    
    if (useStack) {
        Stack stack(rows * cols);
        stack.push(Position(startX, startY, ""));
        visited[startX][startY] = true;
        
        while (!stack.isEmpty()) 
        {
            Position current = stack.pop();
            int x = current.x;
            int y = current.y;
            string path = current.path;
            
            // Check if we reached target
            if (isLastRoom) 
            {
                if (room.grid[x][y] == 'T') 
                {
                    result = path;
                    break;
                }
            } 
            else if (!isLastRoom && room.grid[x][y] == 'O') 
            {
                // Take one additional step to exit 
                for (int i = 0; i < 4; i++) 
                {
                    int exitX = x + dx[i];
                    int exitY = y + dy[i];
                    if (exitX < 0 || exitX >= room.rows || exitY < 0 || exitY >= room.cols) 
                    {
                        result = path + directions[i];
                        break; 
                    }
                }
                if (!result.empty()) break;
            }
            
            // Explore neighbors in NSEW order
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (isValidMove(room, newX, newY, visited)) {
                    visited[newX][newY] = true;
                    stack.push(Position(newX, newY, path + directions[i]));
                }
            }
        }
    } 
    else 
    {
        Queue queue(rows * cols);
        queue.enqueue(Position(startX, startY, ""));
        visited[startX][startY] = true;
        
        while (!queue.isEmpty()) 
        {
            Position current = queue.dequeue();
            int x = current.x;
            int y = current.y;
            string path = current.path;
            
            // Check if we reached target
            if (isLastRoom) 
            {
                if (room.grid[x][y] == 'T') 
                {
                    result = path;
                    break;
                }
            } 
            else 
            {
                if (room.grid[x][y] == 'O') 
                {
                    // Take one additional step to exit
                    for (int i = 0; i < 4; i++)
                    {
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        if (newX < 0 || newX >= room.rows || newY < 0 || newY >= room.cols)
                        {
                            result = path + directions[i];
                            break;
                        }
                    }
                    if (!result.empty()) break;
                }
            }
            
            // Explore neighbors in NSEW order
            for (int i = 0; i < 4; i++) 
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (isValidMove(room, newX, newY, visited)) 
                {
                    visited[newX][newY] = true;
                    queue.enqueue(Position(newX, newY, path + directions[i]));
                }
            }
        }
    }
    
    // Clean memory
    for (int i = 0; i < rows; i++) 
    {
        delete[] visited[i];
    }
    delete[] visited;
    
    return result;
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " -Stack or " << argv[0] << " -Queue" << endl;
        return 1;
    }
    
    string argument = argv[1];
    bool useStack = false;
    
    if (argument == "-Stack") 
    {
        useStack = true;
    } else if (argument == "-Queue") 
    {
        useStack = false;
    } 
    else 
    {
        cerr << "Error: Use -Stack or -Queue" << endl;
        return 1;
    }
    
    Room* rooms = nullptr;
    int numRooms = 0;
    readRooms(rooms, numRooms);
    
    bool escapeFailed = false;
    
    string* paths = new string[numRooms]; // Stocker tous les chemins

    for (int i = 0; i < numRooms; i++) 
    {
        bool isLastRoom = (i == numRooms - 1);
        string path = findPath(rooms[i], useStack, isLastRoom);
    
        if (path.empty()) 
        {
            escapeFailed = true;
        }
        paths[i] = path; 
    }

    if (escapeFailed) 
    {
        cout << "Escape failed.\n";  
    }
    else 
    {
        for (int i = 0; i < numRooms; i++) 
        {
            cout << paths[i] << endl;
        }
    }

    delete[] rooms;
    delete[] paths;
    return 0;
}