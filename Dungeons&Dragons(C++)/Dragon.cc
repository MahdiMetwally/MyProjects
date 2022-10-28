#include <iostream>
using namespace std;

#include <string>
#include "Dragon.h"


Dragon::Dragon(bool i,int h,int s,int a,int x,int y,bool f,char c) : fireBreath(f),Player(i,h,s,a,x,y,c)
{
}

Dragon::~Dragon()
{
}
   
void Dragon::fireOn(){
 fireBreath=true;
}

void Dragon::fireOff(){
 fireBreath=false;
}

bool Dragon::getFire(){return fireBreath;}
