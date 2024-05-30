/*****************************************
** File:    Ship.cpp
** Project: CMSC 202 Project 4, Spring 2024
** Author:  Marcus Davis
** Date:    4/17/24
** Section: 32
** E-mail:  marcusd2@umbc.edu
** Description: This file implements the functions outlined in Ship.h for the Ship class
***********************************************/

#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

// ship constructor
Ship::Ship(string name)
{
  m_name = name;
  m_fuel = STARTING_FUEL;
}

// get name function
string Ship::GetName()
{
  return m_name;
}

// get total function
int Ship::GetTotal(string type)
{
  int totalValue = 0; // total value tracker

  // looping through the m_shipItems vector
  for (size_t i = 0; i < m_shipItems.size(); i++)
  {
    // check if the type of the item matches given type
    if (m_shipItems[i]->GetType() == type)
    {
      // add value of item to the total
      totalValue += m_shipItems[i]->GetValue();
    }
  }
  return totalValue; // return total
}

void Ship::AddItem(Item *newItem)
{
  // Check if the current number of items in the ship's inventory is less than the maximum allowed
  if (m_shipItems.size() < MAX_ITEMS)
  {
    // Add the new item to the inventory vector
    m_shipItems.push_back(newItem);

    cout << "You have found " << newItem->GetName() << "(" << newItem->GetType() << ")"
         << " " << newItem->GetValue() << endl;
  }
  else
  {
    // if the ship's item vector is full
    cout << "Inventory full. You have found " << newItem->GetName() << "(" << newItem->GetType() << ")"
         << " " << newItem->GetValue() << endl;
    DisplayItems();
    // Prompt the user to replace an existing item with the new item since the inventory is full

    ReplaceItem(newItem);
  }
}

// Method to replace an item when the ship's inventory is at capacity
void Ship::ReplaceItem(Item *newItem)
{
  int itemIndex;

  // prompt user to enter the index of the item to replace
  cout << "Enter the number of the item to replace (1-" << m_shipItems.size() << "): ";
  cin >> itemIndex;

  // validate user input to ensure within valid range
  while (itemIndex < 1 || static_cast<size_t>(itemIndex) > m_shipItems.size())
  {
    cout << "Invalid selection. Please try again. Enter a number between 1 and " << m_shipItems.size() << ": ";
    cin >> itemIndex;
  }

  // Adjusting index since user input is 1-based
  int indexToReplace = itemIndex - 1;

  cout << "Item replaced successfully. Now you have " << newItem->GetName() << " instead of " << m_shipItems[indexToReplace]->GetName() << "." << endl;

  // add item to ship's item vector
  m_shipItems[indexToReplace] = newItem;
}

// get fuel function
int Ship::GetFuel()
{
  return m_fuel;
}

void Ship::ModifyFuel(int amount)
{
  m_fuel += amount;
  cout << "New fuel amount: " << m_fuel << endl;
}

int Ship::GetItemCount()
{
  int tracker = 0; // tracker variable for num of items

  // iterate through ship's item vector
  for (size_t i = 0; i < m_shipItems.size(); i++)
  {
    tracker++;
  }
  return tracker; // return the size of the vector
}

// display Ship
void Ship::DisplayShip()
{
  cout << "**************************" << endl;
  // Display basic ship information

  // Using GetName() to retrieve the ship's name
  cout << "Name: " << GetName() << endl;

  // Using GetFuel() to show current fuel level
  cout << "Fuel: " << GetFuel() << endl;

  // Display aggregate stats for weapon, armor, and engine
  cout << "Attack: " << GetTotal("weapon") << endl;
  cout << "Defense: " << GetTotal("armor") << endl;
  cout << "Engine: " << GetTotal("engine") << endl;
  cout << "**************************" << endl;

  // Check if there are any items on the ship
  if (GetItemCount() == 0)
  {
    cout << "No items on the ship." << endl;
  }
  else
  {
    DisplayItems(); // Using DisplayItems() to list all items
  }
}

// Displays all items currently on the ship.
void Ship::DisplayItems()
{
  // Loop through all items in the ship's inventory
  for (size_t i = 0; i < m_shipItems.size(); i++)
  {
    if (m_shipItems.at(i) != nullptr)
    {
      cout << i + 1 << ". ";
      m_shipItems.at(i)->Display(); // ensure the item is not null before calling Display
    }
    else
    {
      cout << i + 1 << ". Null item detected." << endl;
    }
  }
}
