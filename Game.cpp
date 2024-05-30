/*****************************************
** File:    Game.cpp
** Description: This file implements the functions outlined in Game.h in order to run the game
***********************************************/

#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// constructor
Game::Game(string itemFile, string planetFile) : m_fileItems(itemFile), m_filePlanets(planetFile)
{
}

// destructor, deallocates items, ship and planets
Game::~Game()
{
  // delete m_ship and set it to point to a nullptr
  delete m_ship;
  m_ship = nullptr;

  // delete all dynamically allocated items and set to nullptr
  for (size_t i = 0; i < m_items.size(); i++)
  {
    delete m_items.at(i);
    m_items.at(i) = nullptr;
  }
  m_items.clear(); // clear vector

  // delete all dynamically allocated planets and set to nullptr
  for (size_t i = 0; i < m_planets.size(); i++)
  {
    delete m_planets.at(i);
    m_planets.at(i) = nullptr;
  }
  m_planets.clear(); // clear vector
}

// load items
void Game::LoadItems()
{
  int tracker = 0; // variable to count the number of items successfully loaded

  // file stream for reading the item data
  ifstream file;
  file.open(m_fileItems); // attempt to open file
  if (file.is_open())
  {

    string name, type, value; // variables to store item members read from file

    // get line reads up the the DELIMTER = "," and assigns the text read to a variable
    while (getline(file, name, DELIMITER), getline(file, type, DELIMITER), getline(file, value, '\n'))
    {
      // if type is armor create a new Armor object and insert it into our items array
      if (type == "armor")
      {
        m_items.push_back(new Armor(name, type, stoi(value)));
        tracker++;
      }
      // if type is weapon create a new Weapon object and insert it into our items array
      else if (type == "weapon")
      {
        m_items.push_back(new Weapon(name, type, stoi(value)));
        tracker++;
      }
      // if type is engine create a new Engine object and insert it into our items array
      else if (type == "engine")
      {
        m_items.push_back(new Engine(name, type, stoi(value)));
        tracker++;
      }
    }
  }
  cout << tracker << " items loaded" << endl; // print out number of items loaded into our m_items vector
  ;
  file.close(); // close file after reading
}

void Game::LoadPlanets()
{
  int tracker = 0; // variable to count the number of items successfully loaded

  // file stream for reading the planet data
  ifstream file;
  file.open(m_filePlanets); // attempt to open file
  if (file.is_open())
  {
    string name, type, challenge; // variables to store Planet members read from file

    // get line reads up the the DELIMTER = "," and assigns the text read to a variable
    while (getline(file, name, DELIMITER), getline(file, type, DELIMITER), getline(file, challenge, '\n'))
    {
      // if type is gas create a new Gas object and insert it into our planets array
      if (type == "gas")
      {
        m_planets.push_back(new Gas(name, stoi(challenge)));
        tracker++;
      }
      else if (type == "enemy")
      {
        m_planets.push_back(new Enemy(name, stoi(challenge)));
        tracker++;
      }
      else if (type == "mining")
      {
        m_planets.push_back(new Mining(name, stoi(challenge)));
        tracker++;
      }
    }
  }
  cout << tracker << " Planets were loaded" << endl; // output number of planets loaded into our m_planets vector
  file.close();                                      // close file
}

