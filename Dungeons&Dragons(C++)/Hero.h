#ifndef HERO_H
#define HERO_H

#include "Player.h"
#include "Potion.h"

class Hero : public Player
{
  public:
    Hero(bool=true,int=0,int=0,int=0,int=0,int=0,char='N');
    ~Hero();
    bool isAlive();
    void dies();
    void drinkPotion(Potion*);

  private:
    int armour;
   
};

#endif
