#ifndef _PLANET_H_
#define _PLANET_H_
#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;

//The parent class for all of the planets

//Constants
//FUEL_MULTI_WIN is how much fuel you win in a battle
const int FUEL_MULTI_WIN = 20; //How much fuel you win in battle
//FUEL_COST_DELT is cost/point delta between ship attack and planet defense
const int FUEL_COST_DELTA = 3; //Fuel cost per point delta

class Planet {
 public:
  // Name: Planet(string name, int challenge)
  // Description: Used to populate name, challenge, and isExplored (defaults to false)
  // Preconditions: None
  // Postconditions: Used to populate planet data
  Planet(string, int);
  // Name: Planet Destructor
  // Description: Virtual destructor for an planet
  // Preconditions: None
  // Postconditions: Does nothing but cannot be omitted
  virtual ~Planet();
  // Name: Battle()
  // Description: Describes battle between planet and ship
  //              1. Indicates that the battle is starting
  //              2. Randomly chooses the difficult based on m_challenge + 1
  //              3. Gets the ship's attack and defense
  //              4. Compares difficulty with the ship's attack
  //                 If difficult is greater, notifies player, and calculates
  //                 the delta and multiplies with FUEL_COST_DELTA
  //                 and modifies the ship fuel (penalty)
  //                 If ship attack is higher, increases fuel by FUEL_MULTI_WIN
  //                 and sets isExplored
  // Preconditions: None
  // Postconditions: Returns true if win, else false
  bool Battle(Ship*);
  // Name: GetType()
  // Description: Purely virtual type (implemented in child classes)
  // Preconditions: None
  // Postconditions: Must be implemented in child classes
  virtual string GetType() = 0;
  // Name: GetName()
  // Description: Returns planet name
  // Preconditions: None
  // Postconditions: Returns planet name
  string GetName();
  // Name: SetIsExplored
  // Description: Sets IsExplored to true
  // Preconditions: None
  // Postconditions: Toggles from false to true when explored
  void SetIsExplored();
  // Name: GetIsExplored
  // Description: Returns m_isExplored
  // Preconditions: None
  // Postconditions: Returns true if m_isExplored is true
  bool GetIsExplored();
  // Name: GetChallenge
  // Description: Returns challenge of planet
  // Preconditions: None
  // Postconditions: Returns challenge of planet
  int GetChallenge();
  // Name: Overloaded <<
  // Description: Prints the details of planet (name, type, and challenge)
  // Preconditions: None
  // Postconditions: returns an ostream with output of planet
  friend ostream& operator<<(ostream&, Planet&);
private:
  string m_name; //Name of the planet
  int m_challenge; //How challenging this planet is to explore
  bool m_isExplored; //If planet has been explored (true=has been)
};
#endif