// Initializes and sets up a new ship with starting items
void Game::ShipCreation()
{
  // Prompts user to enter name of their ship
  string shipName;
  cout << "Name of ship: ";
  getline(cin, shipName);

  // create ship instance with user inputed name
  m_ship = new Ship(shipName);

  // checks if there are items in our m_items vector
  if (m_items.size() > START_ENGINE && m_items[START_ENGINE])
  {
    // Add the starting engine to the ship's inventory.
    m_ship->AddItem(m_items[START_ENGINE]);
  }
  else
  {
    cout << "Starting engine item missing." << endl;
  }
  // checks if there is an item at the vector index we want to add
  if (m_items.size() > START_ARMOR && m_items[START_ARMOR])
  {
    // Add the starting armor to the ship's inventory.
    m_ship->AddItem(m_items[START_ARMOR]);
  }
  else
  {
    cout << "Starting armor item missing." << endl;
  }
  // makes sure there is an item in our m_items at the index we want to access
  if (m_items.size() > START_WEAPON && m_items[START_WEAPON])
  {
    // Add the starting weapon to the ship's inventory.
    m_ship->AddItem(m_items[START_WEAPON]);
  }
  else
  {
    cout << "Starting weapon item missing." << endl;
  }

  cout << "Ship named '" << shipName << "' has been created and equipped with initial items." << endl;
}

void Game::Action()
{
  int choice = 0;           // sets user choice to invalid choice
  bool continueGame = true; // Control boolean flag for the main game loop

  do
  {
    cout << "\nWhat would you like to do?\n";
    cout << "1. Examine Items\n";
    cout << "2. Move\n";
    cout << "3. Attack Planet\n";
    cout << "4. Travel to Utopia\n";
    cout << "5. Check Stats\n";
    cout << "6. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      DisplayShipItems();
      break;
    case 2:
      Move();
      
       // Check the ship's fuel to see if game should end                                                 
      if (m_ship->GetFuel() <= 0)                                                                         
      {
        cout << "Your ship has run out of fuel! Game over." << endl;
        continueGame = false; // End the game due to fuel depletion                                        
      }
      break;
    case 3:
      AttackPlanet();
      // Check the ship's fuel after to see if game should end
      if (m_ship->GetFuel() <= 0) 
      {
        cout << "Your ship has run out of fuel! Game over." << endl;
        continueGame = false; // End the game due to fuel depletion
      }
      break;
    case 4:
    {
      // result holds the return of TravelUtopia() (-1, 0, 1) and used to check if the game was won
      int result = TravelUtopia();
      if (result == 1 || result == -1)
      {
        continueGame = false; // Set flag to false to end the game
      }
      break;
    }
    case 5:
      Stats();
      break;
    case 6:
      cout << "Ending game." << endl;
      continueGame = false; // Ensures the game loop ends
      break;
    default:
      cout << "Invalid choice, please enter a number between 1-6." << endl;
    }
  } while (continueGame); // repeat until continueGame is false
}

void Game::Move()
{
  // checks to ensure m_planets vector is not empty
  if (m_planets.empty())
  {
    cout << "No planets available to move to." << endl;
    return;
  }

  // Randomly choose a new planet index within the range of 0-m_planets.size
  int newPlanetIndex = rand() % m_planets.size();

  // if the ship has 5 or more fuel it can travel to the next planet
  if (m_curPlanet && m_ship->GetFuel() >= -MOVE_FUEL)
  {
    // Deduct fuel
    m_ship->ModifyFuel(MOVE_FUEL);
    // Update the current planet
    cout << "Your fuel has been modified by " << MOVE_FUEL << endl;
    m_curPlanet = m_planets[newPlanetIndex];
    cout << "You travel to the next planet." << endl;
    cout << *m_curPlanet << endl; // output planet information using overloaded operator
  }
  else
  {
    cout << "Failed to move to a new planet." << endl;
  }
}

void Game::AttackPlanet()
{
  // Check if the planet has already been defeated
  if (m_curPlanet->GetIsExplored())
  {
    cout << "This planet has already been defeated." << endl;
    return;
  }

  cout << "Engaging in battle with the planet: " << m_curPlanet->GetName() << endl;

  // Get the result of the battle (true = win, false=defeat)
  bool victory = m_curPlanet->Battle(m_ship);

  // if the battle was won
  if (victory)
  {
    // If the battle is won, identify and collect an item based on the planet's challenge level.
    IdentifyItem(m_curPlanet->GetChallenge());
  }
  else
  {
    cout << "You failed to defeat the planet: " << m_curPlanet->GetName() << endl;
  }
}

