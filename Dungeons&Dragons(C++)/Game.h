#ifndef GAME_H
#define GAME_H
using namespace std; 
#include <iterator>
#include <list>
#include "Setting.h"
#include "Wizard.h"
#include "Player.h"


class Game
{
  public:
    Game();
    ~Game();
    void displayGame();
    void start();
    void spawnFighter(Player*&);
    void spawnWizard(Wizard*&);

  private:
    Setting <char> dHollow;
    list <Player*> players;
};

#endif
