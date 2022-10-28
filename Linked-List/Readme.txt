Mahdi Metwally 101082004

Purpose of software:
to manipulate records of employees and students at Carleton by utilizing linked list to accomplish the task.

Developer: Mahdi Metwally, Development Date: 2019-11-10

How the software is organized (partitioned into files):
The software consists of 5 file,3 <.c> files and 2 <.h> files.
the 3 <.c> files consist of main.c, linked_list.c, and person.c.
The 2 <.h> files are linked_list.h and person.h, they provide definition 
of functions and structures.

Instruction on how to compile the program (give an example)
running main.c:

create out executible out file by compiling main.c, linked_list.c, person.c together
>>gcc -g main.c linked_list.c person.c

execute out file
>>./a.out

To test for data leaks:
>>valgrind --leak-check=yes ./a.out

Any issues/limitations problem that the user must be aware of:
-none that I know of.

Instructions explaining how to use the software:
1.open the main.c file
2.manipulate linked lists containing PersonInfo data by using the provided functions in linked_list.c
3.compile the program files to be executed (>>gcc -g main.c linked_list.c person.c)
4.run the program (>>./a.out)

