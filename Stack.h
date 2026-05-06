#ifndef STACK_H
#define STACK_H

#include "Position.h"

class Stack 
{
public:
    Stack(int size = 100); // Constructor with default size of 100
    ~Stack(); // Destructor to clean up memory
    
    // Safety: prevent copying to avoid memory issues
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    
    void push(Position pos_in); // Add element to top of stack
    Position pop(); // Remove and return top element
    bool isEmpty(); // Check if stack has no elements

private:
    void resize(); // Double stack size when full

    // Stack data storage
    Position* data; // Dynamic array holding stack elements
    int capacity; // Maximum number of elements stack can hold
    int topIndex; // Index of top element (-1 when empty)
};

#endif

