#ifndef REPORTARRAY_H
#define REPORTARRAY_H
#define MAX_ARR 12
#include "ReportGenerator.h"
using namespace std;
//collection class that stores an array of ReportGenerator object pointers

class ReportArray
{
  public:
    ReportArray();
    ~ReportArray();
    ReportGenerator*& operator[](int);
    void add(ReportGenerator*);
    int getSize() const;

  private:
    ReportGenerator* generators[MAX_ARR];
    int   size;
};

#endif

