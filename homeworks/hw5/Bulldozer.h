#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "Robot.h"
class Bulldozer : public Robot
{
public:
    Bulldozer();                                                                                                          // default constructor
    Bulldozer(int newType, int newStrength, int newHit, string newName) : Robot(newType, newStrength, newHit, newName) {} // 2. constructor

    string getType() override;      // overridden type function
    int getDamage() const override;  //As Bulldozer, this robot has its own special damage value, so we overrided it.
};

#endif