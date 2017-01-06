#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define CtoK 273,15
#define MAX_ARRAY_LENGTH 20

struct vector
{
	unsigned int length;
	double values[MAX_ARRAY_LENGTH];
};
