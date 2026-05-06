#include "Queue.h"
#include <iostream>
using namespace std;

// Constructor
Queue::Queue(int size) 
{
    if (size <= 0) size = 100;
    capacity = size;
    data = new Position[capacity]; // Create the actual storage array
    frontIndex = 0;
    backIndex = -1;
    currentSize = 0;
}

// Destructor
Queue::~Queue() 
{
    delete[] data; // Free the memory we allocated for the array
}

// Function (makes more space when queue gets full)
void Queue::resize() 
{
    int newCapacity = capacity * 2; // Double our space
    Position* newData = new Position[newCapacity]; // Create bigger array
    
    // Copy all existing elements to the new array
    for (int i = 0; i < currentSize; i++) 
    {
        newData[i] = data[(frontIndex + i) % capacity];
    }
    
    delete[] data;
    data = newData;
    frontIndex = 0;
    backIndex = currentSize - 1;
    capacity = newCapacity;
}

// Add an element to the back of the queue
void Queue::enqueue(Position pos_in) 
{
    if (isFull()) 
    {
        resize();
    }
    backIndex = (backIndex + 1) % capacity;
    data[backIndex] = pos_in;
    currentSize++;
}

// Remove and return element from front of queue
Position Queue::dequeue() 
{
    if (isEmpty()) 
    {
        cout << "Error: Queue is empty!" << endl;
        return Position(-1, -1, "ERROR");
    }
    Position value = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    currentSize--;
    return value;
}

// Check if queue has no elements
bool Queue::isEmpty() 
{
    return currentSize == 0;
}

// Check if queue is completely full
bool Queue::isFull() 
{
    return currentSize == capacity;
}