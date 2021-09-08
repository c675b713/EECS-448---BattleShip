/**
*	File Name: ShipMap.hpp
*	Author: Ian Strasma
*	Date: 09/08/2021 
*	Brief: The implementation file for ShipMap class
*/

//PLEASE LET ME KNOW IF YOU FIND ANY MISTAKES IN HERE (This is definitely a WIP)

//We need to accomodate the user's entry for coordinates, either in the executive class or in these functions
//We should probably convert the A-J into ASCII to get integers for columns??? Maybe just subtract 1 from all the row integers
//Also we need to find the best way to make sure all the user's inputs work with the program

using namespace std;

ShipMap::ShipMap() //initializes the arrays with 0s
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ships[i][j] = 0;
			attempts[i][j] = 0;
		}
	}
}

ShipMap::~ShipMap()
{

}

bool ShipMap::isHit(int row, int col) //returns 1 if a ship has been hit
{
	if(ships[row][col] == 1 && attempts[row][col] == 1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void ShipMap::addShip(int row, int col) 
{
	bool shipIsGood = 0;
	while (shipIsGood == 0) //this might be temporary but I think its the best way to make sure that a ship is placed in an empty spot
	{
		if(ships[row][col] == 0)
		{
			ships[row][col] = 1;
		}
		else
		{
			// prompts user to reenter coordinates (will do later if this is best solution)
		}
	}
}

void ShipMap::addAttempt(int row, int col)
{
	bool attemptIsGood = 0;
	while (attemptIsGood == 0) //this might be temporary but I think its the best way to make sure that a ship is placed in an empty spot
	{
		if(attempts[row][col] == 0)
		{
			ships[row][col] = 1;
		}
		else
		{
			// prompts user to reenter coordinates (will do later if this is best solution)
		}
	}
}

void ShipMap::printPlayerPhase() //prints the grid showing information during player phase
{
	cout << "A B C D E F G H I J \n\n"; //this could be used to label the columns?? subject to change ofc
	for(int i = 0; i < 9; i++)
	{
		cout << i+1 << "  "; //this could be used to label the rows?? subject to change ofc
		for(int j = 0; j < 10; j++)
		{
			if(ships[i][j] == 1 && attempts[i][j] == 1) //prints a hit
			{
				cout << "X "; //we can change any of this notation later
			}
			else if(ships[i][j] == 1 && attempts[i][j] == 0) //prints an untouched ship
			{
				cout << "# ";
			}
			else if(ships[i][j] == 0 && attempts[i][j] == 1) // prints a miss
			{
				cout << "* ";
			}
			else //prints empty ocean
			{
				cout << "~ ";
			}
		}
		cout << "\n";
	}
}

void ShipMap::printPlayerPhase() //prints the grid showing information during enemy phase
{
	cout << "A B C D E F G H I J \n\n"; //this could be used to label the columns?? subject to change ofc
	for(int i = 0; i < 9; i++)
	{
		cout << i+1 << "  "; //this could be used to label the rows?? subject to change ofc
		for(int j = 0; j < 10; j++)
		{
			if(ships[i][j] == 1 && attempts[i][j] == 1) //prints a hit
			{
				cout << "X "; //we can change any of this notation later
			}
			else if(ships[i][j] == 0 && attempts[i][j] == 1) // prints a miss
			{
				cout << "* ";
			}
			else //prints empty ocean
			{
				cout << "~ ";
			}
		}
		cout << "\n";
	}
}
