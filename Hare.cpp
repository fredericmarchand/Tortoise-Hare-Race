/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Hare.cpp
 *
 *  This is the Hare class (.cpp) file, it is part of the
 *  model of the program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Hare.h"

Hare::Hare(){
	x = 0;
	y = 0;
	energy = 0;
}

Hare::Hare(int a, int b, int c){
	x = a;
	y = b;
	energy = c;
}

//get function for the x coordinate of the hare
int Hare::getX(){
	return x;
}
	
//get function for the y coordinate of the hare
int Hare::getY(){
	return y;
}
	
//get function for the energy of the hare
int Hare::getEnergy(){
	return energy;
}
	
//set function for the x coordinate of the hare
void Hare::setX(int newX){
	x = newX;	
}
	
//set function for the y coordinate of the hare
void Hare::setY(int newY){
	y = newY;
}

//set function for both coordinates of the hare
void Hare::setCoordinates(int newX, int newY){
	x = newX;
	y = newY;
}
	
//set function for the energy of the hare
void Hare::setEnergy(int en){
	energy = en;
}
	
/*void Hare::sleep(){
	
}*/
	
//this function makes the hare perform a bighop and modifies its postion accordingly
void Hare::bigHop(){
	y -= 9;
	energy-=3;
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

//this function makes the hare perform a bigslip and modifies its postion accordingly
void Hare::bigSlip(){
	y+=12;
}
	
//this function makes the hare perform a smallhop and modifies its postion accordingly
void Hare::smallHop(){
	y--;
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
	
//this function makes the hare perform a smallslip and modifies its postion accordingly
void Hare::smallSlip(){
	y+=2;
}
	
//this function uses the random number generator to decide which of the moves above the hare will perform
void Hare::hareMove(Mountain &cliff){
	if(energy>0){
		int i = randomInt(100);
		if(i<20){//twenty percent chance of getting sleep
			//hare->sleep();  NOTHING HAPPENS
		}
		else if(i>=20 && i<40){//twenty percent chance of getting big hop
			bigHop();
		}
		else if(i>=40 && i<50){//ten percent chance of getting big slip
			bigSlip();
		}
		else if(i>=50 && i<80){//thirty percent chance of getting small hop
			smallHop();
		}
		else{//twenty percent chance of getting small slip
			smallSlip();
		}
	}
	else
		energy = 10;
	
	outOfBoundsCheck(cliff);
}

//this function checks and fixes the position of the hare in the case that it would go out of bounds
void Hare::outOfBoundsCheck(Mountain &cliff){
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
