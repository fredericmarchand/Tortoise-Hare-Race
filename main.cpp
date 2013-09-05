/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  main.cpp
 *
 *  This file is used to simply start and end the program
 *  everything is done using classes
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "main.h"

int main(){	
	initscr();
	while(true){
		int i;
		Race newRace(0);
		i = newRace.setupRace();
		if(i != 1)
			break;
	}
	endwin();
	return(0);
}



