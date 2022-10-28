#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "ReportGenerator.h"
using namespace std;

Report5::Report5(string n) 
  : ReportGenerator(n){}
  
void Report5::loadPartial()
{
//no implementation(empty)
}


//implementation polymorphic execute function that generates coorosponding report
void Report5::execute(string& outStr)
{
  stringstream ss;
  ss.precision(3);
	outStr += "\n";
	//adds all column titles to the return string
	for(int d=0;d<allRegions.size();d++){
  	outStr += "\t" + allRegions[d]->getTarget();
	}
  double percentage;
  for(int r=0;r<allRegions.size();r++){
  	for(int x=0;x<allRegions.size();x++){
    	computePercentage5(allRegions[r]->getResults(),allRegions[x]->getResults(),percentage);
	    if(x==0){
	      //adds row titles at the beggining of each new row to return string
  	    outStr += "\n";
    	  outStr += allRegions[r]->getTarget();
    	}
    	//adds final percentage to return string
    	ss << percentage;
  		outStr += "\t"+ ss.str(); ;
    	ss.str("");
   }
  }
	outStr += "\n";
}

void Report5::computePercentage5(vector<Data*> main,vector<Data*> secondary,double &returnPercentage)
{
  returnPercentage=0;
  double tempGradeAll=0;
  double tempGradFemale=0;
	for(int i=0;i<main.size();i++){
	  //iterates through first regions data and accumulates the total graduates of 
	  //all genders, regardless of degree and year
	  if(main[i]->getGender()=="All"){
	  	tempGradeAll+=main[i]->getNumGrads();
  	}
	}
	for(int s=0;s<secondary.size();s++){
	  //iterates through second regions data and accumulates the total 
	  //female graduates,regardless of degree and year
		if(secondary[s]->getGender()=="Females"){
	  	tempGradFemale+=secondary[s]->getNumGrads();
  	}
  }
	if(tempGradeAll==0 || tempGradFemale==0 ){
		returnPercentage = 0;
	}else{
	  //sets return parameter to final proportion
		returnPercentage=tempGradFemale/tempGradeAll;
	}
}	
   	
