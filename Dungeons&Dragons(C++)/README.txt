program and revision authors: Mahdi Metwally.

purpose:
-The purpose of this game is for two heroes (Timmy & Harold) to randomley travel through a dark hollow to secure an emerald.
Timmy and Harold must go up against randomly generated and randomly moving obsticles including different types of fighters and a drangon. If Timmy or Harold meet a wizard
,They can be given potions to to boost there health, strength, and armour. Harold and Timmy must also avoid
dying due to a randomley occuring dragon fire breath. The game takes place on a 2D grid and each in-game character is represented by a letter(see below).
T=Timmy
H=Harold
D=Dragon
W=Wizard
Fighter=(d,b,or,p)


source/header/data files:

Header Files:
-Control.h
-Dragon.h
-Fighter.h
-Game.h
-Hero.h
-List.h
-Player.h
-Potion.h
-Setting.h
-Wizard.h


Source Files
-Control.cc
-Dragon.cc
-Fighter.cc
-Game.cc
-Hero.cc
-List.cc
-main.cc
-Player.cc
-Potion.cc
-random.cc
-Wizard.cc
-random.cc

Data Files:
-Makefile

compilation and launching instructions:
-extract the game.tar file by entering "tar -xvf game.tar into the command 
prompt where the game.tar file is available in the current directory.

-once the game.tar file is untar'd enter "make" into the command prompt given all the provided game files are in the current directory.

-enter "./E1" into the command prompt to execute the program.

-follow on-screen intructions to properly use the program.

-to test for memory leaks enter "valgrind --leak-check=yes ./E1".


Innovative Features:

-Fire Breath:
 In the game, the dragon located at the cave is capable of breathing fire that reaches
 the entire width of the game map. the only players that this can kill includes the heroes,
 Timmy and Harold. The heroes can block one another and sacrifice themselves to the fire, sparing
 the hero that is standing directly behind the unfortunate hero. If the heroes are standing at the exact
 same position, then the fire will instantly  kill both heroes and the game will end. Note: there is a
 30 percent chance of the dragon breathing fire at each iteration.
 
-Wizards with potions:
 Wizards can be found in the death Hollow and have a 20 percent chance of spawning. If a hero 
 encounters a wizard, the wizard will provide the hero with a potion that has random health, strength, 
 and armour enhancements. The wizard will only provide the heroes with potions and is immune to 
 fire breath due to his fire-resistant cloak and invisible to wandering enemies because of his
 disguise spell. The wizards store Potion objects in a linked list.





