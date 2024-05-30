/*****************************************
** File:    Mining.cpp
** Description: This file implements the constructor and gettype function for the Mining class
***********************************************/

#include "Mining.h"
#include <iostream>
using namespace std;

// mining constructor
Mining::Mining(string name, int challenge) : Planet(name, challenge) {}

// get type function, returns string
string Mining::GetType()
{
  return "mining";
}
