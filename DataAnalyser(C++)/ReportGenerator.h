#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H
#include <string>
#include <iostream>
#include "Data.h"
#include "PartialCollection.h"
#include "Property.h"
#include <vector>
//Abstract Report Generator class is the parent class to 5 report enerator sub classes.
using namespace std;

class ReportGenerator
{
  public:
  	ReportGenerator(string);
  	~ReportGenerator();
		string getName();
		virtual void loadPartial() = 0;
	  virtual void execute(string&) = 0;  
	  
	protected:
		static vector<Data*> allData;
		static PartialCollection<int> allYears;
	  static PartialCollection<string> allRegions;
	  static PartialCollection<string> allDegrees;
	  static PartialCollection<string> allGenders;
	  
	private:
	  string reportName;
		static void dataLoad(); 
		//used for deallocation purposes
		static int delSignal;

};
//Class definiitions for all 5 reportGenerator concrete sub classes are below
/////////////////////////////////REPORT1////////////////////////////////////////////////////////////////////

//Report1 = Exam Specifications(2.1)
//Report 1 is a concrete subclass of ReportGenerator that computes the 
//employment percentage for each region,by degree,for all years and genders
class Report1 : public ReportGenerator
{
  public:
    Report1(string);
	  virtual void execute(string&);

	private:
		void computePercentage(vector<Data*>,string,double&);
	  virtual void loadPartial();
};

/////////////////////////////////REPORT2////////////////////////////////////////////////////////////////////

//Report2 = Exam Specifications(2.2)
//Report2 is a concrete sub class of the ReportGenerator that computes the 
//percentage of females graduates,for all years and all degrees
class Report2 : public ReportGenerator
{
  public:
    Report2(string);
	  virtual void execute(string&);
	  
	private:
		void computePercentage2(vector<Data*>,double&);
	  virtual void loadPartial();
};

/////////////////////////////////REPORT3////////////////////////////////////////////////////////////////////

//Report3 = Exam Specifications(2.3)
//Report3 is a concrete sub class of the ReportGenerator that computes 
//the employment percentage for each region,by year,for all degrees and genders
class Report3 : public ReportGenerator
{
  public:
  	Report3(string);
	  virtual void execute(string&);

	private:
	  void computePercentage3(vector<Data*>,Property<string>*&,int,double&);
	  virtual void loadPartial();
};

/////////////////////////////////REPORT4////////////////////////////////////////////////////////////////////

//Report4 is a concrete sub class of the ReportGenerator that computes 
//the proprtion of employed for each gender in a given region,for each year,regardless of thier degree compared
//to all graduates in that region and in that year,regardless of degree.
//Report4 = refer to README.txt for further explanation
class Report4 : public ReportGenerator
{
  public:
  	Report4(string);
	  virtual void execute(string&);

	private:
	  void computePercentage4(vector<Data*>,string,int,double&);
	  virtual void loadPartial();
};

/////////////////////////////////REPORT5////////////////////////////////////////////////////////////////////

//Report5 is a concrete sub class of the ReportGenerator that computes 
//the proprtion of female graduates in a region,regardless of degree and year compared to all graduates
//in another region regardless of degree and year.
//Report5 = refer to README.txt for further explanation
class Report5 : public ReportGenerator
{
  public:
  	Report5(string);
	  virtual void execute(string&);

	private:
	  void computePercentage5(vector<Data*>,vector<Data*>,double&);
	  virtual void loadPartial();
};

#endif
