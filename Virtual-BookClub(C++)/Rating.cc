#include <iostream>
#include <iomanip>
#include <string>
#include "ClubEntity.h"
#include "Rating.h"

using namespace std;

Rating::Rating(Member* m,Book* b, int s) 
  : member(m), book(b), score(s){ }
  
Rating::~Rating() {}

void Rating::getMember(Member*& retMember) const { retMember=member; }

void Rating::getBook(Book*& retBook) const { retBook=book; } 

int Rating::getScore() const { return score; } 




