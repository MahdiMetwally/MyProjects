#include <iostream>
using namespace std;

#include "List.h"

List::List() : head(NULL) { }

List::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;
  //delete data
  while (currNode != NULL) {
    delete currNode->data;
    currNode = currNode->next;
  }

  currNode = head;
  //delete nodes
  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

void List::add(Potion*& potion)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = potion;
  tmpNode->next = NULL;

  prevNode = NULL;
  currNode = head;
  
  while (currNode != NULL) {
    if (potion->getID() < currNode->data->getID())
      break;
 
    prevNode = currNode;
    currNode = currNode->next;
  }  

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;
    tmpNode->next  = currNode;

}



//function removes first element in inked list and returns it using parameters
void List::popFirst(Potion*& potion){
 if (head!=NULL){
  Node* currNode=head;
  head=head->next;
  potion=currNode->data;
  delete currNode;
 }
}

bool List::empty(){
 return (head==NULL);
}


