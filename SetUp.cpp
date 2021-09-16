/*
*   File: SetUp.cpp
*   Author: Zachary Andrews
*   Date: 09/8/2021
*   Brief: Implementation file for setup
*/

#include <iostream>
#include "SetUp.h"
#include "ShipMap.h"//dunno if i need this
#include <stdexcept>

SetUp::SetUp()
{
  int row1 = 0;
  int col1= 0;
  int row2 = 0;
  int col2 = 0;
  int ships = 0;
  std::cout<<"Welcome to Battleship!\n";
  for(int i = 1; i<2; i++)//for num of players
  {
    std::cout<<"Player "i", make your board! How many ships would you like to make?\n";
    std::cin>>ships;
    for(int j = 0; j<ships; j++)//for num of ships
    {
      std::cout<<"Enter the coordinates of your 1x"j+1" ship. ";
      do
      {
        std::cout<<"Make sure your ship is within 9x10 bounds of the board.\nRow: "
        if(i == 1)//player condition for row
        {
          std::cin>>row1;
        }
        else
        {
          std::cin>>row2;
        }
      }while(row1>9 || row1<1 || row2>9 || row2<1);
      if(i == 1)//player condition for col
      {
        do
        {
          std::cin>>col1;
          std::cout<<"Make sure your ship is within 9x10 bounds of the board.\nColumn: "
        }while(col1>9 || col2<1);
        player1_grid.addShip(row1, col1, j+1);//assuming there will be a parameter for length of ship
      }
      else
      {
        do
        {
          std::cout<<"Make sure your ship is within 9x10 bounds of the board.\nColumn: ";
          std::cin>>col2;
        }while(col2>9 || col2<1);
        player2_grid.addShip(row2, col2, j+1);
      }
    }
  }
}

ShipMap SetUp::returnMap(int player)
{
  if(player == 1)
  {
    return(player1_grid);
  }
  if(player == 2)
  {
    return(player2_grid);
  }
  else//if we use bool for player we don't need this
  {
    throw std::runtime_error("Given player int out of range\n");
  }
}
