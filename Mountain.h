/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Frederic Marchand
 *  Comp2404 Assignment 1
 *  Mountain.h
 *
 *  This is the Mountain class (.h) file, it is the header of the
 *  Mountain.cpp file which contains its attributes and funtion
 *  prototypes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <iostream>
using namespace std;
#include "random.h"


class Mountain{

public:
	Mountain();//Default constructor
	Mountain(int a, int b);

	int getWidth();
	int getHeight();

private:
	int height, width;	
};

#endif
