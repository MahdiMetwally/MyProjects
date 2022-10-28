#ifndef PARTIALCOLLECTION_H
#define PARTIALCOLLECTION_H
#include <string>
#include "Property.h"
#include <vector>
using namespace std;
//template collectin class that stores the property class object pointers

template <class T>
class PartialCollection
{
  public:
    PartialCollection();
    ~PartialCollection();
    void operator+=(Property<T>*&);
    Property<T>*& operator[](int);
    int size();

  private:
    T target;
    vector<Property<T>*> propertyList;
};

template <class T>
PartialCollection<T>::PartialCollection(){}
		
//no need to deallocate results collection becuase allData pointers will be deallocated
template <class T>
PartialCollection<T>::~PartialCollection(){}	

//addition assignment operator that adds a new element to the back of the record collection
template <class T>
void PartialCollection<T>::operator+=(Property<T>*& p)
{
  propertyList.push_back(p);
}

//allows ReportGenerator object pointers to be accessed using indexing
template <class T>
Property<T>*& PartialCollection<T>::operator[](int index)
{
	if(index < 0 || index >= propertyList.size()) {
  	cout << "ERROR:  invalid index" << endl;
    exit(1);
  }else{
 	 return propertyList[index];
	}
}

//simple getter that returns size of colection
template <class T>
int PartialCollection<T>::size()
{
  return propertyList.size();
}


#endif
