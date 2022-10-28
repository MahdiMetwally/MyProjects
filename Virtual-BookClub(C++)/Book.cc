#include <iostream>
#include <iomanip>
#include "Book.h"
#include "ClubEntity.h"

using namespace std;

Book::Book(string t, string a, int y) 
  : title(t), author(a), year(y), ClubEntity() { }
  
Book::~Book() { }

void Book::print()
{
  cout << "id:"  << id
       <<"  Title: "    << title
       <<";  Author: "  << author
       <<";  Year: "    << year << endl;
}

//function that alows books to be ordered by author, then by title
bool Book::lessThan(Book*& b) 
{ 
  if(this->author == b->author){
    return  this->title < b->title;
	}else{
		return this->author < b->author;
	}
}


