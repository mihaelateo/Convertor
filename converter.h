#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define MAX_ARRAY_LENGTH 20

struct vector
{
	double values[MAX_ARRAY_LENGTH];
};

struct node
{
	double val;
	int index;
	node * next;
	node * prev;
};

struct list
{
	node * first;
	node *last; 
};


//temperature
#define CtoK 273,15;

//length
#define oneMeterIninches 39.3701;
#define oneMeterInFeet 3.28084;
#define oneMeterInMiles 0.000621371;
#define oneMeterInYards 1.09361;
#define oneMeterInNauticalMiles 0.000539957;

//area
#define oneSquareMeterInSquareInches 1550;
#define oneSquareMeterInSquareFeet 10.7639;
#define oneSquareKilometerInSquareMiles 0.386102;
#define oneSquareMeterInHectares 0.0001;

//mass
#define oneLbinGrams 453.592;
#define oneOzinGrams 28.3495;
