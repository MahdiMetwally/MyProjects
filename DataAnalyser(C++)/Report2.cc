#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "ReportGenerator.h"
using namespace std;

Report2::Report2(string n) 
  : ReportGenerator(n)
{
  //loads all data into allRegions static collection when a Report2 object is created
	loadPartial();
}

void Report2::loadPartial()
{
	bool found;
	if(allRegions.size()==0){
		for (int i=0; i< allData.size(); i++) {
			found=false;
			for (int y=0; y< allRegions.size(); y++) {
				if(allRegions[y]->contains(allData[i]->getRegion())){
					*allRegions[y]+=allData[i];
			    found=true;
				}
			}
			if(found==false){
				Property<string>* tempProp = new Property<string>(allData[i]->getRegion());
				*tempProp+=allData[i];
				allRegions+=tempProp;
			}	
		}
	}
}

//implementation polymorphic execute function that generates coorosponding report
void Report2::execute(string& outStr)
{
  //stringstream is utilized to add the numeric data to outstr
  stringstream ss;
  ss.precision(3);
  int compare;
  //adds column title to str
	outStr += "\t\tFemales: \n\n";
	double percentage;
	for(int r=0;r<allRegions.size();r++){
  	computePercentage2(allRegions[r]->getResults(),percentage);
  	ss << percentage;
  	//row titles and percentages are concatnated to outStr
  	outStr+= allRegions[r]->getTarget();
  	outStr+= "\t\t" + ss.str() + "\n";
  	ss.str("");
	}
}

void Report2::computePercentage2(vector<Data*> main,double &returnPercentage)
{
  returnPercentage=0;
  double tempFemaleGrad=0;
  double tempAllGrads=0;
  //iterates through each regions data to sum all female graduates 
	for(int i=0;i<main.size();i++){
	  if(main[i]->getGender()=="All"){
	  	tempAllGrads+=main[i]->getNumGrads();
  	}
   //iterates through each regions data to sum graduates with genders combined (All) 
		if(main[i]->getGender()=="Females")
	  	tempFemaleGrad+=main[i]->getNumGrads();
		}
	if(tempFemaleGrad==0 || tempAllGrads==0 ){
		returnPercentage = 0;
	}else{
		//final proprtion is then added to the return parameter
		returnPercentage=tempFemaleGrad/tempAllGrads;
	}
}	
