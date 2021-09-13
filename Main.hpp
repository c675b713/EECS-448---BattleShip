/**
*	File Name: Main.hpp
*	Author: Mat Besch, et al.
*	Date: 09/08/2021 
*	Brief: The implementation file for executive class
*/


#include "SetUp.h"
#include <iostream>
using namespace std;
int main(){
	ShipMap player1;
	ShipMap player2;
	SetUp setUpObject;
	player1 = setUpObject.returnMap(1);
	player2 = setUpObject.returnMap(2);
	
	//I was deciding whether this should be a bool, but currently think this should be a string or an enum
	//for the purposes of readablility
	string currentTurn = "player1";
	string columnLetter, rowString;
	int column, row;
	bool validInput;
	
	while (!player1.isGameOver() && !player2.isGameOver()){//while neither player has lost the game
		cout << "Hello " + currentTurn + "! Here is your opponent's board" << endl;
		if(currentTurn == "player1"){
			player2.printPlayerPhase();
		}
		else{
			player2.printPlayerPhase();
		}
		validInput = false)
		while(validInput == false){
			try{
				cout << "What column do you want to shoot at?" << endl;
				cin >> columnLetter;
				column = lettersToNumbers(columnLetter);
				cout << "What row do you want to shoot at?" << endl;
				cin << rowString;
				if(stoi(rowString) < 10){//This is for input sanitization
					row = stoi(rowString);
				}
				else{
					throw "Row out of bounds";
				}
				if(currentTurn == "player1"){
					player2.addAttempt(column, row-1);
				}
				else{
					player1.addAttempt(column, row-1);
				}
				validInput = true;//if we got to this point without throwing an exception, then we can stop looping and pass the turn
			}
			catch ("Invalid Letter"){
				//good error message
			}
			catch(invalid_argument){
				//good error message
			}
		}
		if(currentTurn = "player1"){
			currentTurn = "player2";
		}
		else{
			currentTurn = "player1";
		}
	}
}

int lettersToNumbers(string letter){
	switch(letter){
		case "A" || "a":
			return 0;
			break;
		case "B" || "b":
			return 1;
			break;
		case "C" || "c":
			return 2;
			break;
		case "D" || "d":
			return 3;
			break;
		case "E" || "e":
			return 4;
			break;
		case "F" || "f":
			return 5;
			break;
		case "G" || "g":
			return 6;
			break;
		case "H" || "h":
			return 7;
			break;
		case "I" || "i":
			return 8;
			break;
		case "J" || "j":
			return 9;
			break;
		default:
			throw "Invalid Letter"
	}
}