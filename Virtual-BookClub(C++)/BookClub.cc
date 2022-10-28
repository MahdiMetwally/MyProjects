#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "BookClub.h"


BookClub::BookClub(string n) 
  : name(n){ }
  
BookClub::~BookClub() {}

void BookClub::addBook(Book*& b)
{
	books.add(b);
}
void BookClub::addMember(Member*& m)
{
	members.add(m);
}

//adds rating to ratings list given the identifier of the book and member (and rating)
void BookClub::addRating(int mId, int bId, int score)
{
	Book* book;
  Member* member;
  bool foundBook;
  bool foundMember;  
  foundBook = books.findBook(bId, book);
  foundMember = members.findMember(mId, member);
  //check if rating already exists
  if (ratings.ratingExists(member,book)){
		cout << "Rating already added" <<endl;
		return;
  }else{
  	//check that both member and book exist
  	if(foundBook && foundMember){
  	  //create new rating and add it to rating list and members colection of books rated
			Rating* r = new Rating(member,book,score);
			ratings.add(r);
			member->addBook(book);
			cout << "Rating Added!" <<endl;
		}else{
		  cout << "invalid Book and/or Member!" <<endl;
		}
	}
}

void BookClub::printMembers() const
{
	members.print();
}

void BookClub::printBooks() const
{
	books.print();
}

//iterates through book collection to find the top rated book
void BookClub::printTopRated() const
{
  Book* topBook;
  Book* nextBook;
  double highest;
  double nextAverage;
  //first book in collection is set to highest rated
  books.getByIndex(0,topBook);
  ratings.getAverage(topBook, highest);
  //iterates through all books in ook club book collection
	for(int i=1;i<books.getNumBooks();i++){
	  books.getByIndex(i,nextBook);
	  ratings.getAverage(nextBook,nextAverage);
	  //if next book has a greater highest value, top rated book is set to the next book
		if(highest < nextAverage){
		  highest = nextAverage;
		  topBook = nextBook;
		}
	}
	cout <<"Top Rated Book with a Rating of " << highest << ": " <<endl;
	topBook->print();
}

//same algoirithm used in printTopRated(), except getFrequency() is utilized instead of getAverage()
void BookClub::printMostRated() const
{
  Book* topBook;
  Book* nextBook;
  int highest;
  int nextMost;
  //first book in collection is set to highest rated
  books.getByIndex(0,topBook);
  ratings.getFrequency(topBook, highest);
  //iterates through all books in ook club book collection
	for(int i=1;i<books.getNumBooks();i++){
	  books.getByIndex(i,nextBook);
	  ratings.getFrequency(nextBook,nextMost);
	  //if next book has a greater highest value, top rated book is set to the next book
		if(highest < nextMost){
		  highest = nextMost;
		  topBook = nextBook;
		}
	}
	cout <<"Most Rated Book, Rated " << highest << " Times: " <<endl;
	topBook->print();
}

//adds rating without user input, used for initialization purposes
void BookClub::initAddRating(Rating*& r)
{
  Book* retBook;
  Member* retMember;
  //rating is added to ratings collection and book rated is added to the members book collection
	ratings.add(r);
	r->getMember(retMember);
	r->getBook(retBook);
	retMember->addBook(retBook);
}







