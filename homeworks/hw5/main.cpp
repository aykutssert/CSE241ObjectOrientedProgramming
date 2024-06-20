#include <iostream>
#include <string>
#include <vector>

#include "World.h"
#include "Robot.h"
#include "Humanic.h"
#include "OptimusPrime.h"
#include "Bulldozer.h"
#include "Robocop.h"
#include "Roomba.h"
using namespace std;

const int INITIAL_COUNT = 5; // there are 5 of each robot

int main()
{
    srand(time(0)); // seed random number generator

    World w; // the world was created

    // create robots and randomly place them in the grid
    /*std::vector<Robot *> robots;

    for (int i = 0; i < INITIAL_COUNT; i++)
    {
        //  humanic robots
        robots.push_back(new OptimusPrime(0, 100, 100, "optimusprime_" + std::to_string(i)));
        robots.push_back(new Robocop(1, 30, 40, "robocop_" + std::to_string(i)));

        // non-humanic robots
        robots.push_back(new Roomba(2, 3, 10, "roomba_" + std::to_string(i)));
        robots.push_back(new Bulldozer(3, 50, 200, "bulldozer_" + std::to_string(i)));
    }

    for (auto robot : robots) //Robots are randomly placed on the map.
    {
        int x, y;
        do
        {
            x = rand() % GRID_SIZE; //random coordinate values are taken
            y = rand() % GRID_SIZE; //random coordinate values are taken
        } while (w.getAt(x, y) != NULL); //If that point on the map is empty, the robot is placed.

        w.setAt(x, y, robot); //placing a robot on the map
        robot->setXY(x, y); //set the coordinates for the robot
        robot->setWorld(&w); //introduce the map to the robot
    }*/

    /*Robot *robots = new Robot [INITIAL_COUNT * 4];

    for (int i = 0; i < INITIAL_COUNT * 4; i += 4)
    {
        // humanic robots
        robots[i] =  OptimusPrime(0, 100, 100, "optimusprime_" + std::to_string(i / 4));
        robots[i + 1] =  Robocop(1, 30, 40, "robocop_" + std::to_string(i / 4));

        // non-humanic robots
        robots[i + 2] =  Roomba(2, 3, 10, "roomba_" + std::to_string(i / 4));
        robots[i + 3] =  Bulldozer(3, 50, 200, "bulldozer_" + std::to_string(i / 4));
    }

    for (int i = 0; i < INITIAL_COUNT * 4; i++)
    {
        int x, y;
        do
        {
            x = rand() % GRID_SIZE;      // random coordinate values are taken
            y = rand() % GRID_SIZE;      // random coordinate values are taken
        } while (w.getAt(x, y) != NULL); // If that point on the map is empty, the robot is placed.

        w.setAt(x, y, &robots[i]); // placing a robot on the map
        robots[i].setXY(x, y);   // set the coordinates for the robot
        robots[i].setWorld(&w);  // introduce the map to the robot
    }
*/
    Robot **robots = new Robot *[INITIAL_COUNT * 4];

    for (int i = 0; i < INITIAL_COUNT * 4; i += 4)
    {
        // humanic robots
        robots[i] = new OptimusPrime(0, 100, 100, "optimusprime_" + std::to_string(i / 4));
        robots[i + 1] = new Robocop(1, 30, 40, "robocop_" + std::to_string(i / 4));

        // non-humanic robots
        robots[i + 2] = new Roomba(2, 3, 10, "roomba_" + std::to_string(i / 4));
        robots[i + 3] = new Bulldozer(3, 50, 200, "bulldozer_" + std::to_string(i / 4));
    }

    for (int i = 0; i < INITIAL_COUNT * 4; i++)
    {
        int x, y;
        do
        {
            x = rand() % GRID_SIZE;      // random coordinate values are taken
            y = rand() % GRID_SIZE;      // random coordinate values are taken
        } while (w.getAt(x, y) != NULL); // If that point on the map is empty, the robot is placed.

        w.setAt(x, y, robots[i]); // placing a robot on the map
        robots[i]->setXY(x, y);   // set the coordinates for the robot
        robots[i]->setWorld(&w);  // introduce the map to the robot
    }

    string s;
    int count = 0;
    int x, y;

    while (true)
    {
        count = 0;   // variable created to count a robot left on the map
        w.Display(); // print the map

        w.SimulateOneStep(); // the game begins to be played.

        w.Display(); // print the map

        // a loop to find how many robots are left on the map
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (w.getAt(i, j) == NULL)
                    count++;
                else
                {
                    x = i;
                    y = j;
                }
            }
        }
        if (count == 99)
        { // If the number of spaces is 99, the game is over.
            cout << w.getAt(x, y)->getName() << " won\n";
            break;
        }
        cout << endl
             << "Press enter for next step" << endl;
        getline(cin, s);
    }

    //delete the dynamically allocated robots and the array itself
   for (int i = 0; i < INITIAL_COUNT * 4; i++)
    {
        if(robots[i]!=NULL)
           delete robots[i];
        
    }
     
    delete[] robots;
 
    return 0;
}
