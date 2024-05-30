#ifndef _MINING_H_
#define _MINING_H_

#include "Planet.h"

// Mining are planets that can be used to harvest fuel from

//***Constants***
const int MINING_SPECIAL = 2; //Base addition for Mining

class Mining: public Planet {
 public:
  // Name: Mining(string name, int challenge)
  // Description: Creates a new Mining planet
  // Preconditions: None
  // Postconditions: Creates a new Mining planet
  Mining(string, int);
  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string GetType();
};
#endif
