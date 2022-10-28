#ifndef CONTROL_H
#define CONTROL_H
#include "BookClub.h"
#include "View.h"

using namespace std;
//control class that drives the control flow of the program.
class Control
{
  public:
  	Control();
  	~Control();
  	void launch(); 

  private:
    void init(BookClub*&);
  	BookClub* bClub;
  	View view;

};

#endif
