#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Book.h"
#include "ClubEntity.h"
//singly linked list class that stores book object pointers and has a head and tail
using namespace std;

class LinkedList
{
  class Node
  {
    public:
      Book* data;
      Node* next;
  };

  public:
    LinkedList();
    ~LinkedList();
    void add(Book*&);
    bool findBook(int, Book*&) const;
    void getByIndex(int, Book*&) const;
    int getNumBooks() const;
    void print() const;

  private:
    Node* head;
    Node* tail;

};

#endif

