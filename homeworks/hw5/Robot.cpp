#include <iostream>
#include <string>

#include "Robot.h"

using namespace std;

class World;

Robot::Robot()
{

    x = 0;
    y = 0;
    moved = false;
    type = 5;
    strength = 0;
    hitpoint = 0;
    name = "";
    world = NULL;
}

int Robot::getType() const // getter
{
    return type;
} 
int Robot::getStrength() const // getter
{
    return strength;
} 
int Robot::getHitPoint() const // getter
{
    return hitpoint;
} 
bool Robot::getMoved() const // getter
{
    return moved;
} 
string Robot::getName() const // getter
{
    return name;
} 
void Robot::setHitpoint(int newHitPoint) // set new Hitpoint
{
    hitpoint = newHitPoint;
} 
void Robot::setXY(int _x, int _y) // set x and y coordinates
{
    x = _x;
    y = _y;
}
void Robot::setWorld(World *_world) // promoting the world for robot
{
    this->world = _world;
}
void Robot::IsItMoved(bool _moved) // robot flag
{
    moved = _moved;
}

string Robot::getType()
{
    switch (type)
    {
    case 0:
        return "OptimusPrime";
    case 1:
        return "Robocop";
    case 2:
        return "Roomba";
    case 3:
        return "Bulldozer";
    }
    return "unknown";
}
int Robot::getDamage() const
{

    int damage = rand() % strength + 1; // The common damage value for each robot is calculated.

    cout << "for " << getName() << " common damage for each robot: " << damage << endl;
    // cout << Robot::name << " attacks for " << damage << " points!" << endl;

    return damage;
}
void Robot::fightUp() // Fight function written for the fight when going to the Up

