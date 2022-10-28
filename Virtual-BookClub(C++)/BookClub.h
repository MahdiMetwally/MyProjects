#ifndef BOOKCLUB_H
#define BOOKCLUB_H
#include <string>
#include "LinkedList.h"
#include "DynArray.h"
#include "StatArray.h"

using namespace std;
//class that represents book club that stores a collection of rating, members, books, and a name.
class BookClub
{
  public:
    BookClub(string name="Defaut Name");
    ~BookClub();
    void addBook(Book*&);
    void addMember(Member*&);
    void addRating(int,int,int);
    void initAddRating(Rating*&);
    void printMembers() const;
    void printBooks() const;
    void printTopRated() const;
    void printMostRated() const;

  private:
    string name;
    LinkedList books;
		DynArray members;
		StatArray ratings;
};

#endif


