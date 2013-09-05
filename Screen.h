/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Screen.h
 *
 *  This is the Screen class (.h) file it contains all the 
 *  function prototypes for Screen.cpp
 *  
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SCREEN_H
#define SCREEN_H

#include "Hare.h"
#include "Mountain.h"
#include "Tortoise.h"
#include "Snack.h"
#include "random.h"
#include <iostream>
#include <ncurses.h>
using namespace std;


class Screen{

public:
	Screen();//Default constructor
	Screen(int, int);

	void startScreen();
	int windowX();
	int windowY();
	void update(Tortoise&, Hare&, Mountain&, Snack*, int, int*);
	void printSnacks(Snack*, int, int*);
	int victoryScreenAndRematch(int, Tortoise&, Hare&, Mountain&);
	
private:
	int xSize, ySize;

};

#endif
