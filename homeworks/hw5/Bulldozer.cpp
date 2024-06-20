#include <iostream>
#include <string>

#include "Bulldozer.h"

string Bulldozer::getType()
{
    return "Bulldozer"; //The type is returned for Bulldozer.
}
int Bulldozer::getDamage() const
{
    int damage = Robot::getDamage(); //Damage is calculated for the bulldozer robot

     cout << "Total attack of " << getName() << " : " << damage << endl;
    return damage;
}