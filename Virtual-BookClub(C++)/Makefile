

MT:	main.o Book.o Member.o BookClub.o Rating.o DynArray.o LinkedList.o StatArray.o ClubEntity.o Control.o View.o
	g++ $(OPT) -o MT  main.o Book.o Member.o BookClub.o Rating.o DynArray.o LinkedList.o StatArray.o ClubEntity.o Control.o View.o


main.o.o:	main.cc
	g++ $(OPT) -c main.cc
		
Book.o:	Book.cc Book.h ClubEntity.h
	g++ $(OPT) -c Book.cc

Member.o:	Member.cc Member.h ClubEntity.h
	g++ $(OPT) -c Member.cc
	
BookClub.o:	BookClub.cc BookClub.h 
	g++ $(OPT) -c BookClub.cc	
	
Rating.o:	Rating.cc Rating.h
	g++ $(OPT) -c Rating.cc
	
DynArray.o:	DynArray.cc DynArray.h
	g++ $(OPT) -c DynArray.cc
	
LinkedList.o:	LinkedList.cc LinkedList.h
	g++ $(OPT) -c LinkedList.cc
	
StatArray.o:	StatArray.cc StatArray.h
	g++ $(OPT) -c StatArray.cc
	
ClubEntity.o:	ClubEntity.cc ClubEntity.h
	g++ $(OPT) -c ClubEntity.cc
	
Control.o:	Control.cc Control.h
	g++ $(OPT) -c Control.cc
	
View.o:	View.cc View.h
	g++ $(OPT) -c View.cc
	
	
clean:
	rm -f *.o MT
