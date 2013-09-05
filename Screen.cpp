/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Screen.cpp
 *
 *  This is the Screen class (.cpp) file it contains all the 
 *  functions having something to do with the view of the
 *  program.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Screen.h"

Screen::Screen(int a, int b){
	xSize = a;
	ySize = b;
}

//this function prints out the screen before the race starts allowing the user to start the race when he is ready
void Screen::startScreen(){
	move(windowY()/2, (windowX()/2)-17);
	printw("Press any button to start the race");
	refresh();
	getch();
}

//this function determines the size of the x-axis of the screen
int Screen::windowX(){
	int xDim, yDim;
	getmaxyx(stdscr, yDim, xDim);
	return xDim;
}

//this function determines the size of the y-axis
int Screen::windowY(){
	int xDim, yDim;
	getmaxyx(stdscr, yDim, xDim);
	return yDim;
}

//calling this function updates the screen after any of the racers have made a movement
void Screen::update(Tortoise &tort, Hare &hare, Mountain &cliff, Snack* snacks, int total, int* remSnacks){
	clear();
	printSnacks(snacks, total, remSnacks);	

	move(0,0);
	printw("Tortoise energy: %d", tort.getEnergy());
	move(0, cliff.getWidth()-15);
	printw("Hare energy: %d", hare.getEnergy()); 
	move(1, (cliff.getWidth()/2)-10);
	printw("____Mountain Top____");
	move(tort.getY(), tort.getX());
	printw("T");
	move(hare.getY(), hare.getX());
	printw("H");
	move(cliff.getHeight()-1, (cliff.getWidth()/2)-12);
	printw("____Mountain Bottom____");
	refresh();
	usleep(1000000);
}

//this function goes through and array of snacks and prints them out according to they're position on the screen
void Screen::printSnacks(Snack *snacks, int total, int *remSnacks){
	int i;
	for(i=0; i<total; i++){
		if(remSnacks[i]==1){
			move(snacks[i].getY(), snacks[i].getX());
			printw("*");
		}
	}
}

//this function prints out the screen at the end of the game asking the user if he wants the race to restart
int Screen::victoryScreenAndRematch(int a, Tortoise &tort, Hare &hare, Mountain &cliff){
	clear();
	char c;
	move(0,0);
	printw("Tortoise energy: %d", tort.getEnergy());
	move(0, cliff.getWidth()-15);
	printw("Hare energy: %d", hare.getEnergy()); 
	move(1, (cliff.getWidth()/2)-10);
	printw("____Mountain Top____");
	move(tort.getY(), tort.getX());
	printw("T");
	move(hare.getY(), hare.getX());
	printw("H");
	move(cliff.getHeight()-1, (cliff.getWidth()/2)-12);
	printw("____Mountain Bottom____");

	move((windowY()/2)-1, (windowX()/2)-17);
	if(a == 1)
		printw("The Hare won the race!");
	else if(a == 2)
		printw("The Tortoise won the race!");
	
	move((windowY()/2)+1, (windowX()/2)-17);
		printw("Press (r) to begin another race");
	move((windowY()/2)+2, (windowX()/2)-17);
		printw("Press anything else to quit");
	refresh();

	c = getch();
	if(c == 'r')
		return(1);
	return(0);
}

