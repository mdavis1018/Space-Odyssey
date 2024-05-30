# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Main executable target
proj4: Game.o Ship.o Planet.o Item.o Gas.o Enemy.o Mining.o Weapon.o Armor.o Engine.o proj4.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) Game.o Ship.o Planet.o Item.o Gas.o Enemy.o Mining.o Weapon.o Armor.o Engine.o proj4.cpp -o proj4

# Object files dependencies
Game.o: Game.cpp Game.h Ship.h Planet.h Item.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Game.cpp

Ship.o: Ship.cpp Ship.h Item.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Ship.cpp

Planet.o: Planet.cpp Planet.h Gas.h Enemy.h Mining.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Planet.cpp

Item.o: Item.cpp Item.h Engine.h Armor.h Weapon.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Item.cpp

Gas.o: Gas.cpp Gas.h Planet.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Gas.cpp

Engine.o: Engine.cpp Engine.h Item.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Engine.cpp

Enemy.o: Enemy.cpp Enemy.h Planet.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Enemy.cpp

Mining.o: Mining.cpp Mining.h Planet.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Mining.cpp

Weapon.o: Weapon.cpp Weapon.h Item.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Weapon.cpp

Armor.o: Armor.cpp Armor.h Item.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Armor.cpp

# Clean target to remove object files and executable
clean:
	rm -f *.o proj4

# Target to run the program with default inputs
run:
	./proj4 proj4_items.txt proj4_planets.txt

# Additional run target with the same configuration
run1: 
	./proj4 proj4_items.txt proj4_planets.txt

# Target to run Valgrind for memory leak checks
val1:
	valgrind ./proj4 proj4_items.txt proj4_planets.txt

valgrind:
	valgrind --leak-check=full --track-origins=yes ./proj4 proj4_items.txt proj4_planets.txt
