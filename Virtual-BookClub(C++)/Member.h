#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include "LinkedList.h"
#include "ClubEntity.h"
//class representing members in a book club
using namespace std;

class Member : public ClubEntity
{
  public:
    Member(string="DefaultName", string="DefaultName");
    ~Member();
    bool lessThan(Member*&) const;
    void print() const;
    void addBook(Book*&);

  private:
    string firstName;
    string lastName;
    LinkedList ratedBooks;
};

#endif

