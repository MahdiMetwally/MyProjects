#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
  public:
    Fighter(bool=true,int=0,int=0,int=0,int=0,int=0,int=0,char='N');
    ~Fighter();
    int getKills();

  private:
    int kills;
   
};

#endif
