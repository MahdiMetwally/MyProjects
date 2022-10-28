#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>

using namespace std;
//view class that responsible for most communication with user
class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
