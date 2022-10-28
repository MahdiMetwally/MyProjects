#ifndef CLUBENTITY_H
#define CLUBENTITY_H
#include <string>
//parent class for Book and Member class
using namespace std;

class ClubEntity
{
  public:
    ClubEntity();
    ~ClubEntity();
    int getId() const;

  protected:
		static int nextId;
    int    id;
	
};

#endif
