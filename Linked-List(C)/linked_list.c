// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"

/*
Purpose: insert a new node into the list as the first element
input
head - head of linked list
person - the data of the new person

output
head - head of linked list

return
A pointer to the node that was allocated.  
NULL - if the operation was not successful

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL
2. person is not NULL

*/

ListNode *insertToList(ListNode **head, PersonInfo *person){

//create new node by initializing to NULL and allocate memory for it
ListNode *newNode = NULL;
newNode=malloc(sizeof(ListNode));
newNode->next=NULL;

//provide the new node with its person data
newNode->person=*person;

//if list is empty set the head  to newNode and return newNode
if(*head==NULL){
   *head = newNode;
    return newNode;
 }else{
 //if list not empty set the next node of the newNode to head
    newNode->next=*head;
 //set the head to the newNode and return newNode
    *head=newNode;
    return newNode;
 }
return NULL;
}

///helper function that adds node to the tail of the linked list
ListNode *append(ListNode **head, PersonInfo *person){

//create new node by initializing to NULL and allocate memory for it
ListNode *newNode = NULL;
ListNode *temp = *head;
newNode=malloc(sizeof(ListNode));
newNode->next=NULL;

//provide the new node with its person data
newNode->person=*person;

 //if list is empty set the head  to newNode and return newNode
if(*head==NULL){
  *head = newNode;
   return newNode;
}else{
  //if list not empty iterae through list to reach tail
   while(temp!=NULL){
    if(temp->next==NULL){
     //once the tail is reached set the next node of the tail to newNode and return newNode
     temp->next=newNode;
     return newNode;
    }
    temp=temp->next;
   }
   }
return NULL;
}

/************************************************************************/
/*
Purpose: find the first node in the list with the input family name and insert a new node containing the 
person data into the list.

If there is no node that matches that given family name then the operation is considered a failure.  

Input
head - head of list
familyName - the family name that must be used to find the first matching recrod
person - the person record to insert into the list as new node


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

Assumptions:
familyName is not NULL
person is not NULL

*/


ListNode *insertAfter(ListNode *head, char *familyName, PersonInfo *person){

 //create new node by initializing to NULL and allocate memory for it
ListNode *temp = head;
ListNode *newNode = NULL;
newNode=malloc(sizeof(ListNode));
newNode->next=NULL;

//iterates through list
while(temp!=NULL){
 //if a node in the list has the same family name as the familyName argument
 if(strcmp(temp->person.familyName, familyName) == 0){
   //sets the person data to the newNode
   newNode->person=*person;
   //newNode is placed after the temp node(node that has matching famlly name)
   newNode->next=temp->next;
   temp->next=newNode; 
   return newNode;
   }
  temp=temp->next;
 }
return NULL;
}


/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
person - person data that is stored in the list


return
0 if node was deleted
1 if node was not deleted or list is empty

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty
2. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteFromList(ListNode **head, PersonInfo *person){

//copies the head node to listNode pointer variable
ListNode *newNode=*head;

//if list is empty return 1
if (*head==NULL){
 return 1;
 }

//sets the person return variable to the person data of the node to be deleted if person is not NULL.
if (person!=NULL){
 *person=newNode->person;
 }
//set the head to point to the next node in the list 
*head=newNode->next;

//free the node pointed to by newNode
free(newNode);
return 0;
}

//helper Function
int deleteFromList2(ListNode **head){

//copies the head node to listNode pointer variable
ListNode *newNode=*head;

//if list is empty return 1
if (*head==NULL){
 return 1;
 }

//set the head to point to the next node in the list 
*head=newNode->next;

//free the node pointed to by newNode
free(newNode);
return 0;
}

/************************************************************************/

