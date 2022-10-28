#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>

/***************************************************************/
// Structures


// holds the thread information for each thread
typedef struct threadData { 
    pthread_t thread_id;			// system thread id
    int tid;                        // inernal id assigned by the program
} ThreadData; 


/******************************************************************/
// Define


#define NUM_THREADS 5


/******************************************************************/
// Function Prototypes

int numPrimeFactors(unsigned long number);

/***************************************************************/
// Global Variables
volatile unsigned long totalNumPrimeFactors = 0;		// global value that holds the final result
unsigned long *recordsToProcess = NULL;     // array that will hold al the numbers to be processed
int numRecords = 0;                         // number of records in the array recordsToProcess
unsigned long *tempRecordsToProcess=NULL;
int numRecordsLarge = 0;
int indexes[100];
sem_t mutex;
pthread_t reserveThreads[100];
int sentinel=0;
int threadCounter=0;


/*************************************************************/
/*
Purpose compute the number of prime factors of a given number
input:
number - the number to be processed

output: 
None

Return:
the number of prime factors of number
*/
int numPrimeFactors(unsigned long number)
{
    unsigned long i;
    unsigned long quot;
    int numFactors = 0;

    // base case
    if (number == 1) return(0);
    if (number == 2 || number == 3) return(1);

    // check for the first factor until integer is less then number 
    for (i = 2; i <= number; i++) {
        if (i % 1000 == 0) {        
            if (number / i == 1) return(1);   // cannot have any more factrs other than self
        }
        if (number % i == 0) {
            quot = number / i;
            if (quot == 1) return(1);   // cannot have any more factrs other than self
            numFactors = 1 + numPrimeFactors(quot);
            return(numFactors);
        }
    }
    return(0);
}
/*************************************************************************/
//Purpose: the main function of the threads

void *threadMain(void *arg){

unsigned long query = *((unsigned long *)arg);

//wait on the mutex,will wait until it is the threads turn to change the shared resource
if (sem_wait(&mutex) < 0) {
 printf("Error: on semaphore wait.\n");
 exit(1);
}

//accumulate return value of numPrimeFactors to totalNumPrimeFactors, which will 
//store the total number of prime factors
totalNumPrimeFactors+=numPrimeFactors(query); 

//release lock on the mutex and allow other threads to access shared resource
if(sem_post(&mutex) < 0) {
 printf("Error: on semaphore post.\n");
 exit(1);
 } 
}

/*************************************************************************/
int main(int argc, char ** argv){

//array that will store first five threads
pthread_t tid[NUM_THREADS];
   
// check command line is correct - if not show how to use the program
if (argc < 3) {
  printf("please enter a valid filename - Usage: ./prime_threads fileName index1 index2\n"); 
  return(1);
}else{
   FILE *fd;
   //attempt to open a file given the provided file name
   if((fd = fopen(argv[1], "r")) == NULL) {
      // File does not exist return 1
      printf("file %s does not exist\n",argv[1]);
      return(1);
   }else{
      //file exists
       if(atoi(argv[2])==-1){
          //will read all numbers in file 
          //set file position indicator to end
          fseek(fd, 0, SEEK_END);
          //set numRecords to the size of the file   
          numRecords= ftell(fd)/sizeof(unsigned long);
          //set file position indicator to the beginning of the file for reading
	  fseek(fd, 0, SEEK_SET);
          //allocate memory for array that will hold the numbers (recordsToProcess)
	  recordsToProcess=malloc(sizeof(unsigned long)*numRecords);
          //read the file and store elements into recordsToProcess
          fread(recordsToProcess, sizeof(recordsToProcess), numRecords, fd);
 	  fclose(fd);
       }else{
          //read numbers at given index
          numRecords=argc-2;
   	  //will store provided indexes into an array
          for (int o=0; o<numRecords; o++){
            indexes[o]=atoi(argv[2+o])-1;
            }
          //allocate memory for array that will hold the numbers (recordsToProcess)
          recordsToProcess=malloc(sizeof(unsigned long)*numRecords);
          for (int i=0; i<numRecords; i++){
            unsigned long temp=0;
            //set file position indicator to the target value in the file for reading
   	    fseek(fd,sizeof(unsigned long)*indexes[i], SEEK_SET);
            //read the file element and store it into recordsToProcess
            fread(&temp, sizeof(unsigned long),1, fd);
            recordsToProcess[i]=temp;
            }
 	  //ensures first five elements in the recordsToProcess array has no garbage data
          //as all other values that have not been read from the file are set to 0
          if(numRecords<5){
            for (int i=numRecords; i<5; i++){
              recordsToProcess[i]=0;
              }
           }
        }
} 
        //init mutex 
        if (sem_init(&mutex, 0, 1) < 0) {
	  printf("Error: on semaphore init.\n");
	  exit(1);
	  }

        //read the records from the file
	  //done above

        //initialize the  first five threads
	for(int i=0;i<NUM_THREADS;i++){
          pthread_create(&tid[i], NULL, threadMain, &recordsToProcess[i]);
  	  }
        
	//initialize all other threads if user has requested more than 5 values
	if(numRecords>5){
	  for(int i=5;i<numRecords;i++){
            pthread_create(&reserveThreads[threadCounter], NULL, threadMain, &recordsToProcess[i]);
            threadCounter++;
  	    }
          } 

         //wait for the threads to terminate
	 for(int i=0;i<NUM_THREADS;i++){
           pthread_join(tid[i], NULL);
  	   }

         //wait for the rest of the threads to terminate if user has requested more than 5 values
	 if(numRecords>5){
	   for(int i=0;i<threadCounter;i++){
             pthread_join(reserveThreads[i], NULL);
  	     }
           }

         //print the number of prime factors in the main thread once all other threads return
         printf("Number of Prime Factors: %ld\n",totalNumPrimeFactors); 
    }
}




