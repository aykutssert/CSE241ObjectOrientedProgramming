#include <iostream>
#include <string>

#include "World.h"
#include "Robot.h"
using namespace std;

class Robot;

World::World() // A 10x10 array is created in the default constructor.
{
    int i, j;
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = NULL;
        }
    }
}

Robot *World::getAt(int x, int y) // Returns the value at points x and y on the map.
{

    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) // if the parameters are correct
        return grid[x][y];

    else
        return NULL; // Returns null if map is empty
}

void World::setAt(int x, int y, Robot *robot) // A value is placed on the map according to the given parameter.
{

    if ((x >= 0) && (x < GRID_SIZE) && (y >= 0) && (y < GRID_SIZE)) // Returns null if map is empty
    {
        grid[x][y] = robot;
    }
}
void World::Display() // for printing the map to the screen
{
    int i, j;
    cout << endl
         << endl;

    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == NULL)
                cout << ".";
            else if (grid[i][j]->getType() == "OptimusPrime") // is the OptimusPrime robot on the map
                cout << "O";
            else if (grid[i][j]->getType() == "Robocop") // is the Robocop robot on the map
                cout << "R";
            else if (grid[i][j]->getType() == "Bulldozer") // is the Bulldozer robot on the map
                cout << "B";
            else if (grid[i][j]->getType() == "Roomba") // is the Roomba robot on the map
                cout << "M";
        }
        cout << endl;
    }
}
void World::SimulateOneStep()
{ // game play function

    for (int i = 0; i < GRID_SIZE; i++)
    {

        for (int j = 0; j < GRID_SIZE; j++)
        {

            if (grid[i][j] != NULL)
            {

                grid[i][j]->IsItMoved(false); // In these two loops, the flags of all robots in the map are set to false.
            }
        }
    }
    for (int i = 0; i < GRID_SIZE; i++)
    {

        for (int j = 0; j < GRID_SIZE; j++)
        {

            if (grid[i][j] != NULL && grid[i][j]->getMoved() == false)
            { // The robot is searched on the map and the motion function is called when found.

                grid[i][j]->IsItMoved(true); // The flag is set to true because the robot is moving.

                grid[i][j]->move(); // move function called
            }
        }
    }
}
