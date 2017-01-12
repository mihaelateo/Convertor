#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <cwchar>

using namespace std;

#define MAX_ARRAY_LENGTH 20

struct vector
{
	int length;
	double values[MAX_ARRAY_LENGTH];
};

struct matrix
{
	double values[MAX_ARRAY_LENGTH][MAX_ARRAY_LENGTH];
};



//temperature
#define CtoK 273,15

//length
#define oneMeterIninches 39.3701
#define oneMeterInFeet 3.28084
#define oneMeterInMiles 0.000621371
#define oneMeterInYards 1.09361
#define oneMeterInNauticalMiles 0.000539957

//area
#define oneSquareMeterInSquareInches 1550
#define oneSquareMeterInSquareFeet 10.7639
#define oneSquareKilometerInSquareMiles 0.386102
#define oneSquareMeterInHectares 0.0001

//mass
#define KgToPounds 2.20462
#define KgToOunce 35.274

//time
#define largeUnits 6
#define middleUnits 4
#define smallUnits 4

//volume
#define LtoUSgal 0.264172
#define LtoUKgal 0.219969
#define LtoCubicFt 0.0353147
#define LtoCubicIn 61.0237
#define LtoCubicYd 0.00130795

//energy
#define kJToJ 1000
#define gCToJ 4.184
#define kCToJ 4.184e+3
#define GcalToJ 4,184e+9
#define WperhToJ 3600
#define kWperhToJ 3600000
#define BTUToJ 1055.06
#define USTToJ 1.055e+8
#define FTLBToJ 1.35582