{
    cout << "\n\n\n";
    do
    {

        int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot.
        int damage_S = world->getAt(x - 1, y)->getDamage(); // Damage is calculated for the victim robot.
        cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
             << " hits " << world->getAt(x - 1, y)->getName() << "(" << world->getAt(x - 1, y)->getHitPoint() << ")" // hit prints are printed.
             << " with " << damage_R << endl;

        world->getAt(x - 1, y)->setHitpoint(world->getAt(x - 1, y)->getHitPoint() - damage_R); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x - 1, y)->getName() << " is " << world->getAt(x - 1, y)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x - 1, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
        {
            cout << world->getAt(x - 1, y)->getName() << " destroyed.\n";
            world->setAt(x - 1, y, NULL);

            break;
        }

        cout << world->getAt(x - 1, y)->getName() << "(" << world->getAt(x - 1, y)->getHitPoint() << ")"
             << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed.
             << " with " << damage_S << endl;

        world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
        {
            cout << world->getAt(x, y)->getName() << " destroyed.\n";
            world->setAt(x, y, NULL);

            break;
        }

    } while (1);
    cout << "\n\n\n";
}
void Robot::fightRight() // Fight function written for the fight when going to the right
{
    cout << "\n\n\n";
    do
    {

        int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot.
        int damage_S = world->getAt(x, y + 1)->getDamage(); // Damage is calculated for the victim robot.
        cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
             << " hits " << world->getAt(x, y + 1)->getName() << "(" << world->getAt(x, y + 1)->getHitPoint() << ")" // hit prints are printed.
             << " with " << damage_R << endl;

        world->getAt(x, y + 1)->setHitpoint(world->getAt(x, y + 1)->getHitPoint() - damage_R); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x, y + 1)->getName() << " is " << world->getAt(x, y + 1)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x, y + 1)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
        {
            cout << world->getAt(x, y + 1)->getName() << " destroyed.\n";
            world->setAt(x, y + 1, NULL);
            break;
        }

        cout << world->getAt(x, y + 1)->getName() << "(" << world->getAt(x, y + 1)->getHitPoint() << ")"
             << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed.
             << " with " << damage_S << endl;

        world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
        {
            cout << world->getAt(x, y)->getName() << " destroyed.\n";
            world->setAt(x, y, NULL);
            break;
        }

    } while (1);
    cout << "\n\n\n";
}
void Robot::fightDown() // Fight function written for the fight when going to the Down
{
    cout << "\n\n\n";
    do
    {
        int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot
        int damage_S = world->getAt(x + 1, y)->getDamage(); // Damage is calculated for the victim robot

        cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
             << " hits " << world->getAt(x + 1, y)->getName() << "(" << world->getAt(x + 1, y)->getHitPoint() << ")" // hit prints are printed
             << " with " << damage_R << endl;

        world->getAt(x + 1, y)->setHitpoint(world->getAt(x + 1, y)->getHitPoint() - damage_R); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x + 1, y)->getName() << " is " << world->getAt(x + 1, y)->getHitPoint() << endl;

        if (world->getAt(x + 1, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
        {
            cout << world->getAt(x + 1, y)->getName() << " destroyed.\n";
            world->setAt(x + 1, y, NULL);
            break;
        }

        cout << world->getAt(x + 1, y)->getName() << "(" << world->getAt(x + 1, y)->getHitPoint() << ")"
             << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed
             << " with " << damage_S << endl;

        world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
        {
            cout << world->getAt(x, y)->getName() << " destroyed.\n";
            world->setAt(x, y, NULL);
            break;
        }

    } while (1);
    cout << "\n\n\n";
}
void Robot::fightLeft()
{ // Fight function written for the fight when going to the left
    cout << "\n\n\n";
    do
    {
        int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot.
        int damage_S = world->getAt(x, y - 1)->getDamage(); // Damage is calculated for the victim robot
        cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
             << " hits " << world->getAt(x, y - 1)->getName() << "(" << world->getAt(x, y - 1)->getHitPoint() << ")" // hit prints are printed.
             << " with " << damage_R << endl;

        world->getAt(x, y - 1)->setHitpoint(world->getAt(x, y - 1)->getHitPoint() - damage_R); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x, y - 1)->getName() << " is " << world->getAt(x, y - 1)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x, y - 1)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
        {
            cout << world->getAt(x, y - 1)->getName() << " destroyed.\n";
            world->setAt(x, y - 1, NULL);
            break;
        }

        cout << world->getAt(x, y - 1)->getName() << "(" << world->getAt(x, y - 1)->getHitPoint() << ")"
             << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed.
             << " with " << damage_S << endl;

        world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

        cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

        if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
        {
            cout << world->getAt(x, y)->getName() << " destroyed.\n";
            world->setAt(x, y, NULL);
            break;
        }

    } while (1);
    cout << "\n\n\n";
}
void Robot::move() // Since the move function is the same for every robot, we do not need to write virtual.
{

    int direction = rand() % 4;

    if (direction == 0) // UP
    {
       

        if (x > 0 && world->getAt(x - 1, y) == NULL) // If the space above the robot is empty, it moves in that direction.
        {
            do
            {
                world->setAt(x - 1, y, world->getAt(x, y)); // displacement is done here.
                world->setAt(x, y, NULL);
                x--;

            } while (x > 0 && world->getAt(x - 1, y) == NULL); // continues until it is full.
        }
        
        if (x > 0 && world->getAt(x - 1, y) != NULL) // If the direction the robot is going is full, the robot enters the war.
        {
            cout << "\n\n\n";
            do
            {

                int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot.
                int damage_S = world->getAt(x - 1, y)->getDamage(); // Damage is calculated for the victim robot.
                cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
                     << " hits " << world->getAt(x - 1, y)->getName() << "(" << world->getAt(x - 1, y)->getHitPoint() << ")" // hit prints are printed.
                     << " with " << damage_R << endl;

                world->getAt(x - 1, y)->setHitpoint(world->getAt(x - 1, y)->getHitPoint() - damage_R); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x - 1, y)->getName() << " is " << world->getAt(x - 1, y)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x - 1, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
                {
                    cout << world->getAt(x - 1, y)->getName() << " destroyed.\n";
                    world->setAt(x - 1, y, NULL);

                    break;
                }

                cout << world->getAt(x - 1, y)->getName() << "(" << world->getAt(x - 1, y)->getHitPoint() << ")"
                     << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed.
                     << " with " << damage_S << endl;

                world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
                {
                    cout << world->getAt(x, y)->getName() << " destroyed.\n";
                    world->setAt(x, y, NULL);

                    break;
                }

            } while (1);
            cout << "\n\n\n";
        }
    }

    // Right
    if (direction == 1)
    {

        if (y < GRID_SIZE - 1 && world->getAt(x, y + 1) == NULL) // If the space right the robot is empty, it moves in that direction.
        {
            do
            {
                world->setAt(x, y + 1, world->getAt(x, y)); // displacement is done here.
                world->setAt(x, y, NULL);
                y++;

            } while (y < GRID_SIZE - 1 && world->getAt(x, y + 1) == NULL); // continues until it is full.
        }
        if (y < GRID_SIZE - 1 && world->getAt(x, y + 1) != NULL) // If the direction the robot is going is full, the robot enters the war.
        {

            cout << "\n\n\n";
            do
            {

                int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot.
                int damage_S = world->getAt(x, y + 1)->getDamage(); // Damage is calculated for the victim robot.
                cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
                     << " hits " << world->getAt(x, y + 1)->getName() << "(" << world->getAt(x, y + 1)->getHitPoint() << ")" // hit prints are printed.
                     << " with " << damage_R << endl;

                world->getAt(x, y + 1)->setHitpoint(world->getAt(x, y + 1)->getHitPoint() - damage_R); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x, y + 1)->getName() << " is " << world->getAt(x, y + 1)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x, y + 1)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
                {
                    cout << world->getAt(x, y + 1)->getName() << " destroyed.\n";
                    world->setAt(x, y + 1, NULL);
                    break;
                }

                cout << world->getAt(x, y + 1)->getName() << "(" << world->getAt(x, y + 1)->getHitPoint() << ")"
                     << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed.
                     << " with " << damage_S << endl;

                world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
                {
                    cout << world->getAt(x, y)->getName() << " destroyed.\n";
                    world->setAt(x, y, NULL);
                    break;
                }

            } while (1);
            cout << "\n\n\n";
        }
    }

    // LEFT
    if (direction == 2) // If the space left the robot is empty, it moves in that direction.
    {

        if (y > 0 && world->getAt(x, y - 1) == NULL)
        {
            do
            {
                world->setAt(x, y - 1, world->getAt(x, y)); // displacement is done here.
                world->setAt(x, y, NULL);
                y--;

            } while (y > 0 && world->getAt(x, y - 1) == NULL); // continues until it is full.
        }
        if (y > 0 && world->getAt(x, y - 1) != NULL) // If the direction the robot is going is full, the robot enters the war.
        {

            cout << "\n\n\n";
            do
            {
                int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot.
                int damage_S = world->getAt(x, y - 1)->getDamage(); // Damage is calculated for the victim robot
                cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
                     << " hits " << world->getAt(x, y - 1)->getName() << "(" << world->getAt(x, y - 1)->getHitPoint() << ")" // hit prints are printed.
                     << " with " << damage_R << endl;

                world->getAt(x, y - 1)->setHitpoint(world->getAt(x, y - 1)->getHitPoint() - damage_R); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x, y - 1)->getName() << " is " << world->getAt(x, y - 1)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x, y - 1)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
                {
                    cout << world->getAt(x, y - 1)->getName() << " destroyed.\n";
                    world->setAt(x, y - 1, NULL);
                    break;
                }

                cout << world->getAt(x, y - 1)->getName() << "(" << world->getAt(x, y - 1)->getHitPoint() << ")"
                     << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed.
                     << " with " << damage_S << endl;

                world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
                {
                    cout << world->getAt(x, y)->getName() << " destroyed.\n";
                    world->setAt(x, y, NULL);
                    break;
                }

            } while (1);
            cout << "\n\n\n";
        }
    }

    // Down
    if (direction == 3) // If the space down the robot is empty, it moves in that direction.
    {

        if (x < GRID_SIZE - 1 && world->getAt(x + 1, y) == NULL)
        {
            do
            {
                world->setAt(x + 1, y, world->getAt(x, y)); // displacement is done here.
                world->setAt(x, y, NULL);
                x++;

            } while (x < GRID_SIZE - 1 && world->getAt(x + 1, y) == NULL); // continues until it is full.
        }
        if (x < GRID_SIZE - 1 && world->getAt(x + 1, y) != NULL) // If the direction the robot is going is full, the robot enters the war.
        {

            cout << "\n\n\n";
            do
            {
                int damage_R = world->getAt(x, y)->getDamage();     // Damage is calculated for the attacker robot
                int damage_S = world->getAt(x + 1, y)->getDamage(); // Damage is calculated for the victim robot

                cout << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")"
                     << " hits " << world->getAt(x + 1, y)->getName() << "(" << world->getAt(x + 1, y)->getHitPoint() << ")" // hit prints are printed
                     << " with " << damage_R << endl;

                world->getAt(x + 1, y)->setHitpoint(world->getAt(x + 1, y)->getHitPoint() - damage_R); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x + 1, y)->getName() << " is " << world->getAt(x + 1, y)->getHitPoint() << endl;

                if (world->getAt(x + 1, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the victim robot is removed from the map.
                {
                    cout << world->getAt(x + 1, y)->getName() << " destroyed.\n";
                    world->setAt(x + 1, y, NULL);
                    break;
                }

                cout << world->getAt(x + 1, y)->getName() << "(" << world->getAt(x + 1, y)->getHitPoint() << ")"
                     << " hits " << world->getAt(x, y)->getName() << "(" << world->getAt(x, y)->getHitPoint() << ")" // hit prints are printed
                     << " with " << damage_S << endl;

                world->getAt(x, y)->setHitpoint(world->getAt(x, y)->getHitPoint() - damage_S); // new values are calculated.

                cout << "The new hitpoints of " << world->getAt(x, y)->getName() << " is " << world->getAt(x, y)->getHitPoint() << endl; // the new hitpoint is printed.

                if (world->getAt(x, y)->getHitPoint() <= 0) // If the hit point is zero or minus, the attacker robot is removed from the map.
                {
                    cout << world->getAt(x, y)->getName() << " destroyed.\n";
                    world->setAt(x, y, NULL);
                    break;
                }

            } while (1);
            cout << "\n\n\n";
        }
    }
}
