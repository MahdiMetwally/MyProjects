#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>
using namespace std;
//the only class that will read iput from the user and print output to the screen

class View
{
  public:
    View();
    void showMenu();
    void userInput(int&,int);
    void printStr(string);
    void printChoice(string,int);
    void resetCounter();
    
  private: 
    int counter;
};

#endif
