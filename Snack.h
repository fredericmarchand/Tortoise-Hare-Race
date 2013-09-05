/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Snack.h
 *
 *  This is the Snack class (.h) file it contains all the 
 *  function prototypes and attributes for Snack.cpp
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef SNACK_H
#define SNACK_H

#include <iostream>
using namespace std;


class Snack{

public:
	Snack();//Default constructor
	Snack(int a, int b);

	int getY();
	int getX();
	void setCoordinates(int newX, int newY);

private:
	int x, y;
};

#endif
