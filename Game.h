#ifndef _GAME_H_
#define _GAME_H_

//Includes of required classes
#include "Ship.h"
#include "Planet.h"
#include "Enemy.h"
#include "Gas.h"
#include "Mining.h"
#include "Item.h"
#include "Armor.h"
#include "Engine.h"
#include "Weapon.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//************************Constants*********************
// GAME CONSTANTS
const int START_PLANET = 0; //The index of the planet the ship starts at
const int MOVE_FUEL = -5; //Fuel burned to move from planet to planet
const int START_ARMOR = 0; //Index of starting armor in m_items
const int START_ENGINE = 1; //Index of starting engine in m_items
const int START_WEAPON = 2; //Index of starting weapon in m_items
const char DELIMITER = ','; //delimiter for each item in the files
const int UTOPIA_MIN = 30; //Minimum engine requirement for Utopia
const int UTOPIA_MAX = 50; //Maximum engine requirement for Utopia
//******************************************************

class Game {
public:
  // Name: Game(string itemFile, string planetFile) - Overloaded Constructor
  // Description: Creates a new Game by setting m_fileItems and m_filePlanets
  // Preconditions: None
  // Postconditions: Sets two file names in Game
  Game(string, string);
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated
  //                 in Game (ship, items, and planets)
  ~Game();
  // Name: LoadItems()
  // Description: Dynamically allocates items and inserts them into
  //              the m_items vector
  // Note: the number of items is NOT known - you should not use constants
  // Hint: Use getline(file,variable,delimiter) - may also use stoi
  // Precondition: m_itemFile is populated
  // Postcondition: m_items is populated
  void LoadItems();
  // Name: LoadPlanets()
  // Description: Dynamically allocates items and inserts them into
  //              the m_planets vector
  // Note: the number of planets is NOT known - you should NOT use constants
  // Hint: Use getline(file,variable,delimiter) - may also use stoi
  // Precondition: m_planetFile is populated
  // Postcondition: m_planets is populated
  void LoadPlanets();
  // Name: ShipCreation()
  // Description: Populates m_ship and asks name (sets name of ship)
  //              Also adds items (START_ENGINE, START_ARMOR, START_WEAPON)
  // Preconditions: None
  // Postconditions: m_ship is populated
  void ShipCreation();
  // Name: StartGame()
  // Description: Welcomes the player to the game. "Super Space Exploration"
  //              Calls LoadPlanets, LoadItems, ShipCreation, sets the m_curPlanet (0)
  //              randomizes m_winEngine based on UTOPIA_MAX and UTOPIA_MIN
  //              Finally, calls Action (which is the main menu)
  // Preconditions: Input files must exist
  // Postconditions: All game components loaded to play game
  void StartGame();
  // Name: Action()
  // Description: Menu for game. Displays menu.
  //              Player can examine the ship's items, move, attack planet,
  //              Try to travel to Utopia, check stats, or quit
  //              Player dies in one of two ways: 1. <= 0 fuel or
  //                   2. Tries to go to Utopia but doesn't have high enough engine
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
  void Action();
  // Name: Move
  // Description: Moves ship to new random location
  //              Charges MOVE_FUEL as cost to move to new planet
  //              Displays information about new planet
  // Preconditions: Must be valid move (may go to same planet more than once)
  // Postconditions: Displays planet information and reduces fuel
  void Move();
  // Name: AttackPlanet
  // Description: Allows ship to attack a planet
  //              1. Checks if planet already defeated (displays message if already won)
  //              2. Calls Planet's battle with ship (if not already defeated)
  //              3. Displays if win or not. Can attack again if not defeated.
  //              4. If winner, Identifies an item load on ship
  // Preconditions: None
  // Postconditions: Fuel may be below zero. May get new item.
  void AttackPlanet();
  // Name: IdentifyItem(int challenge)
  // Description: Randomly identifies an item of the challenge's level
  //              Calls AddItem in ship and tries to add the item
  // Preconditions: None
  // Postconditions: Will try to add an item to the ship of a random type
  void IdentifyItem(int);
  // Name: Stats()
  // Description: Calls the ship's display function
  // Preconditions: None
  // Postconditions: None
  void Stats();
  // Name: TravelUtopia()
  // Description: Attempts to win game if total engine value > m_engineValue
  //              if total engine value is below UTOPIA_MIN, returns 0
  //              If total engine value above m_engineValue, returns 1
  //              If total engine value below m_engineValue, returns -1
  // Preconditions: None
  // Postconditions: -1 = lose; 0 = continue, 1 = win
  int TravelUtopia();
  // Name: DisplayShipItems
  // Description: Displays a numbered list of all items on ship
  // Preconditions: m_items has items in it otherwise says No Items Found
  // Postconditions: None
  void DisplayShipItems();
private:
  vector<Item*> m_items; // Vector for holding all items (loaded from file)
  vector<Planet*> m_planets; //Vector for holding all planets (loaded from file)
  Ship* m_ship; // Ship pointer for Ship (Player)
  string m_fileItems; //Name of the file with the items details
  string m_filePlanets; //Name of the file with the planet names
  int m_winEngine; //Random number between 30 - 50 used to calculate utopia
  Planet* m_curPlanet; //The current planet the ship is orbiting
};

#endif
