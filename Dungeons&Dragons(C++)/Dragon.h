#ifndef DRAGON_H
#define DRAGON_H

#include "Player.h"

class Dragon : public Player
{
  public:
    Dragon(bool=true,int=0,int=0,int=0,int=0,int=0,bool=false,char='N');
    ~Dragon();
				void fireOn();
				void fireOff();
				bool getFire();

  private:
    bool fireBreath;

};

#endif

