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
	/** @pre None
	*   @post The arrays are initialized and lives is set to 0
	*/
	ShipMap();

	/** @pre None
	*   @post None
	*/
	~ShipMap();

	/** @pre Coordinates for the specific column and row
	*   @post None
	*   @return Returns true if the there is both a ship and an attempt in corrsponding spots (ship has been hit)
	*/
	bool isHit(int row, int col);

	/** @pre None
	*   @post Prints out the map of ships during the player's phase
	*/
	void printPlayerPhase();

	/** @pre None
	*   @post Prints out the map of ships during the enemy's phase
	*/
	void printEnemyPhase();

	/** @pre Coordinates for the specific column and row
	*   @post Adds a ship to the ship array
	*/
	void addShip(int row, int col);

	/** @pre Coordinates for the specific column and row
	*   @post Adds an attempt to the attempt array
	*/
	void addAttempt(int row, int col);

	/** @pre None
	*   @post None
	*   @return Returns true if player has 0 lives remaining
	*/
	bool isGameOver();
	
	private:
	bool ships[9][10];
	bool attempts[9][10];
	int lives;
}

#endif
