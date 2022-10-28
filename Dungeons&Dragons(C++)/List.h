#ifndef LIST_H
#define LIST_H

#include "Potion.h"

class List
{
  class Node 
  {
    public:
      Potion* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void add(Potion*&);
    void popFirst(Potion*&);
    bool empty();

  private:
    Node* head;
};

#endif
