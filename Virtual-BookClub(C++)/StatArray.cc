#include <iostream>
#include "StatArray.h"
#define MAX_ARR 64

using namespace std;



StatArray::StatArray()
{
  size = 0;
}

StatArray::~StatArray()
{
  for (int i=0; i<size; ++i){
    delete ratingList[i];
	}
}

void StatArray::add(Rating*& r)
{
  if (size >= MAX_ARR){
    return;
  }else{
    ratingList[size]=r;
    size++;
	}			
}

bool StatArray::ratingExists(Member*& member, Book*& book)
{
  Member* retMember;
  Book* retBook;
	for(int i=0;i<size;i++){
		ratingList[i]->getMember(retMember);
	  ratingList[i]->getBook(retBook);
    if(retMember==member && retBook==book ){
      return true;
		}
	}
	return false;
}

//takes book arguments and returns the average rating of that book in the ratings list
void StatArray::getAverage(Book*& book, double& ret) const
{
  Book* retBook;
	double total;
	double count;
	total=0.0;
	count=0.0;
	for(int i=0;i<size;i++){
	  ratingList[i]->getBook(retBook);
    if(retBook==book){
			total+=ratingList[i]->getScore();
			count++;
		}
	}
	if(count>0 && total >0){
	  total=total/count;
    ret = total;
  }else{
    ret=0;
	}
}	

//takes book arguments and returns the frequency of that book in th ratings list
void StatArray::getFrequency(Book*& book, int& ret) const
{
  Book* retBook;
	int count=0;
	for(int i=0;i<size;i++){
	  ratingList[i]->getBook(retBook);
    if(retBook==book){
			count++;
		}
	}
	ret=count;
}




