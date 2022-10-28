#include <iostream>
using namespace std;
#include <string>
#include "Control.h"
#include "ReportGenerator.h"
#include <vector>

Control::Control()
{
	initAllData();
};

//will call destructor on all ReportGenerators in generators collection
Control::~Control(){};

void Control::launch()
{
  while (1) {
    string returnStr;
    view.resetCounter();
    int choice;
    view.showMenu();

    for (int i=0;i<generators.getSize();i++){
    view.printChoice(generators[i]->getName(),generators.getSize());
 		}
 		//view object calling function to read input from user
 		view.userInput(choice,generators.getSize());
    //each report generator is queried in its collection and set as an argument 
    //to the view showMenu function
    if(choice<1){
    	break;
  	}else{
			generators[choice-1]->execute(returnStr);
			view.printStr(returnStr);
		}
	}
}

void Control::initAllData()
{
  //all 5 report generating sub concrete class object pointers made and 
  //added to a collection of ReportGenerator class object pointers  
  generators.add(new Report1("Report 1"));
  generators.add(new Report2("Report 2"));
  generators.add(new Report3("Report 3"));
  generators.add(new Report4("Report 4"));
  generators.add(new Report5("Report 5"));
}

