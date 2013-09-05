/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Tortoise.h
 *
 *  This is the Tortoise class (.h) file it contains all the 
 *  function prototypes and attributes for Tortoise.cpp
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TORTOISE_H
#define TORTOISE_H

#include <iostream>
#include <string>
using namespace std;

#include "random.h"
#include "Mountain.h"

class Tortoise{

public:
	Tortoise();//default constructor
	Tortoise(int x, int y, int energy);
	
	int getX();
	int getY();
	int getEnergy();
	void setX(int newX);
	void setY(int newY);
	void setCoordinates(int newX, int newY);
	void setEnergy(int);
	void fastPlod();
	void slip();
	void slowPlod();
	void tortoiseMove(Mountain &cliff);
	void outOfBoundsCheck(Mountain &cliff);

private:
	int x, y, energy;
};


#endif
