# Project Dungeon Escape

Academic project completed in C++ (Programming for FinTech)  
Shanghai Advanced Institute of Finance – Shanghai Jiao Tong University (SJTU)

## Overview

Jon Snow is trapped and prisoned by Wildlings in a complex dungeon. 
He has been looking for an opportunity to escape and to unite the livings to fight against the imminent threat, the white walkers. 
Winter is coming. Tonight is a good opportunity as the guard is off the shift now. 
Ygritte and Jon’s friends at night’s watch outside have dug a tunnel exit. 
Jon has to seize this only chance to find the way to the tunnel within a short period of time before the guard is back. 
Mankinds’hope is pending on that.

## Project objective

In this project you will develop a number of algorithms to help Jon find the tunnel. 
You will implement the algorithms in C++, and will be graded on your program’s correctness, performance and programming style.

## Dungeon representation

The dungeon is represented as a text file composed of multiple rooms.
Each room contains:
- "." represents open floor, where Jon can walk safely
- "@" represents obstacles, where Jon should avoid
- "I" is the entrance door, where Jon enters each room.
- "O" is the exit door, where Jon leaves each room.
- "T" is the tunnel, which Jon can use to escape the dungeon for good.

All of the rooms except for the last room have exactly two doors, one entrance door, and one exit.
The last room has one entrance door and one tunnel.
The rooms are not necessarily the same size. If Jon walks into the obstacles in any of the rooms,
he will alert the guards and get caught.

A simple room might look like:
```
@@@@@@@
@@....@
I...@@@
@.....@
@@@@@.@
@T....@
@@@@.@@
```

Unfortunately, Jon cannot see anything in the dark, so he can only move in the North, South, East, or West directions. 
That is, he may not travel along the diagonals of the room but still he could feel the obstables by the training of being night’s watch and return to another directions. 
Your job is to find a route for him to the tunnel and output this route with a sequence of directions in “N”, “S”, “E”, “W”. 
Jon starts his journey at the entering door in the first room. 
Every time he leaves the room through an exit door, he will begin at the entering door in the next room.

## Specification

Jon knows that there are K rooms. He will search for the exit door in the first K-1 rooms, and search for the tunnel in the last room.
Once Jon finds the exit to a room, he must take one additional step to exit the room, depending on which edge of the room he is at. 
If there are multiple directions in which he could exit, then choose in order of “NSEW”.
If Jon cannot find an exit in the first K-1 rooms, or the tunnel in the last room, then the escape simply fails.

## Routing approach

You will develop two routing approaches for Jon:
```
1. Find the first valid path using a queue.
2. Find the first valid path using a stack.
```

Note that the approaches given here are high-level.
You will need to expand upon them to finish this project.

## Input and output format

The input file is a text-based map describing the layout of each room. 
The first line contains an integer indicating the number of rooms (suppose the number is K). 
The rest of the file is divided into K sections describing each room. 
In the first line of each section, the size of the room (M rows by N columns) is specified as a pair of integers, separated by a single space. 
The following M lines will contain exactly N characters for each. 
For example, the following is a legal input file (though it may be physically unrealistic):
```
2
3 3
@.@
..O
I.@
3 3
..I
.T@
...
```

The output will consist of K lines, where K is the number of rooms. 
Each line is a sequence of moves in directions of “N”, “S”, “E”, “W”, and must end with a end of line character. 
For instance,the queue-based output for the above map might look like:
NEEE
WS

If there is no possible way for Jon to escape without knocking over obstacles, print “Escapefailed.\n” to standard output.

## Stacks, Queues, and STL

You are encouraged to implement your own stack and queue classes. 
If you use the STL’s implementations, which will save you substantial programming time and most likely decrease the overall runtime of your program 
(STL containers have been highly optimized over many years). 

## Command Line Arguments

We will run your program with one of the commands:
```
./escape.exe –Stack < [testfile]
./escape.exe –Queue < [testfile]
```

Legal command line inputs include exactly one of –Stack and –Queue. 
If –Stack is present, then use the stack-based approach, and use the queue-based approach if –Queue is present. 
If both are present, neither is present, or if any other command line arguments are included, then print an informative error message to stderr and terminate the program by calling exit(1).
The notation < [testfile] is file input redirection. This means that your program will treat the contents of [testfile] as if it were coming in through cin. 
For this reason, you should use cin to read input, and cout to display output. Do not use ifstream or ofstream.

## Testing

Testing your code to see if it produces the correct solution is essential. 
We highly recommend that you test your code thoroughly with test cases beyond what we have given. 
For instance, your code may have a bug that the given examples do not uncover or your code works with a 4 * 5 grid but not a 10 * 12. 
Try to have a variety of maps to make sure that your code is robust and does not have hidden bugs. 
For example, have small-, medium-, and large-sized maze grids, mazes that are long or wide, and maze that are sparsely-populated (very few obstacles) and densely-populated (many obstacles).
Also you need testing inputs with errors for error-handling testings. It would be expected that error-handling would be part of the evaluation.


