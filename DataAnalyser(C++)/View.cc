#include <iostream>
#include <string>
#include "View.h"
using namespace std;

View::View() 
  : counter(0){}


//basic menu display function
void View::showMenu()
{ 
  cout << endl;
  cout << "For info on reports refer to README.txt: " << endl;
  cout << "What would you like to do:"<< endl;
  cout << "Enter your selection: " << endl;
}

//basic user input function (checks for invalid data)
void View::userInput(int& choice,int size)
{
  cin >> choice;
  if (choice == 0)
    return;
  while (choice < 1 || choice > size) {
    cout << "Invalid input, Enter your selection: " << endl;
    cin >> choice;
    if(choice==0){
      return;
   }
 }
}


//basic print function that displays given string to console
void View::printStr(string str)
{
  cout << str;
}


//function that prints option number alongside report generator report name
void View::printChoice(string r,int size)
{
	cout << "(" << counter << ") " << r << endl;
	counter++; 
	if(counter==size+1){
		cout << "(0) Exit" << endl; 
	}
}


//function that resets option number counter
void View::resetCounter()
{
  counter=1;
}



