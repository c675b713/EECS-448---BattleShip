/*
*   File: SetUp.cpp
*   Author: Zachary Andrews
*   Date: 09/8/2021
*   Brief: Implementation file for setup
*/

#include <iostream>
#include "SetUp.h"
#include "ShipMap.h"//dunno if i need this


SetUp::SetUp()
{
  int row1 = 0;
  int col1= 0;
  int row2 = 0;
  int col2 = 0;
  int ships = 0;
  std::cout<<"Welcome to Battleship!\n";
  for(int i = 1; i<2; i++)
  {
    std::cout<<"Player " << i << ", make your board! How many ships would you like to make?\n";
    std::cin>>ships;
    for(int j = 0; j<ships; j++)
    {//i need to make while for making correct row, column coordinates
      std::cout<<"Enter the coordinates of your 1x" << j+1 << " ship.\nRow: ";
      if(i == 1)
      {
        std::cin>>row1;
      }
      else
      {
        std::cin>>row2;
      }
      if(row1>9 || row1<1 || row2>9 || row2<1)
      {
        //need to make while loops for conditions
      }
      std::cout<<"Column: ";
      if(i == 1)
      {
        std::cin>>col1;
        if(col1>9 || col1<1)
        {
          //while loop needed instead of lone if
        }
        player1_grid.addShip(row1, col1, j+1);//assuming there will be a parameter for length of ship
      }
      else
      {
        do
        {
          std::cout<<"Please type in column within 9x10 bounds of board: ";
          std::cin>>col2;
          player2_grid.addShip(row2, col2, j+1);
        }while(col2>9 || col2<1);
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
  else
  {
    //throw exception
  }
}