/*
Purpose: delete the first node with the matching family name
Input
head - the head of the list
familyName - family name of person

output
head - the head of the list
person - data of the person in the node


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

Assumptions
1. familyName is not NULL
2. Function has to be robuse enough to handle cases where head is NULL or the list is empty
3. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteNodeByName(ListNode **head, char *familyName, PersonInfo *person){

ListNode *temp,*currNode,*prevNode;

//if list is empty return 1
if(head==NULL){
 return 1;
}else{
 temp = *head; 
 //if first node in the list has matching familly name call deletFromList function on the list.
 if(strcmp(temp->person.familyName, familyName) == 0){
   deleteFromList(head,person);
   return 0;
  }
 //iterate through list to find matching node
 while(temp->next!=NULL){  
   //if the next node of a node matches the family name
   if(strcmp(temp->next->person.familyName, familyName) == 0){
     //set the prevNode node to the found node and currNode node to the next node
     prevNode=temp;
     currNode = temp->next;
       //if person is not NULL it is set to the person data of the node to be removed (currNode)
      if (person!=NULL){
       *person=currNode->person;
       }
      //remove the currNode by setting the next node of the prevNode to the the next node of the currNode
      prevNode->next=currNode->next;
      //free the node
      free(currNode);
      return 0;
    }
    temp=temp->next;
   }
   return 1;
  }
 }


///////////////////////////////////

//helper Function
int deleteNodeByFullName(ListNode **head,char *firstName, char *familyName){

ListNode *temp,*currNode,*prevNode;

//if list is empty return 1
if(head==NULL){
 return 1;
}else{
 temp = *head; 
 //if first node in the list has matching familly name call deletFromList function on the list.
 if(strcmp(temp->person.familyName, familyName) == 0 && strcmp(temp->person.firstName, firstName) == 0 && temp->person.empOrStudent==STUDENT_TYPE ){
   deleteFromList2(head);
   return 0;
  }
 //iterate through list to find matching node
 while(temp->next!=NULL){  
   //if the next node of a node matches the family name
   if(strcmp(temp->next->person.familyName, familyName) == 0 &&strcmp(temp->next->person.firstName, firstName) == 0 && temp->next->person.empOrStudent==STUDENT_TYPE ){
     //set the prevNode node to the found node and currNode node to the next node
     prevNode=temp;
     currNode = temp->next;
      //remove the currNode by setting the next node of the prevNode to the the next node of the currNode
      prevNode->next=currNode->next;
      //free the node
      free(currNode);
      return 0;
    }
    temp=temp->next;
   }
   return 1;
  }
 }


/************************************************************************/
/*
Purpose: deletes all nodes from the list

input
head - the head of the list

output
head - the head of the list

return
none

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/


void deleteList(ListNode **head){

ListNode *temp=*head;
ListNode *temp_next;
while(temp!=NULL){
 //since temp is to be freed must save the next node of temp to another variable
 temp_next=temp->next;
 //free temp
 free(temp);
 temp=temp_next;
 }
//delete list simply by setting the head to NULL
*head=NULL;
}



/************************************************************************/
/*
Purpose: search for the first node with the matching familyName
Input
head - the head of the list
familyName - family name of person

Output
person - a copy of the person record in the node

return
a pointer to the node that was found.
NULL - if no node was found or list empty


Assumptions
1. familyName is not NULL
2. person can be NULL.  If person is NULL then no coping of the person record is required. 

*/


ListNode *searchByName(ListNode *head, char *familyName, PersonInfo *person){

ListNode *temp=head;
//iterate through list
while(temp!=NULL){
 //if node with matching family name is found return node
 if(strcmp(temp->person.familyName, familyName) == 0){
   // set person to the person data of the found node if person is not NULL
   if (person!=NULL){
    *person=temp->person; 
     }
   return temp;   
   }
 temp=temp->next;
}
//returns NULL if no node is found with matching name
return NULL;
}



/************************************************************************/
/*
Purpose: prints all the records in the list according to their type a student or an employee

input
head - the head of the list
*/


void printList(ListNode *head){

ListNode *temp=head;
//iterates through list
while (temp!=NULL){
 //if person data of node is STUDENT_TYPE, call printStudent on the person data of the node
 if(temp->person.empOrStudent==STUDENT_TYPE){
   printStudent(&temp->person);
 }else{
  //otherwise call printEmployee on the person data of the node
   printEmployee(&temp->person);
   }
 temp=temp->next;
 }
}

