#include <iostream>
#include <string>

#include "OptimusPrime.h"

string OptimusPrime::getType()
{     
    return "OptimusPrime"; // The type is returned for OptimusPrime.
}
int OptimusPrime::getDamage() const
{

    int damage = Humanic::getDamage(); // Damage is calculated for robots that are humanic
    
    if (rand() % 100 < 15)
    {
        // cout << "Strong attack from " << getName() << endl;
        cout<<"for "<<getName()<<" Damage exclusive to OptimusPrime: x2"<<endl;
        damage *= 2; //Damage exclusive to the optimus prime robot
    }
     cout << "Total attack of " << getName() << " : " << damage << endl;
    return damage;
}