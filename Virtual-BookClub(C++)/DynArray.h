#ifndef DYNARRAY_H
#define DYNARRAY_H
#include "ClubEntity.h"
#include "Member.h"

using namespace std;
//collection class that stores a dynamically allocated array of Member pointers
class DynArray
{
  public:
    DynArray();
    ~DynArray();
    void add(Member*&);
    void print() const;
    bool findMember(int, Member*&) const;

  private:
    Member** memberList;
    int   size;
};

#endif

