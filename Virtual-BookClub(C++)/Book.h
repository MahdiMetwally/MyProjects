#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "ClubEntity.h"
//Book class that stores basic information for a book
using namespace std;

class Book : public ClubEntity
{
  public:
    Book(string="Unknown", string="Unknown", int=0);
    ~Book();
    void print();
    bool lessThan(Book*& b);

  private:
    string title;
    string author;
    int    year;
};

#endif

