#ifndef QUEUE_H
#define QUEUE_H

#include "Position.h"

class Queue 
{
public:
    Queue(int size = 100); // Constructor with default size of 100
    ~Queue(); // Destructor to clean up memory
    
    Queue(const Queue&) = delete; // Disable copy constructor
    Queue& operator=(const Queue&) = delete; // Disable assignment operator
    
    void enqueue(Position pos_in); // Add element to the back
    Position dequeue(); // Remove element from the front
    bool isEmpty(); // Check if queue is empty
    bool isFull(); // Check if queue is full

private:
    void resize(); // Double the size when queue is full
    // Queue data members
    Position* data; // Dynamic array to store queue elements
    int capacity; // Maximum number of elements queue can hold
    int frontIndex; // Index of the front element
    int backIndex; // Index of the back element
    int currentSize; // Current number of elements in queue
};

#endif