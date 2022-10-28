#ifndef SETTING_H8
#define SETTING_H
#include <iostream>
#include "Player.h"
#include "Dragon.h"
#include "Wizard.h"
#include <list>


template <class T>
class Setting
{
  public:
    Setting();
    ~Setting();
    void initialize();
    void display();
    //enables cascading;
    Setting<T>& insert(Player*);
    Setting<T>& insert(int,int,char);
    Setting<T>& update(list <Player*>&,Dragon*&);
    Player* getHitter(list <Player*>,char,int,int);

  private:
    T** coordinates;
};

template <class T>
Setting<T>::Setting()
{
 coordinates = new T*[8];
 for (int i = 0; i < 8; i++){
  coordinates[i] = new T[28];
 }
}

template <class T>
Setting<T>::~Setting()
{
 for (int i = 0; i < 8; i++){
  delete coordinates[i];
 }
 delete coordinates;
}

template <class T>
void Setting<T>::initialize()
{
for(int y=0;y<7;y++){
 for(int x=0;x<28;x++){
   if(x==27 && y==3){
    coordinates[y][x]='*';
   }else if((y>1 && y<5) && x==26){
    coordinates[y][x]='=';
   }else if(x==0 || x==26){
    coordinates[y][x]='|';
   }else if((y==0 && (x>0 && x<27)) || (y==6 && (x>0 && x<27))){
	  coordinates[y][x]='-';
   }else{
    coordinates[y][x]=' ';
   }
  }
 }
}

//inserts player into map
template <class T>
Setting<T>& Setting<T>::insert(Player* p)
{
 if(coordinates[p->getY()][p->getX()]==' '){
   coordinates[p->getY()][p->getX()]=p->getId();
   return *this;
 }else{
   return *this;
 }
}

//inserts char into map given x,y coordinates
template <class T>
Setting<T>& Setting<T>::insert(int x, int y,char c)
{
 if(coordinates[y][x]==' '){
   coordinates[y][x]=c;
   return *this;
 }else{
   return *this;
 }
}

//updates current map given a list of players
template <class T>
Setting<T>& Setting<T>::update(list <Player*>& p,Dragon*& dragon)
{
 Player* temp;
 char tChar;
 int damage;
 list <Player*> :: iterator it; 
 for(it=p.begin();it!=p.end();it++){
   tChar=coordinates[(*it)->getY()][(*it)->getX()];
   temp=getHitter(p,tChar,(*it)->getX(),(*it)->getY());
   //if current position is empty
   if(tChar==' '){
     coordinates[(*it)->getY()][(*it)->getX()]=(*it)->getId();
   }else{
     //checking for collision cases=
     //friendly collision
     if((tChar=='T' && (*it)->getId()=='H') || (tChar=='T' && (*it)->getId()=='H')){
       (*it)->skipCollision(1);

     //Dragons-fighter collisions
     }else if ((tChar=='d' || tChar=='b' || tChar=='p') && (*it)->getId()=='D'){
       (*it)->skipCollision(2);
     }else if (tChar=='D' && ((*it)->getId()=='d' || (*it)->getId()=='b' || (*it)->getId()=='p')){
       (*it)->skipCollision(3);

     //Dragon-Hero collisions
     }else if (tChar=='D' && ((*it)->getId()=='H' ||  (*it)->getId()=='T')){
       (*it)->collision(4,temp);
     }else if ((tChar=='H' || tChar=='T') && (*it)->getId()=='D'){
       (*it)->collision(5,temp);

		   //fighter-Hero  collisions
     }else if ((tChar=='H' || tChar=='T') && ((*it)->getId()=='d' || (*it)->getId()=='b' || (*it)->getId()=='p')){
       (*it)->collision(6,temp);
       if((*it)->getHealth() < 1){
		       //removes and deallocates dead enemy and enemy that has left the bound from players list
         p.remove((*it));
         delete temp;
       }

				//fighter-Hero  collisions contd
		   }else if ((tChar=='d' || tChar=='b'|| tChar=='p') && ((*it)->getId()=='H' || (*it)->getId()=='T')){
		      (*it)->collision(7,temp);
		      if(temp->getHealth() < 1){
		       //removes and deallocates dead enemy and enemy that has left the bound from players list
					    p.remove(temp);
         delete temp;
		      }
		   }
	  }

}
}


//displays map
template <class T>
void Setting<T>::display()
{
 for(int y=0;y<8;y++){
  for(int x=0;x<28;x++){
    cout << coordinates[y][x];
   }
  cout << endl;
 }
}


//function returns player occupying current players desired location (colliding player)
template <class T>
Player* Setting<T>::getHitter(list <Player*> p ,char id,int x,int y)
{
 list <Player*> :: iterator it2; 
 for(it2=p.begin();it2!=p.end();it2++){
  if ((*it2)->getId()==id && (*it2)->getX()==x && (*it2)->getY()==y){
   return (*it2);
  }
 }
}

#endif





