#include <iostream>
#include "ReportArray.h"
using namespace std;

ReportArray::ReportArray()
{
  size = 0;
}

ReportArray::~ReportArray()
{
	for (int i=0;i<size;i++){
		delete generators[i];
	}
}

//allows ReportGenerator object pointers to be accessed using indexing
ReportGenerator*& ReportArray::operator[](int s)
{
  if (s<0 || s >= size) {
    exit(1);
  }
  return generators[s];
}

//add ReportGenerator object pointers to collection
void ReportArray::add(ReportGenerator* r)
{
  if (size >= MAX_ARR)
    return;

  generators[size] = r;
  ++size;
}


int ReportArray::getSize() const {return size;}