/************************************************************************/
/*
Purpose: prints all the students in the list

input
head - the head of the list

Output 
None

Return
None
*/


void printStudents(ListNode *head){

ListNode *temp=head;
//iterates through list
while (temp!=NULL){
 //if person data of node is STUDENT_TYPE, call printStudent on the person data of the node
 if(temp->person.empOrStudent==STUDENT_TYPE){
   printStudent(&temp->person);
   }
  temp=temp->next;
 }
}

/************************************************************************/
/*
Purpose: prints all the employees in the list

input
head - the head of the list

Output
None

Return
None
*/


void printEmployees(ListNode *head){

ListNode *temp=head;
//iterates through list
while (temp!=NULL){
 //if person data of node is EMPLOYEE_TYPE, call printEmployee on the person data of the node
 if(temp->person.empOrStudent==EMPLOYEE_TYPE){
  printEmployee(&temp->person);
  }
  temp=temp->next;
 }
}


/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


unsigned int listSize(ListNode *head){

unsigned int counter=0;
ListNode *temp=head;
//iterates through list
while (temp!=NULL){
  //add 1 to counter if node is ot NULL
  counter++;
  temp=temp->next;
 }
//return the counter
return counter;
}




/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL


*/
int copyList(ListNode *head, ListNode **newListHead){

//deletes newListHead to make sure its empty
deleteList(newListHead);
ListNode *temp=head;
//iterate through list
while (temp!=NULL){
  //adds new node to tail of newListHead using person data of current node
  append(newListHead,&temp->person);
  temp=temp->next;
 }
//if the original list and the newly created list have thee same length return 0(success)
if(listSize(head)==listSize(*newListHead)){
 return 0;
 }
 return 1;
}
/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL

*/
int copyListRecursive(ListNode *head, ListNode **newListHead){

//if the list is not empty add a new node to newListHead using the data of the current node by calling append
if(head!=NULL){
 ListNode *temp=head;
 append(newListHead,&temp->person);
 //recursive calll to copyListRecursive with next node
 copyListRecursive(head->next,newListHead);
 }
//if the original list and the newly created list have thee same length return 0(success)
if(listSize(head)==listSize(*newListHead)){
 return 0;
 }
 return 1;
}

/************************************************************************/
/*
Purpose: removes all the nodes that have student data from the list
input
head - the head of the list

output
head the modified list

return
0 if successful
1 if failed

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/

//helper Function
int numStudents(ListNode **head){

ListNode *temp=*head;
//set accumulator to 0
int counter=0;
//traverse the entire linked list
while(temp!=NULL){
 // if node contains person data that is student add 1 to accumulator
 if(temp->person.empOrStudent==STUDENT_TYPE){
  counter++;
  }
 temp=temp->next;
 }
 //return number of students once traversal is complete
 return counter;
}

int removeStudents(ListNode **head){

//set variable to number of students in the linked list
int stuQuantity=numStudents(head);
// will travers the list stuQuantity number of times 
for (int i=0;i<stuQuantity;i++){
 //sets temp to the head of the list in beginning of each traversal of the list
 ListNode *temp=*head;
 //traverses the list
 while(temp!=NULL){
  //if node has person data of student type it is removed using deleteNodeByFullName iven students full name.
  if(temp->person.empOrStudent==STUDENT_TYPE){
   deleteNodeByFullName(head,temp->person.firstName,temp->person.familyName);
   //if student is removed end traversal
   break;
   }
   temp=temp->next;
  }
 }
}

void generalTravers(ListNode *head,void (*fpntr)(PersonInfo *person)){

ListNode *temp=head;
//traverses the list
while(temp!=NULL){
  //calls the function pointer on the nodes person data
  fpntr(&temp->person);
  temp=temp->next;
  }
}

void printStudentPtr(PersonInfo *person){

//will only print person is they are a student by calling printStudent
if(person->empOrStudent==STUDENT_TYPE){
 printStudent(person);
 }
}



