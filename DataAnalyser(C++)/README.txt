program and revision authors: Mahdi Metwally 101082004

purpose:
-The purpose of this program is to generate a set of reports based on data from Canadas
 National Graduate Survey from the years 2000-2015. The program will read the said 
 data from a the file "grad.dat" read and store each line to generate a report based on the users choice.

source/header/data files:

Header Files:
-ReportGenerator.h
-Data.h
-Property.h
-PartialCollection.h
-ReportArray.h
-Control.h
-View.h

Source Files
-ReportGenerator.cc
-Report1.cc
-Report2.cc
-Report3.cc
-Report4.cc
-Report5.cc
-Data.cc
-ReportArray.cc
-Control.cc
-View.cc
-main.cc

Data Files:
-Makefile
-grad.dat

compilation and launching instructions:
-untar the ExamSubmission.tar file by entering $tar -xvf ExamSubmission.tar into the command prompt
-once the ExamSubmission.tar is untar'd enter $make in the command prompt where all the provided Exam Submission files are in the current directory
-enter $./E1 into the command prompt to execute the program.
-to test for memory leaks enter $valgrind --leak-check=yes ./E1

Report4 Description:
-Report 4 produces a total of 4 lists, one for each year in the database. Each list presents the proportion of employed graduates by 
 gender,region, and year compared to all graduates in that region and year, regardless of degree
-(Row=Region,Column=Gender) * number of years(4)
 EXAMPLE: if you wanted to find the proportion of employed males in NL (regardless of degree) compared to all graduates in 
 NL (regardless of degree) in 2005 then you would go down to the list with the title "For Year: 2005" and find the intersection
 of males (col) and NL (row).
 
Report5 Description:
-Report 5 only produces one list but it is the largest from all the other because it compares all possible region combinations (11*11)
 the list reports the proportions of female employees regardless of degree and year(in the y) compared to all graduates regardless of
 degree and year (in the x). Each cell represents the female employees of the column region compared to all graduates in the row region.
 EXAMPLE: if you wanted to find the proportion of female employees in NL (regardless of degree and year) compared to all 
 graduates in QC (regardless of degree and year) then i would look at the top for NL and find where it intersects with QC.

NOTES and LIMITATIONS:
-The Abstract class ReportGenerator consisits of not one, but two pure virtual functions
-this includes the execute function and the loadPArtial function. The loadPartial function
 loads data to a partial collection. Each concrete subclass with Report5 as an exeption implements this 
 function and this is mainly because it be large and messy if i made it a ReportGenerator class function. 
 This function is called in the constructor of each concrete sub class of ReportGenerator (except Report5) 
 which means its downside is that all ReportGenerator concrete subclasses must be created for the program to work.
 






