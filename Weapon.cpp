/*****************************************
** File:    Weapon.cpp
** Description: This file implements the constructor and Display function for the Weapon class
***********************************************/

#include "Weapon.h"
#include <iostream>
using namespace std;

// weapon constructor
Weapon::Weapon(string name, string type, int value) : Item(name, type, value)
{
}

// weapon display function, displays name and value
void Weapon::Display()
{
  cout << WEAPON << GetName() << " "
       << "(" << GetValue() << ")" << endl;
}
