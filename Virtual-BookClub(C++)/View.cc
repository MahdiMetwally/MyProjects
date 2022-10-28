#include <iostream>
#include <string>
#include "View.h"

using namespace std;

void View::showMenu(int& choice)
{
  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print the data for all the Members in the Book Club" << endl;
  cout << "  (2) Print the data for all the Books in the Book Club" << endl;
  cout << "  (3) allow club member to rate a book, from 1 to 10" << endl;
  cout << "  (4) compute and print best rated Book, and most rated Book" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 4) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}



