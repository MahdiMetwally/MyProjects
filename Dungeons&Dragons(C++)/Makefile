E1:	main.o Control.o Player.o Game.o Hero.o Fighter.o Dragon.o Wizard.o List.o Potion.o
	g++ -o E1 main.o Control.o Player.o Game.o Hero.o Fighter.o Dragon.o Wizard.o List.o Potion.o

main.o:	main.cc
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Player.o: Player.cc Player.h
	g++ -c Player.cc

Game.o: Game.cc Game.h 
	g++ -c Game.cc

Hero.o: Hero.cc Hero.h
	g++ -c Hero.cc

Fighter.o: Fighter.cc Fighter.h
	g++ -c Fighter.cc

Dragon.o: Dragon.cc Dragon.h
	g++ -c Dragon.cc

Wizard.o: Wizard.cc Wizard.h
	g++ -c Wizard.cc

List.o: List.cc List.h
	g++ -c List.cc

Potion.o: Potion.cc Potion.h
	g++ -c Potion.cc



clean:
	rm -f *.o E1

