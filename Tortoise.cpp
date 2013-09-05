/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Tortoise.cpp
 *
 *  This is the Tortoise class (.cpp) file it is part of the 
 *  model for the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Tortoise.h"

Tortoise::Tortoise(){
	x = 0;
	y = 0;
	energy = 0;
}


Tortoise::Tortoise(int a, int b, int c){
	x = a;
	y = b;
	energy = c;
}
	
//get function for the x coordinate of the tortoise
int Tortoise::getX(){
	return x;
}

//get function for the y coordinate of the tortoise
int Tortoise::getY(){
	return y;
}

//get function for the energy of the tortoise
int Tortoise::getEnergy(){
	return energy;
}

//set function for the x coordinate of the tortoise
void Tortoise::setX(int newX){
	x = newX;	
}

//set function for the y coordinate of the tortoise
void Tortoise::setY(int newY){
	y = newY;
}

//set function for both coordinates of the tortoise
void Tortoise::setCoordinates(int newX, int newY){
	x = newX;
	y = newY;
}

//set function for the energy of the tortoise
void Tortoise::setEnergy(int en){
	energy = en;
}

//this function makes the tortoise perform a fastplod and modifies its position accordingly
void Tortoise::fastPlod(){
	y -= 3;
	energy-=2;
	int rand = randomInt(100);
	if(rand<33){
		x--;	
	}
	else if(rand>=33 && rand<66){
		//x stays the same
	}
	else{
		x++;
	}

	if(energy<0)
		energy = 0;
}

//this function makes the tortoise perform a slip and modifies its position accordingly
void Tortoise::slip(){
	y+=6;
}

//this function makes the tortoise perform a slowplod and modifies its position accordingly
void Tortoise::slowPlod(){
	y -= 1;
	energy--;
	int rand = randomInt(100);
	if(rand<33){
		x--;	
	}
	else if(rand>=33 && rand<66){
		//x stays the same
	}
	else{
		x++;
	}

	if(energy<0)
		energy = 0;
}

//this function uses the random number generator to determine which of the moves above that the tortoise will perform
void Tortoise::tortoiseMove(Mountain &cliff){
	if(energy>0){
		int i = randomInt(100);
		if(i<50){//fifty percent chance of getting fast plod
			fastPlod();
		}
		else if(i>=50 && i<70){//twenty percent chance of getting slip
			slip();
		}
		else{//thirty percent chance of getting slow plod
			slowPlod();	
		}
	}
	else
		energy = 10;

	outOfBoundsCheck(cliff);
}

//this function checks and fixes the coordinates of the tortoise in the case that it would be out of bounds
void Tortoise::outOfBoundsCheck(Mountain &cliff){
	if(x<1)
		x = 1;
	if(x>cliff.getWidth()-1){
		x = cliff.getWidth()-1;
	}
	if(y>cliff.getHeight()-1){
		y = cliff.getHeight()-1;
	}
	if(y<=1){
		y = 1;
	}
}



