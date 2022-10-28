E1:	main.o Control.o ReportGenerator.o Report1.o Report2.o Report3.o Report4.o Report5.o Data.o Property.h ReportArray.o PartialCollection.h View.o
	g++ -o E1 main.o Control.o ReportGenerator.o Report1.o Report2.o Report3.o Report4.o Report5.o Data.o Property.h ReportArray.o PartialCollection.h View.o

main.o:	main.cc
	g++ -c main.cc
		
Control.o:	Control.cc Control.h
	g++ -c Control.cc

ReportGenerator.o:	ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc
	
Report1.o:	Report1.cc ReportGenerator.h
	g++ -c Report1.cc
	
Report2.o:	Report2.cc ReportGenerator.h
	g++ -c Report2.cc
	
Report3.o:	Report3.cc ReportGenerator.h
	g++ -c Report3.cc
	
Report4.o:	Report4.cc ReportGenerator.h
	g++ -c Report4.cc
	
Report5.o:	Report5.cc ReportGenerator.h
	g++ -c Report5.cc
	
Data.o:	Data.cc Data.h
	g++ -c Data.cc
	
ReportArray.o:	ReportArray.cc ReportArray.h
	g++ -c ReportArray.cc
	
View.o:	View.cc View.h
	g++ -c View.cc
	
	
clean:
	rm -f *.o E1
	
