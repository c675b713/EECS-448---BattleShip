/**
*	File Name: ShipMap.h
*	Author: Ian Strasma
*	Date: 09/08/2021 
*	Brief: A header file for ShipMap class
*/

#ifndef SHIP_MAP_H
#define SHIP_MAP_H

#include <iostream>

class ShipMap
{
	public:
	ShipMap();
	~ShipMap();
	bool isHit();
	void printPlayerPhase();
	void printEnemyPhase();
	void addShip(int row, int col);
	void addAttempt(int row, int col);
	
	private:
	bool ships[9][10];
	bool attempts[9][10];
}

#endif
