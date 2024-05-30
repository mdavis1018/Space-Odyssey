#ifndef _ARMOR_H_
#define _ARMOR_H_

#include "Item.h"

//Constants
const string ARMOR = "|ARMOR| ";

// The Armor is a type of item used by your ship. It affects defense.

class Armor: public Item {
 public:
  // Name: Armor(string name, string type, int value)
  // Description: Creates a new Armor item
  // Preconditions: None
  // Postconditions: Can create a Armor item
  Armor(string, string, int);
  // Name: Display
  // Description: Displays ARMOR, name, and value of armor
  // Preconditions: None
  // Postconditions: Displays information about the armor
  void Display();
};
#endif
