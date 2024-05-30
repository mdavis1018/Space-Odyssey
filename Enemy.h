#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Planet.h"

// Enemy are planets that can be used to harvest fuel from

//***Constants***
const int ENEMY_SPECIAL = 2; //Base addition for Enemy

class Enemy: public Planet {
 public:
  // Name: Enemy(string name, int challenge)
  // Description: Creates a new Enemy planet
  // Preconditions: None
  // Postconditions: Creates a new Enemy planet
  Enemy(string, int);
  // Name: GetType
  // Description: Returns type of planet
  // Preconditions: None
  // Postconditions: Returns the type of planet
  string GetType();
};
#endif
