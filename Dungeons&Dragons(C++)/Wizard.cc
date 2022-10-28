#include <iostream>
using namespace std;

#include <string>
#include "Wizard.h"
#include "Potion.h"
#include "Hero.h"


Wizard::Wizard(bool i,int h,int s,int a,int x,int y,char c) : Player(i,h,s,a,x,y,c)
{
}

Wizard::~Wizard()
{
}

void Wizard::addPotion(Potion* p)
{
 potions.add(p);
}

void Wizard::wizCollision(Hero* hero)
{
 Potion* p;
 if(potions.empty()==false){
   //pop first potion from wizard and have hero drink iy
   potions.popFirst(p);
   hero->drinkPotion(p);
  }
}




