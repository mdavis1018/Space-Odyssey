/*****************************************
** File:    Enemy.cpp
** Description: This file implements the constructor and gettype function for the Enemy class
***********************************************/

#include "Enemy.h"
#include <iostream>
#include <string>
using namespace std;

// enemy constructor
Enemy::Enemy(string name, int challenge) : Planet(name, challenge)
{
}

// get type function, returns a string
string Enemy::GetType()
{
  return "enemy";
};
