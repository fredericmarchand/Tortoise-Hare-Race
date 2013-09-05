/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Mountain.cpp
 *
 *  This is the Mountain class (.cpp) file, it is part of the 
 *  model, it keeps track of the dimensions of the cliffs insufficient
 *  logic
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Mountain.h"


Mountain::Mountain(){
	width = 0;
	height = 0;
}

Mountain::Mountain(int a, int b){
	width = a;
	height = b;
}

//get function for the mountains width
int Mountain::getWidth(){
	return width;
}

//get function for the mountains height
int Mountain::getHeight(){
	return height;
}



