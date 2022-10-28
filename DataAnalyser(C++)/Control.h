#ifndef CONTROL_H
#define CONTROL_H
#include "View.h"
#include "ReportArray.h"
using namespace std;
//control class that is in charge of the flow of the program

class Control
{
  public:
  	Control();
  	~Control();
  	void launch();

  private:
  	//ReportGenerator object pointers are stored in ReportArray collection class
	  ReportArray generators;
  	View view;
  	void initAllData();

};

#endif
