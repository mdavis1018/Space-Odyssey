/*****************************************
** File:    Engine.cpp
** Description: This file implements the constructor and Display function for the Engine class
***********************************************/

#include "Engine.h"
#include <iostream>
using namespace std;

// constructor
Engine::Engine(string name, string type, int value) : Item(name, type, value)
{
}

// engine display function
void Engine::Display()
{
  // use item getters because we do not have access to item's private variables
  cout << ENGINE << GetName() << " "
       << "(" << GetValue() << ")" << endl;
}
