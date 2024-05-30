/*****************************************
** File:    Armor.cpp
** Description: This file implements the constructor and Display function for the Armor class
***********************************************/

#include "Armor.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Armor::Armor(string name, string type, int value)
    : Item(name, type, value) // Prepends the ARMOR prefix to name
{
}

// Display function
void Armor::Display()
{
  cout << ARMOR << GetName() << " "
       << "(" << GetValue() << ")" << endl;
}
