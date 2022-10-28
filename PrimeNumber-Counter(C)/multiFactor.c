#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>
#include<sys/wait.h> 
#include <signal.h>

void handleSig1(int);
static int cResponse=0;
int numRecords;
int total=0;

int main(int argc, char *argv[]){

//instal signal handler
signal(SIGUSR1, handleSig1);

unsigned long *arrayOfPrime=NULL;
int status,waitID;
int sumChild=0;
int parent =getpid();
int cpid;
int counter=-1;
int counter2=0;
int allspawned=0;
int *children=NULL;


//check to see if file was provided in command line argument
if (argc < 2) {
  printf("please enter a valid filename - Usage: ./multiFactor fileName\n"); 
  return(1);
}else{
  FILE *fd;
  //open the file provided using the provided filename
  if ((fd = fopen(argv[1], "r")) == NULL) {
    // File does not exist return 1
    printf("file %s does not exist\n",argv[1]);
    return(1);
  }else{
    //set file position indicator to end
    fseek(fd, 0, SEEK_END);
    //set numRecords to the size of the file
    numRecords= ftell(fd)/sizeof(unsigned long);
    //allocate memory for arrayOfPrime and children (will hold all children processes)
    arrayOfPrime=malloc(sizeof(unsigned long)*numRecords);
    children=malloc(sizeof(int)*numRecords);
    //set file position indicator back to beginning for reading
    fseek(fd, 0, SEEK_SET);
    //read the file and store into arrayOfPrime
    fread(arrayOfPrime, sizeof(arrayOfPrime), numRecords, fd);
    ///close the file once done reading
    fclose(fd);
  }
}

//function that morphs the child proccess into numPrimeFactors
int morph(char *number){

int childPID;
char *args[2];
args[0]="numPrimeFactors";
args[1]=number;
//will stop child proccess from continuing this code and begin executing numPrimeFactors
childPID = execv("./numPrimeFactors",args);
return -1; //if failed

}

//once this loop terminates all children will have spawned
for(int i=0;i<numRecords;i++){
  //will execute if is parent proccess
  if (getpid()==parent){
    //creates child and stores into children array
    children[i]=fork();
    //signal when ALL children have finished spawning
    if(i==numRecords-1 && getpid()==parent){
      printf("All children have spawned!\n\n");
    }
   counter++;
  }
}

//will loop for numRecords times to morph all children that have been created in previous loop
for(int i=0;i<numRecords;i++){
  if(children[i]==0){
    //will execute if is child process
    char input[100];
    sprintf(input, "%lu", arrayOfPrime[counter]);
    char *ptrInput=input;
    //child process calls morph function with given long value from arrayOfPrime
    morph(ptrInput);
    exit(0);
  }
}


//will wait for a child numRecords times
for (int i=0;i<numRecords;i++) {
 //send signal to handler
 kill(getpid(),SIGUSR1);
 //wait for a child to respond
 waitID = waitpid(-1,&status,0);
 //get exit code from child and add to accumulator
 total+=WEXITSTATUS(status);
 //add 1 to cResponse which will hold the number of children that have responded
 cResponse++;
 }

//once loop is done call waitpid and if it returns -1 then all children hae responded
waitID = waitpid(-1,&status,0);
if(waitID=-1){
 //all children have responded process will terminate
 printf(" Finished Processes: %d, Still Working: %d\n",cResponse,numRecords-cResponse);
 printf("total number of prime factors of all the input numbers: %d\n",total);
 printf("All children are done. Process %d terminating.\n", getpid());
 }
}

//signal handler
void handleSig1(int signal){
printf(" Finished Processes: %d, Still Working: %d\n",cResponse,numRecords-cResponse);

}


