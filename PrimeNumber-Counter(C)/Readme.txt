Purpose of multiFactor(part 1):

the program will take a binary file and compute the 
total number of prime factors in each individual number in the file.
this program will utilize child processes spawning, morphing, and signals to complete the task.

Purpose of multithread(part 2):

the program will take a binary file and indices of the numbers 
that will be processed in the given file. The program will compute the 
total number of prime factors in each individual number requested by the user.
the program will utilize threads and synchronizing using mutex to complete the task.

Developer: Mahdi Metwally, 101082004

Development date: 11/29/2019

How the software is organized:
A5 file resources:

createBinary.c -a program that creates a binary file for testing the prime number program 
multiFactor.c -multiSpawn program source code (functionality explained above)
numPrimeFctors.c -a program that returns the number of prime factors that a given number has. 
prime_threads.c -multithread program source code (functionality explained above)
prime.bin -binary file that contains 12 unsigned numbers for testing the multiSpawn and multithread program
prime.txt -a file that contains 12 unsigned numbers in ASCII format. The numbers correspond to the numbers in the file
prime.bin
Readme.txt -text file that contains information on software for user (this file)

Instruction on how to compile the program:

How to compile and run multiFactor(part 1):
>>make -f Makefile1
>>./multiSpawn prime.bin 
**to use another binary file instead use same format as above by replacing prime.bin with other file name**

How to compile and run multithread(part 2):
>>make -f Makefile2
>>./multithread prime.bin <index here>
**to use another binary file instead use same format as above by replacing prime.bin with other file name**


Any issues/limitations problem that the user must be aware of: 

N/A

Instructions explaining how to use the software:

How to use and run multiFactor(part 1):

once the file is compiled using the provided makefile as show above,
simply execute the program by entering ./multiSpawn prime.bin into the command
prompt (executable must be in working directory).press enter and the file will
print the total number of prime factors of each long in the binary file prime.bin.
 *NOTE* executable must be in current working directory to run.

How to use and run multiFactor(part 1):

once the file is compiled using the provided makefile as show above,
simply execute the program by entering ./multithread prime.bin <indices> into the command prompt.
Enter your desired indices instead of <indices> as shown above and the longs located at the provided 
indices in the binary file prime.bin will be computed and the total number of prime factors of these
longs will be printed. Alternately you can enter -1 as an index in the place of <indices> shown
above and the total number of prime factors of all longs in the file will be computed and printed.
 *NOTE* executable must be in current working directory to run.

