/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Snack.cpp
 *
 *  This is the Snack class (.cpp) file it is part of the 
 *  model for the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Snack.h"

Snack::Snack(){
	x=0;
	y=0;
}

Snack::Snack(int a, int b){
	x = a;
	y = b;
}

//get function for a snack's x coordinate
int Snack::getX(){
	return x;
}
	
//get function for a snacks y coordinate
int Snack::getY(){
	return y;
}

//set function for the snacks x and y coordinates	
void Snack::setCoordinates(int newX, int newY){
	x = newX;
	y = newY;
}


