#include <iostream>
#include <string>

#include "Humanic.h"
using namespace std;

 int Humanic::getDamage() const 
{
  
  int damage = Robot::getDamage(); // Damage common to every robot

  if (rand() % 10 == 0)
  {
    // cout << "10% chance of tactical attack " << getName() << endl;
    cout << "for "<<getName()<<" Damage of robots that are humanic: +50"<<endl;
    damage += 50; // Damage is calculated for robots that are humanic
  }

  return damage;
}