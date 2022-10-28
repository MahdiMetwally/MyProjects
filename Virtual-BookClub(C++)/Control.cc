#include <iostream>
#include <string>
#include "Control.h"

using namespace std;

Control::Control()
{
  bClub = new BookClub("Best Book Club");
  init(bClub);
};

Control::~Control(){}

void Control::launch()
{

  while (1) {
    int choice;
    view.showMenu(choice);
    //exit program and free book club pointer
    if (choice == 0){
    delete bClub;
    break;
    }

		//Print Members
    if (choice == 1) {
			bClub->printMembers();
    }
		//Print Books
    if (choice == 2) {
			bClub->printBooks();
    }
		//Rate Specific Book given member id and book id (also rating)
    if (choice == 3) {
			int memberInput;
			int bookInput;
			int rating;
			cout << "Enter Member Id" <<endl;
			view.readInt(memberInput);
		  cout << "Enter Book Id" <<endl;
			view.readInt(bookInput);
			cout << "Enter Book Rating" <<endl;
			view.readInt(rating);
			while(rating < 1 || rating > 10){
		  	cout << "Rating must between 1 and 10,try again!" <<endl;
				view.readInt(rating);
			}
			bClub->addRating(memberInput,bookInput,rating);
    }
		//compute and print top rated and most rated books in the book club
    if (choice == 4) {
			bClub->printTopRated();
		  cout << endl;
			bClub->printMostRated();
    }
  }
}

void Control::init(BookClub*& bClub)
{
	//10 books are created
  Book* b1 = new Book("Party Of Two", "Jasmine Gullory",2007);
  Book* b2 = new Book("Beach Read", "Harold",2005);
  Book* b3 = new Book("Invisible Man", "Ralph Ellison",1952);
  Book* b4 = new Book("To Kill A Mockingbird", "Harper Lee",1960);
  Book* b5 = new Book("Lord Of The Flies", "William Golding",1954);
  Book* b6 = new Book("Hamlet", "Shakespeare",1603);
  Book* b7 = new Book("Anna Kerenina", "Leo Tolstoy",1878);
  Book* b8 = new Book("The Great Gatsby", "F.Scott Fitzgerald",1925);
  Book* b9 = new Book("A Passage to India", "E.M. Forster",1924);
  Book* b10 = new Book("Jane Eyre", "Charlotte Bronte",1847);

	//5 members are created
  Member* m11 = new Member("Peters", "Mallory");
  Member* m12 = new Member("Butcher", "Anna");
  Member* m13 = new Member("Griffin", "Chris");
  Member* m14 = new Member("Simpson", "Bart");
  Member* m15 = new Member("Green", "Charlotte");
  
  //20 rating are created
 	Rating* r1 = new Rating(m11,b1,6);
  Rating* r2 = new Rating(m11,b2,7);
  Rating* r3 = new Rating(m11,b3,3);
  Rating* r4 = new Rating(m11,b4,8);
  
  Rating* r5 = new Rating(m12,b3,3);
	Rating* r6 = new Rating(m12,b4,7);
 	Rating* r7 = new Rating(m12,b7,1);
  
 	Rating* r8 = new Rating(m13,b4,4);
	Rating* r9 = new Rating(m13,b5,7);
  Rating* r10 = new Rating(m13,b6,5);
  Rating* r11 = new Rating(m13,b1,5);
  Rating* r12 = new Rating(m13,b1,5);
  
 	Rating* r13 = new Rating(m14,b7,8);
  Rating* r14 = new Rating(m14,b8,5);
  Rating* r15 = new Rating(m14,b9,3);
  
  Rating* r16 = new Rating(m15,b1,6);
  Rating* r17 = new Rating(m15,b3,8);
  Rating* r18 = new Rating(m15,b7,4);
  Rating* r19 = new Rating(m15,b8,10);
  Rating* r20 = new Rating(m15,b4,3);
  
  //books are added to the book club
  bClub->addBook(b2);
  bClub->addBook(b1);
  bClub->addBook(b3);
  bClub->addBook(b4);
  bClub->addBook(b5);
  bClub->addBook(b6);
	bClub->addBook(b7);
  bClub->addBook(b8);
	bClub->addBook(b9);
	bClub->addBook(b10);
	
	//members arre added to the book club
	bClub->addMember(m11);
	bClub->addMember(m12);
	bClub->addMember(m13);
	bClub->addMember(m14);
	bClub->addMember(m15);
      
  //ratings are added to the book club            
  bClub->initAddRating(r1);
  bClub->initAddRating(r2);
  bClub->initAddRating(r3);
  bClub->initAddRating(r4);
  bClub->initAddRating(r5);
  bClub->initAddRating(r6);
  bClub->initAddRating(r7);
  bClub->initAddRating(r8);
  bClub->initAddRating(r9);
  bClub->initAddRating(r10);
  bClub->initAddRating(r11);
  bClub->initAddRating(r12);
  bClub->initAddRating(r13);
  bClub->initAddRating(r14);
  bClub->initAddRating(r15);
  bClub->initAddRating(r16);
  bClub->initAddRating(r17);
  bClub->initAddRating(r18);
  bClub->initAddRating(r19);
  bClub->initAddRating(r20);

  
}

