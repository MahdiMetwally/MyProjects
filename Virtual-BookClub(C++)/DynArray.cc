#include <iostream>
#include "ClubEntity.h"
#include "DynArray.h"
#define MAX_ARR 64

using namespace std;


DynArray::DynArray()
{
  memberList = new Member*[MAX_ARR];
  size = 0;
}

DynArray::~DynArray()
{
  for (int i=0; i<MAX_ARR; ++i){
 		delete memberList[i];
	}
	delete memberList;
	}

void DynArray::add(Member*& s)
{
  int stop=size;
  if (size >= MAX_ARR){
    return;
  }else if(stop==0){
  	memberList[size]=s;
  	size++;
  	return;
  }else{
 	 	for(int i=0;i<size;i++){
  		if(s->lessThan(memberList[i])){
  		  stop=i;
  			break;
  		}
  	}
	}
  for(int y=size; y>stop; y--){
  	memberList[y] = memberList[y-1];
  }
  memberList[stop]=s;
  size++;
}

void DynArray::print() const
{
  cout << endl << endl << "Members:" << endl;
  for (int i=0; i<size; i++){
    memberList[i]->print();
  }
}

bool DynArray::findMember(int id, Member*& mem) const
{
	for(int i=0;i<size;i++){
    if(memberList[i]->getId()==id){
      mem=memberList[i];
      return true;
		}
	}
	return false;
}


