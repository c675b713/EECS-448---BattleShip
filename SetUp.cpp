#include <iostream>
#include "SetUp.h"
using namespace std;
SetUp::SetUp(){
	int row, col, ships;
	string rowString, colString;
	bool valid_input = false;
	cout << "Welcome to Battleship!" << endl;
	cout << "How many ships do you want to play with?\n";
	do
	{
		cin >> ships;
    		if(ships < 1 || ships > 6){
   			cout << "That is an invalid number of ships! Please try again." << endl;
   		}
	}while(ships<1 || ships > 6);
	for (int playerNum = 1; playerNum<=2; playerNum++){
		cout << "Hello Player " << playerNum << "!" << endl;
		for (int i =1; i<=ships; i++){
			if(playerNum == 1){
        			player1Map.printPlayerPhase();
    			}
    			else{
				player2Map.printPlayerPhase();
			}
			valid_input = false;
			while(valid_input == false){
				try{
					cout << "Enter the starting position of your 1x" << i << " ship. \nColumn:";
          				cin >> colString;
					col = SetUp::lettersToNumbers(colString);
          				cout << "Row: ";
					cin >> rowString;
					row = stoi(rowString);//throws an invalid_argument exeption when it fails;
					if(row < 1 || row > 9){
						throw string("Out of Bounds");
					}
					if(playerNum == 1){
						player1Map.addShip(row-1, col, i);
					}
					else{
						player2Map.addShip(row-1, col, i);
					}
					valid_input = true;//This line will only be reached if we don't throw an exception
				}
        			catch (string e){
					if(e == "Out of Bounds"){
						cout << "That number is not a row number, please try again!" << endl;
					}
					else if(e == "Invalid Letter"){
						cout << "That is not the name of a column, please try again!" << endl;
					}
					else{
						cout << e << endl;
					}
				}
				catch(invalid_argument){
					cout << "That is not a valid number, please try again" << endl;
				}
				catch(...){
          				cout << "what?" << endl;
				}
			}
		}
	}
}
	
				
ShipMap SetUp::returnMap(int player)
{
	if(player == 1)
	{
		return(player1Map);
	}
	if(player == 2)
	{
		return(player2Map);
	}
}

int SetUp::lettersToNumbers(string letter){
	if(letter == "A" || letter == "a"){
		return 0;
	}
	else if(letter == "B" || letter == "b"){
		return 1;
	}
	else if(letter == "C" || letter == "c"){
		return 2;
	}
	else if(letter == "D" || letter == "d"){
		return 3;
	}
	else if(letter == "E" || letter == "e"){
		return 4;
	}
	else if(letter == "F" || letter == "f"){
		return 5;
	}
	else if(letter == "G" || letter == "g"){
		return 6;
	}
	else if(letter == "H" || letter == "h"){
		return 7;
	}
	else if(letter == "I" || letter == "i"){
		return 8;
	}
	else if(letter == "J" || letter == "j"){
		return 9;
	}
	else {
		throw string("Invalid Letter");
	}
}
	
