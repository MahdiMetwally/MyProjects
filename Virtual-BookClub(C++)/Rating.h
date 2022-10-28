#ifndef RATING_H
#define RATING_H

#include <string>
#include "Member.h"
#include "Book.h"
//association class that represents what book club member rated what book
using namespace std;

class Rating
{
  public:
    Rating(Member*, Book*, int);
    ~Rating();
    void getMember(Member*&) const;
    void getBook(Book*&) const;
    int getScore() const;

  private:
    Member* member;
    Book* book;
		int score;
};

#endif


