BattleShip: main.o
	g++ -std=c++11 -g -Wall main.o ShipMap.o SetUp.o -o BattleShip

main.o: main.hpp
	g++ -std=c++11 -g -Wall -c main.hpp
	
ShipMap.o: ShipMap.h ShipMap.hpp
	g++ -std=c++11 -g -Wall -c ShipMap.h ShipMap.hpp

SetUp.o: SetUp.h SetUp.hpp
	g++ -std=c++11 -g -Wall -c SetUp.h SetUp.hpp
clean: 
	rm *.o BattleShip