// FILE IS main.c

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"
#include "person.h"

#define CONTINUE {printf("hit <cr> to continue \n"); getchar();}

void populatePerson(PersonInfo *person);

int main(int argc, char* argv[])
{
	
        PersonInfo person;
	ListNode *head = NULL;
	ListNode *newListHead = NULL;
	ListNode *p = NULL, *q = NULL;
        char familyName[64];
	int i;
        int rc = 0;
	
      ////////////////////////////

	for (i = 0; i < 20; i++) {
	// add code for testing
	  populatePerson(&person);
          p = insertToList(&head,  &person);
      	  //prints family name of all head nodes
	  //printf("%s\n",head->person.familyName);
	}
	
	
	printf("\n");
	
      //prints entire linked list
      printList(head);

      ////////////////////////////

	printf("\ntest insert after \n");

        //testing insertAfter

	if (p != NULL) {
	  for (i = 0; i < 4; i++) {
	    populatePerson(&person);
	    p = insertAfter(head, p->person.familyName, &person);
	  }
	}

    
   //prints entire linked list
   printList(head);
 
    ////////////////////////////

    CONTINUE;
    
    //test deleteFromList
    printf("\ntest deleteFromList\n");

     deleteFromList(&head,&person);
     deleteFromList(&head,&person);
     deleteFromList(&head,&person);
     deleteFromList(&head,&person);
     deleteFromList(&head,&person);
     deleteFromList(&head,&person);
	
   //prints entire linked list
   printList(head);



    ////////////////////////////

    //test deleteNodeByName
     printf("\ntest deleteNodeByName\n");

     rc = deleteNodeByName(&head, "Tayloy", &person);
     rc = deleteNodeByName(&head, "Tayloy", &person);

     printf("deleteAfter rc = %d \n",rc);


    //prints entire linked list
    printList(head);

    ////////////////////////////



    CONTINUE;

    ////////////////////////////

	//test searchByName
	printf("\ntest searchByName\n");

	p = searchByName(head, "King", &person);

	if (p != NULL) {
	  printf("\n found name to delete \n");
	  printEmployee(&p->person);
	  printf("\n");
	  strncpy(familyName, p->person.familyName, NAME_LENGTH-1);
	  familyName[NAME_LENGTH-1] = '\0';
	  deleteNodeByName(&head, familyName, &person);
	}


        //prints entire linked list
        printList(head);

       ////////////////////////////

	CONTINUE;

	printf("\n\n List size \n\n");

	printf("%d\n",listSize(head));

	printf("\n duplicate list \n\n");

  	//copyListRecursive(head, &newListHead);
	copyList(head, &newListHead);
	printList(newListHead);
	

	printf("\n duplicate list recursive \n\n");

        deleteList(&newListHead);
  	copyListRecursive(head, &newListHead);
	printList(newListHead);


	CONTINUE;


	printf("\n\n print students \n\n");
	printStudents(newListHead);

	printf("\n\n print employees \n\n");
	printEmployees(newListHead);
	CONTINUE;

	printf("\n\n remove students \n\n");
	removeStudents(&head);
	printList(head);
	CONTINUE;

	printf("\nprinting students using traverse function\n");
	//in order to test, remove removeStudents function call above
	generalTravers(head,printStudentPtr);

        //test deleteList
	printf("\ntest deleteList\n");
	//deletes both linked lists
	deleteList(&head);
	deleteList(&newListHead);
	printList(head);
        printf("\n");
	printList(newListHead);


	//	getchar();


	return 0;

}


	

/***************************************************************************/
/* purpose: the function populate the person info

input/output
struct personInfo *p - allocated memory to the struct pointer which the function assigns values.




*/

void populatePerson(PersonInfo *person)
{
	static int initRand = 0;
	int j;
	char *first[10] = { "John", "Don", "Edna", "Bev", "Miya", "Oliver", "James", "Liam", "Emily", "Alice"  };
	char *family[10] = { "Broker", "Smith", "Tower", "Little", "Bronson", "Brown", "Tayloy", "King", "Green", "Baker"   };

	if (!initRand) {
		srand(1557);
		initRand ++;
	}
	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 10;
	// copy the first name to the structure pointed by p using strcpy
	strncpy(person->firstName, first[j], NAME_LENGTH);

	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 10;
	// copy the family name to the structure pointed by p using strcpy
	strncpy(person->familyName, family[j], NAME_LENGTH);

	// populate the student id using the random numnber in the range of 0-4096  
	person->id = rand() % 150;

	// populate either the student field of the employee field
	if (rand() % 100 < 20) {
		// employee record
		person->emp.salary = rand() % 50000 + 50000;
		person->emp.yearsOService = rand() % 41;
		person->empOrStudent = EMPLOYEE_TYPE;
	}
	else {
		// student record
		person->stu.gpa = rand() % 9 + 4;
		person->stu.numCompletedCourses = rand() % 31 + 10;
		person->stu.numRequiredCourses = 40;
		person->empOrStudent = STUDENT_TYPE;

	}

}






