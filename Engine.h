#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Item.h"

//Constants
const string ENGINE = "->ENGINE-> ";

// The Engine is a type of item used by your ship. It affects engine.

class Engine: public Item {
 public:
  // Name: Engine(string name, string type, int value)
  // Description: Creates a new Engine item
  // Preconditions: None
  // Postconditions: Can create a Engine
  Engine(string, string, int);
  // Name: Display
  // Description: Displays ENGINE, name, and value of engine item
  // Preconditions: None
  // Postconditions: Displays information about the engine
  void Display();
};
#endif
