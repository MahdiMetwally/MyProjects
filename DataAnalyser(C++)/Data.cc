#include <iostream>
#include <iomanip>
#include <string>
#include "Data.h"
using namespace std;

Data::Data(int y,string r,string d,string g,int e,int x) 
  : year(y),region(r),degree(d),gender(g),numEmployed(e),numGrads(x){ }

int Data::getYear()const {return year;}

string Data::getRegion()const {return region;}

string Data::getDegree()const {return degree;}

string Data::getGender()const {return gender;}

int Data::getNumEmployed()const {return numEmployed;}

int Data::getNumGrads()const {return numGrads;}


