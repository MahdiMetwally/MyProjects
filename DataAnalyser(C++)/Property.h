#ifndef PROPERTY_H
#define PROPERTY_H
#include <string>
#include "Data.h"
#include <vector>
using namespace std;
//class template that can store a single year,degree,gender,or region 
//and stores a vector that contains all the data object pointers coorosponding
//to that target value

template <class T>
class Property
{
  public:
    Property(T);
    ~Property();
    bool contains(T);
    void operator+=(Data*&);
    Data*& operator[](int);
    T getTarget();
    vector<Data*> getResults();

  private:
    T target;
    vector<Data*> results;
};

template <class T>
Property<T>::Property(T targetVal)
	: target(targetVal){}
		
//no need to deallocate results collection becuase allData pointers will be deallocated
template <class T>
Property<T>::~Property(){}	

//function that returns true or false if target is equal to argument
template <class T>
bool Property<T>::contains(T t)
{
 return (target==t);
}

//addition assignment operator that adds a new element to the back of the record collection
template <class T>
void Property<T>::operator+=(Data*& d)
{
  results.push_back(d);
}

template <class T>
Data*& Property<T>::operator[](int index)
{
	if(index < 0 || index >= results.size()) {
  	cout << "ERROR:  invalid index" << endl;
    exit(1);
  }else{
 	 return results[index];
	}
}

//getter function that returns value representing partial data of calling property object
template <class T>
T Property<T>::getTarget(){return target;}

//getter function that returns collection of data object pointers of calling property object
template <class T>
vector<Data*> Property<T>::getResults(){return results;}



#endif
