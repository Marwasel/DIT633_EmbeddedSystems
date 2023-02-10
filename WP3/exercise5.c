// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 3
// Exercise 5
// Submission code:

/*
This program creates an array containing 10 random numbers between 1-99.
It prints out the array pointer, the first and last integer in the array, the size of an integer and the size of the whole array.
Then it uses a pointer to print each integer value in the array, and the integer value * 2.
*/


//Included libraries
#include <stdio.h>
#include <stdlib.h>

//Constants
#define MAX 10 //number of integers in the array


//###### Main program ####### 
int main() {
  int array[MAX]; 
  int i;

  // Fill the array with random integers from 1 to 99
  for (i = 0; i < MAX; i++) {
    array[i] = rand() % 99 + 1;
  }

  // Print the address of the array (pointer)
  printf("\nThe value of the address of the array (pointer) is: %p\n", array);
  // Print the first integer in the array
  printf("First integer in the array is (array[0]): %d\n", array[0]);
  // Print the last integer in the array
  printf("The last integer in the array is: %d\n", array[MAX - 1]);
  // Print the size of an integer
  printf("The size of an integer (number of bytes) is: %ld\n", sizeof(array[0]));
  // Print the size of the whole array in bytes
  printf("The size of the whole array in bytes is: %ld\n\n", sizeof(array));

  // Use a pointer to print each integer value and its double
  int *ptr = array;
  for (i = 0; i < MAX; i++) {
    printf("Integer value at index %d: %d\n", i, *ptr);
    printf("Double of the integer value at index %d: %d\n\n", i, (*ptr) * 2);
    ptr++;
  }

  return 0;
}