void Game::IdentifyItem(int challenge)
{
  // temporary vector to store items matching the challenge level
  vector<Item *> identifyVector;

  // Iterate through m_items vector to find all items with the specified challenge level
  for (size_t i = 0; i < m_items.size(); i++)
  {
    if (m_items.at(i)->GetValue() == challenge)
    {
      // If an item's value matches the challenge, add it to the temporary vector
      identifyVector.push_back(m_items.at(i));
    }
  }

  // generate a random index to select an item from temporary vector
  int randomIndex = rand() % identifyVector.size();

  Item *selectedItem = identifyVector[randomIndex]; // selected item = random item from the temporary vector

  // add new item to ship
  m_ship->AddItem(selectedItem);
}

void Game::Stats()
{
  // Check if the ship exists
  if (m_ship)
  {
    m_ship->DisplayShip(); // Call the ship's method that displays its statistics
  }
  else
  {
    cout << "No ship available to display stats." << endl;
  }
}

int Game::TravelUtopia()
{
  // get the total engine power of the ship
  int totalEnginePower = m_ship->GetTotal("engine");

  // uncomment these if you want to check total engine power and m_winEngine values
  // cout << "Current total engine power: " << totalEnginePower << endl;
  // cout << "Engine power needed to safely travel to Utopia: " << m_winEngine << endl;

  // if the total engine power is less than the UTOPIA_MIN = 30
  if (totalEnginePower < UTOPIA_MIN)
  {
    cout << "Your engine power of " << totalEnginePower << " is below the minimum required " << UTOPIA_MIN << " to attempt the journey to Utopia." << endl;
    cout << "You are not prepared to try to travel to Utopia yet. Perhaps develop your engines more?" << endl;
    return 0; // Continue the game, as the player might still improve the ship.
  }
  // if the ship's engine power is greater than m_winEngine then the game is won and ends
  else if (totalEnginePower >= m_winEngine)
  {
    cout << "Congratulations! Your ship's engine power of " << totalEnginePower << " is sufficient to travel to Utopia! You win the game!" << endl;
    return 1; // Win condition met.
  }
  // if the ship's engine power is greater than the UTOPIA_MIN but less than the m_winEngine then the game ends with a loss
  else if (totalEnginePower > UTOPIA_MIN && totalEnginePower < m_winEngine)
  {
    cout << "Your ship attempts to make it to Utopia. " << endl;
    cout << "Your engine power of " << totalEnginePower << " is not enough to overcome the challenges to Utopia. You need at least " << m_winEngine << " to succeed. You eventually ran out of food and fuel and died." << endl;
    cout << "Please play again!" << endl;
    cout << "Good bye!" << endl;
    return -1; // Lose condition, as the player attempted and failed. Game over.
  }
  return 0;
}

void Game::DisplayShipItems()
{
  // Check if the ship has items
  if (m_ship->GetItemCount() > 0)
  {
    m_ship->DisplayItems(); // Call Ship's method to display items
  }
  else
  {
    cout << "No items found on the ship." << endl;
  }
}

void Game::StartGame()
{
  cout << "Welcome to Super Space Exploration!" << endl;
  LoadItems();
  LoadPlanets();
  ShipCreation();

  // generate a random number between UTOPIA MIN - UTOPIA_MAX and set it equal to m_winEngine member variable
  m_winEngine = UTOPIA_MIN + (rand() % (UTOPIA_MAX - UTOPIA_MIN + 1));

  // uncomment this if you would like to see the m_winEngine value when the game starts
  //cout << "win engine value: " << m_winEngine << endl;
  
  m_curPlanet = m_planets[START_PLANET]; // Set the starting planet
  Action();                              // main menu
}

// ask TA if you lose a battle with a planet and fuel goes under 0 if the game should end or you should be able to try and attack the same planet again
