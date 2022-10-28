#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h> 
#include <time.h> 
#include "Potion.h"

Potion::Potion()
{
 hBoost= 1+ random(10);
 sBoost= 1+ random(10);
 aBoost= 1+ random(10);
}

Potion::~Potion()
{
}

int Potion::getID(){return id;}

int Potion::getHBoost(){return hBoost;}

int Potion::getSBoost(){return sBoost;}

int Potion::getABoost(){return aBoost;}

int Potion::random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}



