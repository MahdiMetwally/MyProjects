#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "ReportGenerator.h"
using namespace std;

Report4::Report4(string n) 
  : ReportGenerator(n)
{
  //loads all data into allGenders static collection when a Report4 object is created
  loadPartial();
}


void Report4::loadPartial()
{
	bool found;
	if(allGenders.size()==0){
		for (int i=0; i< allData.size(); i++) {
    	found=false;
    	for (int g=0; g< allGenders.size(); g++) {
	  		if(allGenders[g]->contains(allData[i]->getGender())){
	 				*allGenders[g]+=allData[i];
        	found=true;
  	  	}
	  	}
  		if(found==false){
				Property<string>* tempProp = new Property<string>(allData[i]->getGender());
				*tempProp+=allData[i];
		  	allGenders+=tempProp;
  		}
 		}	
 	}
}

//implementation polymorphic execute function that generates coorosponding report
void Report4::execute(string& outStr)
{
  //stringstreaam is used to concatnate numeric value to outStr
  stringstream ss;
  ss.precision(2);
  double percentage;
  
  for(int y=0;y<allYears.size();y++){
    //adds table year number to the return string outStr
		ss << allYears[y]->getTarget();
		outStr += "\n\nFor Year: " + ss.str();
  	ss.str("");
    //adds column titles  for each table to return string outStr
		outStr += "\n\t\tFemales\t\tMales\n";
    for(int r=0;r<allRegions.size();r++){
    	outStr += "\n";
    	for(int g=0;g<allGenders.size();g++){
    	  //only compute proportion and add to return string if gender is male or female (not All)
    	  if(allGenders[g]->getTarget()!= "All"){
		    	computePercentage4(allRegions[r]->getResults(),allGenders[g]->getTarget(),allYears[y]->getTarget(),percentage);
		    	//percentage is added to the return string
		    	ss << percentage;
	    		outStr += "\t\t" + ss.str();
	      	ss.str("");
		    }
  	    if(g==0){
  	      //row titles are added to return string at the beginging of each new row
	    	  outStr += allRegions[r]->getTarget();
	    	}
	   }
  	}
	}
	outStr += "\n";
}


void Report4::computePercentage4(vector<Data*> main,string searchGender,int searchYear,double &returnPercentage)
{
  returnPercentage=0;
  double tempEmployed=0;
  double tempAllGrads=0;
	for(int i=0;i<main.size();i++){
	  //gradutes total for given region and all genders in given year is computed
	  if(main[i]->getGender()=="All" && main[i]->getYear() == searchYear){
	  	tempAllGrads+=main[i]->getNumGrads();
	  //employment total for given gender in given region in given year,regardless of degree is computed
	 }else if(main[i]->getGender()==searchGender && main[i]->getYear() == searchYear){
	  	tempEmployed+=main[i]->getNumEmployed();
  	}
  }
	if(tempEmployed==0 || tempAllGrads==0 ){
		returnPercentage = 0;
	}else{
	  //final proportion is then added to the return parameter
		returnPercentage=tempEmployed/tempAllGrads;
	}
}	
   	
