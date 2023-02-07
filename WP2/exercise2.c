// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 2
// Exercise 2
// Submission code:RG0456-v


/*
This program contains two functions:

The first function creates a linked list that contains 5 records.
Each record is given a random number between 0-100.
Then it prints the random list.

The second function adds a new record to the first position in the list.
Then the list with the new added number is printed.
*/

//Included libraries
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//Constants
#define MAX 5 // The number of elements in the linked list 
#define limit 100 // The maximum random number to generate
#define firstNumber 1 // The number to add to the beginning of the list
 
//Data structure definition for linked list node
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 

// Function declarations
REGTYPE* random_list(void); //random list
REGTYPE* add_first(REGTYPE* temp, int data); //list with firstNumber added
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; // Counter for the first print of the list
    int newNr=0; // Counter for the second print of the list
 
    REGTYPE *act_post , *head=NULL; 
 
    srand(time(0));  //Random seed

    head=random_list(); 
    act_post=head; 

    // Print the generated linked list
    printf("Random list: \n");
    while( act_post!=NULL){ 
           printf("Post nr %d : %d \n" , nr++, act_post->number); 
           act_post=act_post->next; 
    }  

    head=add_first(head, firstNumber); 
    act_post=head; 

    // Print the linked list with the firstNumber added
    printf("\nNumber added to beginning of list: \n");
    while( act_post!=NULL){ 
           printf("Post nr %d : %d\n" , newNr++, act_post->number); 
           act_post=act_post->next; 
    }    
 
       
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 


 // Function to generate a random linked list
 REGTYPE* random_list(void ){ 
    int nr, i=0; 
    REGTYPE *top, *old, *item; // pointers: top = first element in the list, old = last element, item = current item
    top = NULL;

    // Generate MAX number of random linked list elements
    for (i = 0; i < MAX; i++){
        item = (REGTYPE *)malloc(sizeof(REGTYPE)); //allocating memory for item
        nr = rand() % limit; // Generate a random number between 0 and 100
        item->number = nr; //assigning the random numbers to 'number' 
        item->next = NULL; //next node is NULL

        // If this is the first element, assign this item as 'top'
        if (top == NULL) {
            top = item; 
            top -> prev = NULL; //previous node is NULL
        } 

        // If this is not the first element, add to the end of the list
        else {
            old = top; // the old pointer is set as the current top

            //while the next node is not NULL
            while (old->next != NULL) {
                old = old->next; // set old to the next item in the list
            }
            item->prev = old; // set the current item's previous variable to the old item
            old->next = item; // set the end of the list's next to the current item
        } 

    }
     
    return(top); //return top
} 

//==========================================================  


//Function to insert a number to the first position of the linkedlist 
REGTYPE* add_first(REGTYPE* temp, int data){ 
    REGTYPE *newTop = malloc(sizeof(REGTYPE)); //allocate space for new top
    newTop->number = data; //sets the new top value to data
    newTop->next = temp; // Makes the new tops next pointer point to the previous head of the linked list
    temp = newTop; //assign the new top to temp

    return temp;  // Returns new head
 
} 