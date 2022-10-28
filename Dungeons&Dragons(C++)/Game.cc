#include <iostream>
using namespace std;

#include <string>
#include "Game.h"
#include "Player.h"
#include "Fighter.h"
#include "Hero.h"
#include "Dragon.h"
#include "Wizard.h"  
#include "random.cc" 
 
Game::Game(){ dHollow.initialize();}

Game::~Game()
{
 list <Player*> :: iterator it; 
	for(it=players.begin();it!=players.end();it++){
   //wizards are dealloacted seeperatley
   if((*it)->getId()!='W'){
     delete (*it);
   }
 }
}

void Game::start()
{
 //final message to user
 string finalMessage="All heros have died";
	Player* newFighter;
	Wizard* newWizard;
 Wizard* wizards[40];
 int numWizards=0;
	int chance;
	int herosDead=0;
	int deathToll=0;
	int deathY1=0;
	int deathX1=0;
	int deathY2=0;
	int deathX2=0;
	//get random int between 1 and 5 inclusive
	srand( (unsigned)time( NULL ) );
	int ran1 = 1+random(5);
	int ran2 = 1+random(5);

	//ensures harold and timmy have unique starting Y coordinates
	while(ran1==ran2){
		ran2 = 1+random(5);
	}

 //create pointers to hero and dragon objects(timmy,harold,and dragon)
	Hero* harold = new Hero(true,15,5,1,1,ran1,'H');
	Hero* timmy = new Hero(true,15,3,3,1,ran2,'T');
	Dragon* dragon = new Dragon(true,100,100,100,24,3,false,'D');
 //insert pointers to timmy,harold, and dragon into STL list of player pointers
	players.push_front(harold);
	players.push_front(timmy);
	players.push_front(dragon);
 //update the empty map so it contains the initial players 
	dHollow.update(players,dragon);
 //display first map frame
	dHollow.display();

 //real game begins
	while(deathToll<2){
   dragon->fireOff();
		 chance = random(10);
   if(chance==3){
     //10 percent chance new wizard to appearS
		   spawnWizard(newWizard);
     //new wizard is added to local array of wizard pointers
     wizards[numWizards]=newWizard;
     numWizards++;
     //new wizard is added to STL list of player pointers
		   players.push_front(newWizard);
		  }
   if(chance<3){
     //30 percent chance fire breath
     dragon->fireOn();
		  }
		 if(chance<6){
     //60 percent chance a fighter will be spawned
		   spawnFighter(newFighter);
     //new enemy is added to STL list of player pointers
		   players.push_front(newFighter);
		  }

				//will call move() function on all players in STL list of player pointers
				list <Player*> :: iterator it; 
				for(it=players.begin();it!=players.end();it++){
      //polymorphical function that sets next position of player
				  (*it)->move(dragon->getFire(),dragon->getY());
     }
				//display player data for all players (for testing and debugging)
				for(it=players.begin();it!=players.end();it++){
				  //(*it)->display();
     }

    //loops to check if a hero has colided with a wizard
    for(int i=0;i<numWizards;i++){
      if(wizards[i]->getX()==timmy->getX() && wizards[i]->getY()==timmy->getY() && timmy->isAlive()){
        wizards[i]->wizCollision(timmy);
      }else if(wizards[i]->getX()==harold->getX() && wizards[i]->getY()==harold->getY()&& harold->isAlive()){
        wizards[i]->wizCollision(harold);
      }
    }


   //resets game map
			dHollow.initialize();
   //places '+' mark on map for remainder of the game
			if(deathX1>0 && deathY1>0 && deathX2>0 && deathY2>0){
				dHollow.insert(deathX1,deathY1,'+');
				dHollow.insert(deathX2,deathY2,'+');
			}else if(deathX1>0 && deathY1>0){
				dHollow.insert(deathX1,deathY1,'+');
			}else if(deathX2>0 && deathY2>0){
				dHollow.insert(deathX2,deathY2,'+');
			}

   //places all players in the players list into the map
			dHollow.update(players,dragon);
   //draws fire onto the map
    if(dragon->getFire()){
      for(int x=0;x<24;x++){
        dHollow.insert(x,dragon->getY(),'~');
      } 
    }

   //remove harold and/or timmy if they are be dead
			if(harold->getHealth()<1 && timmy->getHealth()<1 && harold->isAlive() && timmy->isAlive()){
				 deathY1=timmy->getY();
				 deathX1=timmy->getX();
				 deathY2=harold->getY();
				 deathX2=harold->getX();
				 harold->dies();
				 timmy->dies();
				 deathToll=2;
     dHollow.display();
				 break;
			}else if(harold->getHealth()<1 && harold->isAlive()){
				 deathY2=harold->getY();
				 deathX2=harold->getX();
				 harold->dies();
				 deathToll++;
				 cout << "Harold died" << endl;
			}else if(timmy->getHealth()<1 && timmy->isAlive()){
				 deathY1=timmy->getY();
				 deathX1=timmy->getX();
				 timmy->dies();
				 deathToll++;
				 cout << "Timmy died" << endl;
			}
    //display game map
			 dHollow.display();

    //ends game if timmy or harold secure the emerald
 			if(timmy->getX()==24 && (timmy->getY()==2 || timmy->getY()==3  || timmy->getY()==4) && timmy->isAlive() ){
		   finalMessage="Timmy secured the emerald!";
			  break;
   }else if(harold->getX()==24 && (harold->getY()==2 || harold->getY()==3  || harold->getY()==4) && harold->isAlive()){
     finalMessage="Harold secured the emerald!";
     break;
   }
 }
    cout << finalMessage << endl;
    //deallocation of all wizards
    for(int i=0;i<numWizards;i++){
        delete wizards[i];
    }
}

//function that randomly creates enemy with random strength value
void Game::spawnFighter(Player*& f)
{
	int ran3 = random(3);
	int ranHeight = 1+random(5);
 //equal prbability of creating dorc,borc,and porc
	if(ran3==0){
		Fighter* dorc = new Fighter(true,5,6+random(3),0,0,24,ranHeight,'d');
		f=dorc; 
	}else if(ran3==1){
	  Fighter* borc = new Fighter(true,5,8+random(4),0,0,24,ranHeight,'b');
	 	f=borc;
	}else{
	 	Fighter* porc = new Fighter(true,5,4+random(2),0,0,24,ranHeight,'p');
	 	f= porc;
	}
}


//function that randomly creates Wizard with location
void Game::spawnWizard(Wizard*& wiz) 
{
	int ranHeight = 1+random(5);
	int ranWidth = 1+random(24);
	int numPotions = 1+ random(10);//adds 1 to 10 potions to new wizard
	wiz = new Wizard(true,20,15,5,ranWidth,ranHeight,'W');
 for(int i=0;i<numPotions;i++){
   wiz->addPotion(new Potion());
 }
}

//game display function
void Game::displayGame()
{
 //all function does it call the print function of the dHollow Setting
 dHollow.display();
}
