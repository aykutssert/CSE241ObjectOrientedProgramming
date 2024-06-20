#include <iostream>
#include <string>

#include "Roomba.h"

using namespace std;

string Roomba::getType()
{
    return "Roomba"; //The type is returned for Roomba.
}
int Roomba::getDamage() const
{
    
    int damage = Robot::getDamage(); // Damage is calculated for the Roomba robot
    
   
    damage += Robot::getDamage();    // Adds double damage exclusive to Roomba.
 cout<<"for "<<getName()<<" Double damage is added for Roomba.\n";
    cout << "Total attack of " << getName() << " : " << damage << endl;
    return damage;
}