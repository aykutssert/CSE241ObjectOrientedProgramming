

#ifndef HUMANIC_H
#define HUMANIC_H
#include "Robot.h"

class Humanic : public Robot
{
public:
Humanic(); // default constructor
    Humanic(int newType, int newStrength, int newHit, string newName) : Robot(newType, newStrength, newHit, newName) {} //2. constructor
    virtual int getDamage() const override; //Robots included in the humanic class also have their own special damage values, so we override this function.
};

#endif