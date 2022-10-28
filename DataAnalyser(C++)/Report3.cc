#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "ReportGenerator.h"
using namespace std;

Report3::Report3(string n) 
  : ReportGenerator(n)
{
  //loads all data into allDegrees static collection when a Report3 object is created
	loadPartial();
}

void Report3::loadPartial()
{
	bool found;
	if(allDegrees.size()==0){
		for (int i=0; i< allData.size(); i++) {
    	found=false;
    	for (int y=0; y< allDegrees.size(); y++) {
	  		if(allDegrees[y]->contains(allData[i]->getDegree())){
	 				*allDegrees[y]+=allData[i];
        	found=true;
  	  	}
	  	}
  		if(found==false){
			  Property<string>* tempProp = new Property<string>(allData[i]->getDegree());
				*tempProp+=allData[i];
		  	allDegrees+=tempProp;
  		}
 		}	
 	}
}

//implementation polymorphic execute function that generates coorosponding report
void Report3::execute(string& outStr)
{
  //stringstreaam is used to concatnate numeric value to outStr
  stringstream ss;
  ss.precision(3);
  //adds all column titles to outStr (return string)
  for(int y=0;y<allYears.size();y++){
    ss << allYears[y]->getTarget();
	  outStr += "\t\t" + ss.str();
	  ss.str("");
	}
	outStr += "\n";
	//allRegions is traversed and property object pointer that represents canadian partial data is 
	//saved to local variable canTemp
  Property<string>* canTemp;
	for(int r=0;r<allRegions.size();r++){
	  if(allRegions[r]->getTarget()=="CAN"){
	    canTemp=allRegions[r];
    }
  }
  double percentage;
	for(int r=0;r<allRegions.size();r++){
		for(int y=0;y<allYears.size();y++){
			computePercentage3(allRegions[r]->getResults(),canTemp,allYears[y]->getTarget(),percentage);
	  	if(y==0){
	  	  //row titles are printed when a new row begining
	  	  outStr += "\n" + allRegions[r]->getTarget();
	  	}
	  	//percentage is added to return string outStr
	  	ss << percentage;
	  	outStr += "\t\t" + ss.str();
	    ss.str("");
	 }
	}
	outStr += "\n";
}

void Report3::computePercentage3(vector<Data*> main,Property<string>*& canProp,int searchYear,double &returnPercentage)
{
  returnPercentage=0;
  double tempEmployed=0;
  double tempAllGrads=0;
  int canEmp=0;
  //canadian emplyment numbers for each year are computed
	for(int i=0;i<canProp->getResults().size();i++){
	  if(canProp->getResults()[i]->getYear()==searchYear && canProp->getResults()[i]->getGender()=="All"){
	    canEmp+=canProp->getResults()[i]->getNumEmployed();
	   }
	}
	//emplyments numbers are computed for each region, for a specific year regardless of gender and degrees
	for(int i=0;i<main.size();i++){
		if(main[i]->getGender()=="All" && main[i]->getYear()==searchYear){
	  	tempEmployed+=main[i]->getNumEmployed();
  	}
  }
	if(tempEmployed==0 || canEmp==0 ){
		returnPercentage = 0;
	}else{
	  //return parameter is set to the final proportion
		returnPercentage=tempEmployed/canEmp;
	}
}	
   	
