#include <iostream>
#include <iomanip>
#include "ClubEntity.h"

using namespace std;

//unique identifier that is automatically generated for Book and Member child classes
int ClubEntity::nextId = 1;

ClubEntity::ClubEntity() 
  :id(nextId++) { }
  
ClubEntity::~ClubEntity() {}

//simple id getter function inhereted by Book and Member class
int ClubEntity::getId() const { return id; }




