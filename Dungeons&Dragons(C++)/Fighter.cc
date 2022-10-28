#include <iostream>
using namespace std;

#include <string>
#include "Fighter.h"


Fighter::Fighter(bool i,int h,int s,int a,int k,int x,int y,char c) : kills(k), Player(i,h,s,a,x,y,c)
{
}

Fighter::~Fighter()
{
}

int Fighter::getKills(){return kills;}


