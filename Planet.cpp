/*****************************************
** File:    Planet.cpp
** Description: This file implements the functions outlined by Planet.h for the Planet class
***********************************************/

#include "Planet.h"
#include <iostream>
using namespace std;

// planet constructor
Planet::Planet(string name, int challenge) : m_name(name), m_challenge(challenge), m_isExplored(false) {}

bool Planet::Battle(Ship *ship)
{
  cout << "Battle commencing!" << endl;

  int difficulty = rand() % (m_challenge + 1); // randomly chooses difficulty based on m_challenge + 1
  cout << "m_challenege: " << m_challenge << endl;
  int shipAttack = ship->GetTotal("weapon"); // gets total ship attack
  int shipDefense = ship->GetTotal("armor"); // gets total ship defense
  cout << "Battle difficulty: " << difficulty << endl;
  cout << "Ship's attack power: " << shipAttack << endl;
  cout << "Ship's defense rating: " << shipDefense << endl;

  int delta = difficulty - shipAttack; // Calculate the difference between planet rand diff and ship's attack total
  int costDelta = delta - shipDefense; // calculates difference between delta and ship's defense total for lost battle

  if (delta < 0)
  {
    // Ship wins
    int fuelGained = -delta * FUEL_MULTI_WIN; // calculates fuel gained based on negative delta and fuel win constant

    ship->ModifyFuel(fuelGained); // Increase the ship's fuel
    cout << "Your planetary bombardment worked. You won!" << endl;
    cout << "Your fuel has been modifed by " << fuelGained << " fuel units" << endl;
    m_isExplored = true; // Mark the planet as explored
  }
  else if (delta == 0)
  {
    // ship's attack total and planet difficulty is even have ship win and gain FUEL_MULTI_WIN constant fuel = 20;
    ship->ModifyFuel(FUEL_MULTI_WIN);
    cout << "Your planetary bombardment worked. You won!" << endl;
    cout << "Your fuel has been modifed by " << FUEL_MULTI_WIN << " fuel units" << endl;
    m_isExplored = true; // Mark the planet as explored
  }
  else if (delta > 0)
  {
    // Ship loses the battle
    int fuelPenalty = costDelta * FUEL_COST_DELTA; // Calculates fuel penalty based on costDelta times fuel cost delta = 3
    ship->ModifyFuel(costDelta);                   // Reduce the ship's fuel
    cout << "Ship loses. Fuel reduced by " << fuelPenalty << " units due to battle difficulty." << endl;
  }
  return m_isExplored;
}

// get name function
string Planet::GetName()
{
  return m_name;
}

// set is explored function
void Planet::SetIsExplored()
{
  m_isExplored = true;
}

// returns if the planet has been explored
bool Planet::GetIsExplored()
{
  return m_isExplored;
}

// returns challenge level of planet
int Planet::GetChallenge()
{
  return m_challenge;
}

// overloaded << function, outputs planet info
ostream &operator<<(ostream &output, Planet &planet)
{
  output << planet.GetName() << "(" << planet.GetType() << ")"
         << "Challenge: " << planet.GetChallenge();
  return output;
}

// planet destroyer
Planet::~Planet()
{
}
