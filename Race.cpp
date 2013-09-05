/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Race.cpp
 *
 *  This is the Race class (.cpp) file, it is basically the
 *  controller of the program, it checks for collisions
 *  and makes everything happen.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "Race.h"

Race::Race(){
	a = 0;
}

Race::Race(int i){
	a=i;
}

//this function sets up and controls the race 
int Race::setupRace(){
	clear();
	int i;//loop variable
	int victoryCode, rematchCode;
	
	Screen   newScreen(0,0);
	newScreen.startScreen();

	Tortoise newTortoise((newScreen.windowX()/3), (newScreen.windowY()-1), 20);
	Hare	 newHare((newScreen.windowX()*2/3), (newScreen.windowY()-1), 20);
	Mountain newMountain(newScreen.windowX(), newScreen.windowY());

	int totalSnacks = (int)(floor(newMountain.getWidth()*newMountain.getHeight()*15/100));
	Snack snackArray[totalSnacks];
	int   remainingSnacks[totalSnacks];
	Snack newSnack(0,0);
	for(i=0; i<totalSnacks; i++){
		newSnack.setCoordinates(randomInt(2,newMountain.getWidth()-2), randomInt(2,newMountain.getHeight()-2));
		snackArray[i] = newSnack;
		remainingSnacks[i] = 1;
	}
	
	while(1){
		newScreen.update(newTortoise, newHare, newMountain, snackArray, totalSnacks, remainingSnacks);
		victoryCode = checkVictory(newTortoise, newHare);
		if(victoryCode == 1){
			rematchCode = newScreen.victoryScreenAndRematch(victoryCode, newTortoise, newHare, newMountain);
			break;
		}
		newHare.hareMove(newMountain);
		checkCollision(newTortoise, newHare, snackArray, totalSnacks, remainingSnacks);
		
		newScreen.update(newTortoise, newHare, newMountain, snackArray, totalSnacks, remainingSnacks);
		victoryCode = checkVictory(newTortoise, newHare);
		if(victoryCode == 2){
			rematchCode = newScreen.victoryScreenAndRematch(victoryCode, newTortoise, newHare, newMountain);
			break;
		}
		newTortoise.tortoiseMove(newMountain);
		checkCollision(newTortoise, newHare, snackArray, totalSnacks, remainingSnacks);
	}
	return rematchCode;

}

//this function verifies if there has been any collisions in the race (Hare and Tortoise) (Hare and Snack) (Tortoise and Snack)
void Race::checkCollision(Tortoise &tort, Hare &hare, Snack *snacks, int total, int *remSnacks){
	int i;

	if((tort.getX() == hare.getX()) && (tort.getY() == hare.getY())){
		hare.setEnergy(hare.getEnergy()-3);
	}
	
	for(i=0; i<total; i++){
		if(remSnacks[i] == 1){
			if((tort.getX() == snacks[i].getX()) && (tort.getY() == snacks[i].getY())){
				tort.setEnergy(20);
				remSnacks[i] = 0;
			}
			else if((hare.getX() == snacks[i].getX()) && (hare.getY() == snacks[i].getY())){
				hare.setEnergy(20);
				remSnacks[i] = 0;
			}	
		}
	}
}

//this function verifies if one of the runners have reached the top of the cliffs of insufficient logic
int Race::checkVictory(Tortoise &tort, Hare &hare){
	if(hare.getY() == 1){
		return 1;//a 1 is returned if the hare wins
	}
	if(tort.getY() == 1){
		return 2;//a 2 is returned if the tortoise wins
	}
	else
		return 0;// a zero is returned if no one has won yet
}


