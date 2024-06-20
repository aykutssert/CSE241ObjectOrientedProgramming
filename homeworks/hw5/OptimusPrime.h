#ifndef OPTIMUSPRIME_h
#define OPTIMUSPRIME_h

#include "Humanic.h"

class OptimusPrime : public Humanic
{
public:
    OptimusPrime();                                                                                                            // default constructor
    OptimusPrime(int newType, int newStrength, int newHit, string newName) : Humanic(newType, newStrength, newHit, newName) {} // 2. Constructor
    string getType() override;                                                                                                 // overridden type function
    int getDamage() const override;                                                                                            // As optimusPrime, this robot has its own special damage value, so we overrided it.
};

#endif