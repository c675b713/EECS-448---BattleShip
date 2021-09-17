/*
*   File: Setup.h
*   Author: Zachary Andrews
*   Date: 09/8/2021
*   Brief: Header for interface to users
*/

#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include "ShipMap.h"
#include <stdexcept>

class SetUp
{
  public:
  //sets up 9x10 boards via ship map methods; welcomes user
  SetUp();
  /*
  *pre: ship maps set up; need to be altered in some way
  *params: player number
  *post: a ShipMap object is returned
  */
  ShipMap returnMap(int player);
  
  private:
  ShipMap player1_grid;//two ShipMap objects
  ShipMap player2_grid;
};

#endif