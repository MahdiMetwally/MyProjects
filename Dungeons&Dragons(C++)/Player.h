#ifndef PLAYER_H
#define PLAYER_H

class Player
{
  public:
    Player(bool=true,int=0,int=0,int=0,int=0,int=0,char='N');
    ~Player();
    int getX();
    int getY();
    char getId();
    int getHealth();
    int getStrength();
    int getArmour();
    void move(bool,int);
    void collision(int,Player*);
    void skipCollision(int);
    void display();
    int random(int);

  protected:
    bool alive;
    int health;
    int strength;
    int armour;
    int xCoordinate;
    int yCoordinate;
    char id;

  private:
    void yMotion(Player*);
};

#endif
