#ifndef _SHIP_H_
#define _SHIP_H_
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

//************************Constants*********************
const int MAX_ITEMS = 10; //Max items the ship can hold
const int STARTING_FUEL = 100; //Starting fuel for the ship
//******************************************************

class Ship {
 public:
  // Name: Ship(string) - Overloaded ship 
  // Description: Creates a new ship that can hold items (MAX_ITEMS)
  //              and Fuel (STARTING_FUEL). Populates m_name
  // Preconditions: None
  // Postconditions: A new ship
  Ship(string name);
  // Name: GetName()
  // Description: Returns m_name
  // Preconditions: None
  // Postconditions: Returns ship's m_name
  string GetName();
  // Name: GetTotal(string type)
  // Description: Passed an item type (armor, weapon, or engine)
  //     Iterates over all items on ship and totals type passed in
  // Preconditions: None
  // Postconditions: Returns total value for armor, weapon, or engine
  int GetTotal(string);
  // Name: AddItem
  // Description: Adds a new item into m_items up to MAX_ITEMS.
  //    If at max, calls ReplaceItem
  // Preconditions: None
  // Postconditions: m_items is populated
  void AddItem(Item*);
  // Name: ReplaceItem(Item*)
  // Description: Used when m_shipItem is at capacity.
  //   Lists all ship items and replaces with updated pointer
  //   Does NOT make a new object - just updates pointer
  // Preconditions: None
  // Postconditions: Used to replace an item in inventory (m_shipItems)
  void ReplaceItem(Item*);
  // Name: GetFuel
  // Description: Returns fuel
  // Preconditions: None
  // Postconditions: Returns m_fuel
  int GetFuel();
  // Name: ModifyFuel(int)
  // Description: Used to increase (positive int) or
  //              decrease (negative int) m_fuel
  // Preconditions: None
  // Postconditions: Used to update fuel.
  void ModifyFuel(int);
  // Name: DisplayItems
  // Description: Displays a numbered list of all items on ship.
  // Preconditions: None
  // Postconditions: m_items is populated
  void DisplayItems();
  // Name: GetItemCount();
  // Description: Returns number of items in m_shipItems
  // Preconditions: None
  // Postconditions: Returns items in m_shipItems
  int GetItemCount();
  // Name: DisplayShip;
  // Description: Displays stats about the ship
  // Displays name, fuel, attack(weapon), defense(armor), engine(engine) all all items
  // Preconditions: None
  // Postconditions: None
  void DisplayShip();
private:
  vector<Item*> m_shipItems; //Items on the ship
  int m_fuel; //Fuel on the ship
  string m_name; //Name of the ship
};
#endif
