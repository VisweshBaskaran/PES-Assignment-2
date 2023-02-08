# PES-Assignment-2

Author: Visweshwaran Baskaran.
Contact email address: viba5388@colorado.edu
Tools used in this project: Microsoft Visual Studio Code, GCC Compiler
Language: C

This project implements a stack using linked list and a circular buffer using an array in C. A stack, a LIFO object is used for memory management and expression evaluations (parantheses matching). A queue, a FIFO object is used when a part of a code (possibly an interrupt) is producing data (enqueues) and another part of code consumes data (dequeues). The latter find its use while reading data byte by byte from a UART. This code was developed with an emphasis for embedded device use case, to have a memory footprint as light as possible. Thereby using malloc unfrequently (only when required), a node can be created but not be used (does not point to any data element)

Important files:


APIs implemented to achieve the above task:

LIFO APIs:

lllifo_t *lllifo_create(int capacity) :  
Creates a Stack using linked List of "capacity" number of nodes. Returns the created linked list to the function call. 
Makes use of malloc() to allocate memory for each node. free() and the API llifo_destroy is used to avoid memory leaks.

int lllifo_push(lllifo_t *lifo, void *element) :
Pushes the element passed onto the stack at the first created but unused node. Returns the length of the updated stack

void *llfifo_pop(lllifo_t *lifo) :
Pops the element present at the last created and used node. Returns the popped data element.

int lllifo_length(lllifo_t *lifo) :
Returns the current length of the Stack. i.e the number of created and used nodes

int lllifo_capacity(lllifo_t *lifo) :
Returns the current capacity of the Stack. i.e the number of created nodes that are both used and unused

void lllifo_destroy(lllifo_t *lifo) :
Frees up all the memory that was allocated for the stack (LIFO) implementation


FIFO APIs: 
size_t cbfifo_enqueue(void *buf, size_t nbyte);
size_t cbfifo_dequeue(void *buf, size_t nbyte);
size_t cbfifo_length();
size_t cbfifo_capacity();


