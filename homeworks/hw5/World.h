
#ifndef WORLD_H
#define WORLD_H

class Robot;              // forward declaration
const int GRID_SIZE = 10; // const array size

class World
{

private:
    Robot *grid[GRID_SIZE][GRID_SIZE]; // map
public:
    World(); // default constructor
    Robot *getAt(int x, int y);             // Returns the value at points x and y on the map.
    void setAt(int x, int y, Robot *robot); // A value is placed on the map according to the given parameter.
    void Display();                         // for printing the map to the screen
    void SimulateOneStep();                 // game play function
};
#endif