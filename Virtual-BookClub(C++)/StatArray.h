#ifndef STATARRAY_H
#define STATARRAY_H
#define MAX_ARR 64
#include "Rating.h"

using namespace std;
//Collection class that stores a statically allocated array of Rating pointers
class StatArray
{
  public:
    StatArray();
    ~StatArray();
    void add(Rating*&);
    bool ratingExists(Member*&, Book*&);
    void getAverage(Book*&,double&) const;
    void getFrequency(Book*&,int&) const;

  private:
    Rating* ratingList[MAX_ARR];
    int   size;
};

#endif

