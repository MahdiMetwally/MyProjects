#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ClubEntity.h"

using namespace std;

LinkedList::LinkedList() : head(NULL),tail(NULL){ }

LinkedList::~LinkedList()
{
	Node* currNode;
 	Node* temp;
  currNode = head;
  while (currNode != NULL) {
  	temp=currNode->next;
  	delete currNode->data;
  	delete currNode;
  	currNode=temp;  
	}
}

void LinkedList::add(Book*& book)
{
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node;
  newNode->data = book;
  newNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  
 while (currNode != NULL) {
    if(newNode->data->lessThan(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

	//if newnode location is at head
  if (prevNode == NULL){
    head = newNode;
    newNode->next = currNode;
  //if newnode location is at tail
  }else if(currNode == NULL){
  	tail=newNode;
  	prevNode->next=tail;
  //if newnode location is in middle
  }else{
    prevNode->next = newNode;
    newNode->next = currNode;
	}
}

bool LinkedList::findBook(int id, Book*& book) const
{

  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;
  
  //iterates through list until data with same identifier as paremeter is found, then returned
  while (currNode != NULL) {
    if (currNode->data->getId() == id){
      book=currNode->data;
      return true;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  return false;
}

//function that takes an index location of node and returns data of that node
void LinkedList::getByIndex(int index, Book*& book) const
{
	int count = 0;
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;
  
  while (currNode != NULL) {
    if (count == index){
      book=currNode->data;
      return;
    }
    prevNode = currNode;
    currNode = currNode->next;
    count++;
  }
}

//function that uses simple accumulator to return size of the linkked list
int LinkedList::getNumBooks() const
{
	int count=0;
	Node*currNode;
	currNode=head;
  
  while (currNode != NULL) {
    count++;
    currNode = currNode->next;
  }
  return count;
}

void LinkedList::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
  //head and tail data is printed again specifying which is which
  cout << "Head Node Data: " <<endl;
  head->data->print();
  cout << "Tail Node Data: " << endl;
  tail->data->print();
}


