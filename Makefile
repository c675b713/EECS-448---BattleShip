BattleShip: main.o ShipMap.o SetUp.o 
	g++ -std=c++11 -g -Wall main.o ShipMap.o SetUp.o -o BattleShip

main.o: main.cpp ShipMap.h SetUp.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
ShipMap.o: ShipMap.h ShipMap.cpp
	g++ -std=c++11 -g -Wall -c ShipMap.cpp

SetUp.o: SetUp.h SetUp.cpp
	g++ -std=c++11 -g -Wall -c SetUp.cpp
clean: 
	rm *.o BattleShip *.h.gch