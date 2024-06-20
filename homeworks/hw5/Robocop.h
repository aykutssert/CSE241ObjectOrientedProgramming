#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "Humanic.h"
#include <string>

class Robocop : public Humanic
{
public:
    Robocop();                                                                                                            // default constructor
    Robocop(int newType, int newStrength, int newHit, string newName) : Humanic(newType, newStrength, newHit, newName) {} // 2. Constructor

    string getType() override; // overridden type function

    int getDamage() const override; // As Robocop, this robot has its own special damage value, so we overrided it.
};

#endif