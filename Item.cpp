/*****************************************
** File:    Item.cpp
** Description: This file implements the constructor, destroyer and getter functions for the Item class
***********************************************/

#include "Item.h"
#include <iostream>
#include <string>
using namespace std;

// Item constructor using initialization list
Item::Item(string name, string type, int value) : m_name(name), m_type(type), m_value(value)
{
}

// Item destructor
Item::~Item()
{
  // nothing needed because Item is an abstract class
}

// Get Type function
string Item::GetType()
{
  return m_type;
}

// Get name function
string Item::GetName()
{
  return m_name;
}

// Get value function
int Item::GetValue()
{
  return m_value;
}
