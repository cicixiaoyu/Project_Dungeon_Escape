#include "Stack.h"
#include <iostream>
using namespace std;

// Constructor
Stack::Stack(int size) 
{
    capacity = size;
    data = new Position[capacity];
    topIndex = -1;
}

// Destructor
Stack::~Stack() 
{
    delete[] data;
}

void Stack::resize() 
{
    int newCapacity = capacity * 2;
    Position* newData = new Position[newCapacity];
    
    // Copy all existing elements to new array
    for (int i = 0; i <= topIndex; i++) 
    {
        newData[i] = data[i];
    }
    
    // Switch to new array and update capacity
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Add element to top of stack
void Stack::push(Position pos_in) 
{
    if (topIndex >= capacity - 1) 
    {
        resize();
    }
    topIndex++;
    data[topIndex] = pos_in;
}

// Remove and return top element from stack
Position Stack::pop() 
{
    if (isEmpty()) 
    {
        cout << "Error: Stack is empty!" << endl;
        return Position(-1, -1, "ERROR"); 
    }
    Position value = data[topIndex];
    topIndex--;
    return value;
}

// Check if stack contains no elements
bool Stack::isEmpty() 
{
    return (topIndex == -1);
}

