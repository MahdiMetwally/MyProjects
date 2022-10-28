#include <iostream>
#include <typeinfo>

using namespace std;

#include <string>
#include "Player.h"
#include "Hero.h"


Player::Player(bool i,int h,int s,int a,int x,int y,char c) : alive(i),health(h),strength(s),armour(a),xCoordinate(x),yCoordinate(y),id(c)
{
}

Player::~Player()
{
}

int Player::getArmour(){return armour;}

int Player::getX(){return xCoordinate;}

int Player::getY(){return yCoordinate;}

int Player::getHealth(){return health;}

int Player::getStrength(){return strength;}

char Player::getId(){return id;}


int Player::random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}

void Player::move(bool fire,int yFire)
{
 //Movement for Heros
 if(id=='H' || id=='T'){
				if(xCoordinate!=24){
				  xCoordinate++;
				  int ran = random(2);
				  //randomly moves hero one position up or down
				  yMotion(this);
				}else{
				 //reached end of hollow must move up or down
				  if(yCoordinate < 2){
				   yCoordinate++;
				  }else if(yCoordinate > 4){
				   yCoordinate--;
				  }
  }
  if(yFire==yCoordinate && fire==true){
    this->health=0;
  }
 //Movement for enemies
 }else if(id=='d' || id=='b' || id=='p'){
   if(xCoordinate!=1){
    xCoordinate--;
    //randomly moves enemy one position up or down
    yMotion(this);
   }else{
   health=0;//sentinel that results in removal of enemy
 }
 //Movement for Dragon
 }else if(id=='D'){
  if(strength==50){
    if(yCoordinate==2){
      strength=51;
      yCoordinate++;
    }else{
      yCoordinate--;
    }
  }else{
     if(yCoordinate==4){
       strength=50;
       yCoordinate--;
     }else{
       yCoordinate++;
     }
  }
 }else{
  //wizards completely random movement
  xCoordinate= 1+random(24);
  yCoordinate= 1+random(5);
 } 
}

//functon that is call when collision ensues that does not have any effect(usd to later add functionality)
void Player::skipCollision(int hitId)
{
}


void Player::collision(int hitId,Player* attacker)
{
	if(hitId==4){
		 health=0;//hero health
	}else if(hitId==5){
		 attacker->health=0;//hero health
	}else if(hitId==6){
	//caller is enemy
		 health -= attacker->getStrength(); //enemy health
		 attacker->health -= (strength - attacker->getArmour()); //hero health
	}else if(hitId==7){
   //caller is hero
 	 health -= (attacker->getStrength() - armour); //hero health
   attacker->health -= strength; //enemy health
	}
}

void Player::yMotion(Player* p)
{
	int ran2 = random(2);
	if(ran2==0){
  //check if new position is out of bounds
		if(yCoordinate<5){
		  p->yCoordinate++;
	 }else{
		  p->yCoordinate--;
	 }
	}else if(ran2==1){
   //check if new position is out of bounds
		 if(yCoordinate>1){
		   p->yCoordinate--;
		 }else{
	 	  p->yCoordinate++;
		 }
	}
}

void Player::display()
{
 cout << "X: " << xCoordinate << " Y: " << yCoordinate << " health: " << health  << " strength: " << strength<< " armour: " << armour  << endl;
}


