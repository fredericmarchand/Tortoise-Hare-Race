/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Race.h
 *
 *  This is the Race class (.h) file, it is basically the
 *  controller of the program
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef RACE_H
#define RACE_H

#include "Hare.h"
#include "Tortoise.h"
#include "Mountain.h"
#include "Snack.h"
#include "Screen.h"
#include "random.h"
#include <ncurses.h>
#include <math.h>
using namespace std;


class Race{

public:
	Race();
	Race(int = 0);
	
	int setupRace();
	void checkCollision(Tortoise &tort, Hare &hare, Snack *snacks, int total, int *remSnacks);
	int checkVictory(Tortoise &tort, Hare &hare);


private:
	int a;

};

#endif
