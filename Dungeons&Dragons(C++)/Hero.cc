#include <iostream>
using namespace std;

#include <string>
#include "Hero.h"
#include "Potion.h"


Hero::Hero(bool i,int h,int s,int a,int x,int y,char c) : Player(i,h,s,a,x,y,c)
{
}

Hero::~Hero()
{
}

bool Hero::isAlive(){return alive;}

void Hero::dies(){
 alive=false;
 xCoordinate=0;
 yCoordinate=0;
 id=' ';
}

//function that increases heros health,strength,and armour according to given potion
void Hero::drinkPotion(Potion* potion){
	health+= potion->getHBoost();
	strength+=potion->getSBoost();
	armour+=potion->getABoost();
 delete potion;
}

