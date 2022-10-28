#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
using namespace std;
//class that is designed to hold each record read in from the data file(3.2.3)

class Data
{
  public:
  	Data(int,string,string,string,int,int);
  	int getYear() const;
		string getRegion() const;
		string getDegree() const;
		string getGender() const;
		int getNumEmployed() const;
		int getNumGrads() const;
  	
  private:
  	int year;
		string region;
		string degree;
		string gender;
		int numEmployed;
		int numGrads;
	
};

#endif
