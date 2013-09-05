/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Hare.h
 *
 *  This is the Hare class (.h) file, it is the header of the
 *  hare.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HARE_H
#define HARE_H

#include <iostream>
#include <string>
using namespace std;

#include "random.h"
#include "Mountain.h"

class Hare{

public:
        Hare();//default constructor
        Hare(int x, int y, int energy);

        int getX();
        int getY();
        int getEnergy();
        void setX(int newX);
        void setY(int newY);
        void setCoordinates(int newX, int newY);
        void setEnergy(int energy);
        //void sleep();
        void bigHop();
        void bigSlip();
        void smallHop();
        void smallSlip();
        void hareMove(Mountain &cliff);
	void outOfBoundsCheck(Mountain &cliff);

private:
        int x, y, energy;

};

#endif

