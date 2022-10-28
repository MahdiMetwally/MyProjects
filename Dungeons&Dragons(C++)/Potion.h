#ifndef POTION_H
#define POTION_H

class Potion
{
  public:
    Potion();
    ~Potion();
    int getHBoost();
    int getSBoost();
    int getABoost();
    static int getNextId();
    int getID();
    int random(int);

  private:
    int id;
		int hBoost;
    int sBoost;
    int aBoost;
};

#endif
