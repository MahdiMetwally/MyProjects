#include <iostream>
#include <iomanip>
#include "Member.h"
#include "ClubEntity.h"

using namespace std;

Member::Member(string n1, string n2) 
  : lastName(n1), firstName(n2), ClubEntity() { }

Member::~Member() { }

bool Member::lessThan(Member*& mem) const 
{
	return id < mem->getId();
}

//adds book that member has rated to members collection of books
void Member::addBook(Book*& b)
{
	ratedBooks.add(b);
}

void Member::print() const
{
	cout << "Member Name: " << lastName << ", " << firstName << ", ID: " << id <<endl;
}

