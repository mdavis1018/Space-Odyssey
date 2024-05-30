/*****************************************
** File:    Gas.cpp
** Description: This file implements the constructor and gettype function for the Gas class
***********************************************/

#include "Gas.h"
#include <iostream>
#include <string>
using namespace std;

// Gas constructors
Gas::Gas(string name, int challenge) : Planet(name, challenge)
{
}

// get type function
string Gas::GetType()
{
  return "gas";
}

// ask TA whether my gettype function is correct
