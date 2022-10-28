#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"
#include "List.h"
#include "Hero.h"

class Wizard : public Player
{
  public:
     Wizard(bool=true,int=0,int=0,int=0,int=0,int=0,char='W');
    ~Wizard();
     void addPotion(Potion*);
     void wizCollision(Hero*);

  private:
    List potions;
   
};

#endif
