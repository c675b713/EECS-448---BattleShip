/**
*	File Name: Main.hpp
*	Author: Mat Besch, et al.
*	Date: 09/08/2021
*	Brief: The implementation file for executive class
*/


#include "SetUp.h"
#include <iostream>
#include <stdexcept>
using namespace std;


int main(){
	ShipMap player1;
	ShipMap player2;
	SetUp setUpObject;
	player1 = setUpObject.returnMap(1);
	player2 = setUpObject.returnMap(2);
	
	string currentTurn = "player1";
	string columnLetter, rowString;
	int column, row;
	bool validInput;
	
	while (!player1.isGameOver() && !player2.isGameOver()){//while neither player has lost the game
		cout << "Hello " + currentTurn + "! Here is your opponent's board" << endl;
		if(currentTurn == "player1"){
			player2.printEnemyPhase();
		}
		else{
			player1.printEnemyPhase();
		}
		validInput = false;
		while(validInput == false){
			try{
				cout << "What column do you want to shoot at?" << endl;
				cin >> columnLetter;
				column = SetUp::lettersToNumbers(columnLetter);
				cout << "What row do you want to shoot at?" << endl;
				cin >> rowString;
				if(stoi(rowString) < 10 && stoi(rowString) > 0){//This is for input sanitization
					row = stoi(rowString);
				}
				else{
					throw string("Row out of bounds");
				}
				if(currentTurn == "player1"){
					player2.addAttempt(row-1, column);
				}
				else{
					player1.addAttempt(row-1, column);
				}
				validInput = true;//if we got to this point without throwing an exception, then we can stop looping and pass the turn
			}
			catch (string e){
				if (e == "Invalid Letter"){
					cout << "That letter is not valid, please try a different letter" << endl;
				}
				else{
					cout << e << endl;
				}
			}
			catch(invalid_argument){
				//good error message
			}
		}
		if(currentTurn == "player1"){
			currentTurn = "player2";
		}
		else{
			currentTurn = "player1";
		}
	}
	if(player1.isGameOver()){
		cout << "Congratulations Player 2! You win!" << endl;
	}
	else {
		cout << "congratulations Player 1! You win!" << endl;
	}
}
