#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "ReportGenerator.h"
using namespace std;

Report1::Report1(string n) 
  : ReportGenerator(n)
{
  //loads all data into allYears static collection when a Report1 object is created
	loadPartial();
}

//implementation of derived pure virtual function that lads data into allYears static collection
void Report1::loadPartial()
{
	bool found;
	//prevents allYears from being loaded twice
	if(allYears.size()==0){
 		for (int i=0; i< allData.size(); i++) {
			found=false;
			for (int y=0; y< allYears.size(); y++) {
				if(allYears[y]->contains(allData[i]->getYear())){
				  //adds new data to property if year is already in allYears collection
					*allYears[y]+=allData[i];
		   		found=true;
				}
			}
			if(found==false){
			  //creates new propert function which is added to allYears collection
				Property<int>* tempProp = new Property<int>(allData[i]->getYear());
			  *tempProp+=allData[i];
				allYears+=tempProp;
			}
		}	
	}
}

//implementation polymorphic execute function that generates coorosponding report
void Report1::execute(string& outStr)
{
  //used to add double value into outstr
  stringstream ss;
  ss.precision(3);
  //adds column titles to outstr
	for(int d=0;d<allDegrees.size();d++){
	  outStr += "\t    " + allDegrees[d]->getTarget();
	}
	outStr += "\n";
  double percentage;
  //nested loop that iterates through all region and degree combinations
	for(int r=0;r<allRegions.size();r++){
		for(int d=0;d<allDegrees.size();d++){
		  //calls helper function that returns percentage for each region,with given degree
	  	computePercentage(allRegions[r]->getResults(),allDegrees[d]->getTarget(),percentage);
	  	if(d==0){
	  	  //adds row titles to outStr
	  	  outStr += "\n";
	  	  outStr += allRegions[r]->getTarget();
	  	}
	    //adds percentages to outStr
	  	ss << percentage;
	  	outStr += "\t\t" + ss.str();
	    ss.str("");
	  }
  }
  outStr += "\n";
}

//helper function that returns percentage for each region,with given degree
void Report1::computePercentage(vector<Data*> main,string search,double &returnPercentage)
{
  returnPercentage=0;
  double tempGradDeg=0;
  double tempEmp=0;
	for(int i=0;i<main.size();i++){
	  //total of graduates in given region of all genders,degrees,and all years is computed
		if(main[i]->getGender()=="All"){
    	tempGradDeg+=main[i]->getNumGrads();
  	}
  	//total of employed in given region ,with given degree ,of all genders and all years is computed
    if(main[i]->getDegree()==search && main[i]->getGender()=="All" ){
	    tempEmp+=main[i]->getNumEmployed();
		}
	}
	if(tempGradDeg==0 || tempEmp==0){
		returnPercentage = 0;
	}else{
		//final proprtion is then added to the return parameter
		returnPercentage=tempEmp/tempGradDeg;
	}
}	




