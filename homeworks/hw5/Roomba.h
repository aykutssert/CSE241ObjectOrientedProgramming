
#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.h"

class Roomba : public Robot
{
public:
    Roomba(); // default constructor
    Roomba(int newType, int newStrength, int newHit, string newName) : Robot(newType, newStrength, newHit, newName) {} // 2. constructor
    string getType() override;  //overridden type function
    int getDamage() const override;  //As Roomba, this robot has its own special damage value, so we overrided it.
};

#endif