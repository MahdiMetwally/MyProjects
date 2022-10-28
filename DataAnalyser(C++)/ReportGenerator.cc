#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "ReportGenerator.h"
#include "Property.h"
using namespace std;
vector<Data*> ReportGenerator::allData;
PartialCollection<int> ReportGenerator::allYears;
PartialCollection<string> ReportGenerator::allRegions;
PartialCollection<string> ReportGenerator::allDegrees;
PartialCollection<string> ReportGenerator::allGenders;
int ReportGenerator::delSignal=0;


//constructor that intializes report name and call function to init allData collection if it isnt init already
ReportGenerator::ReportGenerator(string n) 
{
	reportName=n;
	if(allData.empty()){
		dataLoad();
 	}
}

//destructor deallocates all shared static collections
ReportGenerator::~ReportGenerator() 
{
  //prevents data member to be deallocated more than once(double free)
	if(delSignal==0){
		for(int d=0;d<allData.size();d++){
			delete allData[d];
		}	 
		for(int y=0;y<allYears.size();y++){
			delete allYears[y];
		}	 
		for(int r=0;r<allRegions.size();r++){
			delete allRegions[r];
		}	 
		for(int f=0;f<allDegrees.size();f++){
			delete allDegrees[f];
		}	
		for(int g=0;g<allGenders.size();g++){
			delete allGenders[g];
		}	
		delSignal=1;
		return; 
  }
  return;
}

//initialization function that loads data from grad.dat to allData static collection
void ReportGenerator::dataLoad()
{
  //objects that will represent each file line attribute
  int year;
  string region;
  string major;
  string gender;
  int numEmployed;
  int numGrad;
  
	ifstream infile("grad.dat", ios::in);

  //ends program if file loading fails
  if (!infile) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }
  //iterates through each file line and creates a data object pointer which is then added to allData collection
  while (infile >> year >> region >> major >> gender >> numEmployed >> numGrad ) {
    Data* newData = new Data(year, region, major, gender, numEmployed, numGrad);
    ReportGenerator::allData.push_back(newData);
  }
}

string ReportGenerator::getName(){return reportName;}

/*
expected output(for debugging reasons)
1
	    Bachelor's	    College	    Doctorate	    Master's

AB		0.436		0.347		0.0228		0.11
BC		0.408		0.372		0.0145		0.11
CAN		0.407		0.345		0.0186		0.135
MB		0.466		0.34		0.0138		0.0966
NB		0.427		0.381		0.00484		0.0806
NL		0.417		0.307		0		0.141
NS		0.404		0.324		0.0118		0.158
ON		0.378		0.379		0.0178		0.125
PE		0.295		0.583		0		0.02
QC		0.426		0.269		0.0251		0.192
SK		0.488		0.319		0.0147		0.0975

2
		Females: 
AB		0.606
BC		0.581
CAN		0.586
MB		0.588
NB		0.555
NL		0.565
NS		0.575
ON		0.578
PE		0.5
QC		0.602
SK		0.581


3
		2000		2005		2010		2015
AB		0.0784		0.104		0.0971		0.101
BC		0.128		0.119		0.135		0.133
CAN		1		1		1		1
MB		0.031		0.0351		0.0309		0.0301
NB		0.0245		0.0255		0.0159		0.0198
NL		0.0147		0.013		0.0154		0.00918
NS		0.0376		0.0398		0.0375		0.0345
ON		0.436		0.395		0.39		0.398
PE		0.00623		0.00448		0.00482		0.00586
QC		0.205		0.236		0.242		0.241
SK		0.0334		0.0294		0.0297		0.0266

4

For Year: 2000
		Females		Males

AB		0.53		0.39
BC		0.51		0.38
CAN		0.53		0.37
MB		0.55		0.37
NB		0.48		0.41
NL		0.45		0.35
NS		0.5		0.37
ON		0.53		0.37
PE		0.49		0.42
QC		0.52		0.37
SK		0.57		0.39

For Year: 2005
		Females		Males

AB		0.57		0.37
BC		0.57		0.36
CAN		0.54		0.37
MB		0.54		0.36
NB		0.5		0.41
NL		0.57		0.32
NS		0.52		0.38
ON		0.53		0.38
PE		0.48		0.39
QC		0.54		0.37
SK		0.52		0.37

For Year: 2010
		Females		Males

AB		0.54		0.4
BC		0.5		0.4
CAN		0.53		0.38
MB		0.55		0.38
NB		0.51		0.38
NL		0.47		0.4
NS		0.53		0.36
ON		0.52		0.39
PE		0.42		0.4
QC		0.57		0.36
SK		0.51		0.42

For Year: 2015
		Females		Males

AB		0.54		0.35
BC		0.5		0.39
CAN		0.51		0.39
MB		0.49		0.4
NB		0.48		0.42
NL		0.47		0.41
NS		0.51		0.39
ON		0.49		0.4
PE		0.42		0.35
QC		0.53		0.38
SK		0.51		0.41

5

		AB		BC		CAN			MB		NB		NL			NS		ON		PE		QC		SK

AB	0.606	0.794	6.18	0.194	0.125	0.0803	0.227	2.47	0.0284	1.47	0.178

BC	0.443	0.581	4.52	0.142	0.0914	0.0588	0.167	1.81	0.0208	1.07	0.13

CAN	0.0574	0.0752	0.586	0.0184	0.0118	0.00761	0.0216	0.235	0.00269	0.139	0.0169

MB	1.84	2.4	18.7	0.588	0.378	0.243	0.689	7.5	0.0861	4.45	0.539

NB	2.69	3.53	27.5	0.863	0.555	0.357	1.01	11	0.126	6.52	0.791

NL	4.26	5.58	43.5	1.37	0.878	0.565	1.6	17.4	0.2	10.3	1.25

NS	1.53	2.01	15.6	0.491	0.316	0.203	0.575	6.26	0.0719	3.71	0.45

ON	0.141	0.185	1.44	0.0453	0.0292	0.0188	0.0531	0.578	0.00664	0.343	0.0416

PE	10.7	14	109	3.41	2.2	1.41	4	43.5	0.5	25.8	3.13

QC	0.249	0.326	2.54	0.0797	0.0512	0.033	0.0934	1.02	0.0117	0.602	0.0731

SK	1.98	2.59	20.2	0.633	0.407	0.262	0.742	8.07	0.0927	4.79	0.581



*/
