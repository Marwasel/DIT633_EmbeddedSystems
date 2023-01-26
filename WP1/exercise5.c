// (C) Nazli moghaddam , Marwa Selwaye, Jonna johansson , group: 16 __ (2023) 
// Work package 1
// Exercise 5 
// Submission code: 123569KL 
#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab ) {   
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
   int i;
   // Iterate through the tab array, using the rand() function to assign a random number between 0-100 to each element
    for (i = 0; i < MAX; i++) {
        tab[i] = rand() % MAXNUMBER;
    }
}

void count_frequency(int *tab, int *freq ) {    
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
 int i;
 //  initializes all the elements of the freq array to 0. The loop starts with 
 // the variable i set to 0 and continues as long as i is less than MAXNUMBER. 
    for (i = 0; i < MAXNUMBER; i++) {
        freq[i] = 0;
    }
    //  iterates through the table array, counting the occurrences of each number. 
    // The loop starts with the variable i set to 0 and continues as long as i is less than MAX.
    for (i = 0; i < MAX; i++) {
        freq[tab[i]]++;
    }
}

void draw_histogram(int *freq ) {

     int i, j;
     // prints a header "Number Frequency"
    printf("Number\tFrequency\n");
    // iterate over each element in the freq array, 0 to less than MAXNUMBER
    for (i = 0; i < MAXNUMBER; i++) {
        //  checks if frequency of current number is not equal to 0
        if (freq[i] != 0) {
        // prints numbers using a format specfier(d),and two tabs to create space between number and freq  
            printf("%d\t", i);
            // print out the frequency count as x times.
            for (j = 0; j < freq[i]; j++) {
                printf("x");
            }
            // new line after each number
            printf("\n");
        }
    }
}

// ------ Function definitions   ---------- 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly 
int main (void){ 
 
    int table[MAX], n ; 
    int frequency[MAXNUMBER]; 
// Call the create_random function to generate a set of random numbers and fill the table 
    create_random(table);
    // Call the count_frequency function to count the occurrences of each number in the table 
    count_frequency(table, frequency);
    // Call the draw_histogram function to display a histogram of the frequency counts for each number
    draw_histogram(frequency);

} 