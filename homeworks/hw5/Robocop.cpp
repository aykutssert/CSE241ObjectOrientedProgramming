#include <iostream>
#include <string>
using namespace std;

#include "Robocop.h"

string Robocop::getType()
{
    return "Robocop"; // The type is returned for Robocop.
}

int Robocop::getDamage() const
{
    int damage = Humanic::getDamage(); // Damage is calculated for robots that are humanic

    cout << "Total attack of " << getName() << " : " << damage << endl;
    return damage;
}