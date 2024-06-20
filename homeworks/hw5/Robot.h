#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>

#include "World.h"

using namespace std;

class World;               // forward declaration
class Robot : public World // optimus prime , robocop , roomba , bulldozer
{

public:
    Robot();                                                                                                                             // default constructor
    Robot(int newType, int newStrength, int newHit, string name) : name(name), strength(newStrength), hitpoint(newHit), type(newType) {} // 2.constructor

    virtual string getType();

    virtual int getDamage() const;     // virtual getDamage
    int getType() const;               // getter
    int getStrength() const;           // getter
    int getHitPoint() const;           // getter
    bool getMoved() const;             // getter
    string getName() const;            // getter
    void setHitpoint(int newHitPoint); // set new Hitpoint
    void setXY(int _x, int _y);        // set x and y coordinates

    void setWorld(World *_world); // promoting the world for robot

    void IsItMoved(bool _moved); // robot flag

    void move();       // robot movement //Since the move function is the same for every robot, we do not need to write virtual.
    void fightUp();    // Fight function written for the fight when going to the Up
    void fightDown();  // Fight function written for the fight when going to the Down
    void fightRight(); // Fight function written for the fight when going to the right
    void fightLeft();  // Fight function written for the fight when going to the left
  

protected:
    int x, y;     // coordinates
    bool moved;   // flag
    int type;     // type example:Bulldozer
    int strength; // features of the robot
    int hitpoint; // features of the robot
    string name;  // features of the robot
    World *world; // promoting the world for robot
};

#endif