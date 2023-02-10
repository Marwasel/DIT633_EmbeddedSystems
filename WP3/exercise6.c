// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 3
// Exercise 6
// Submission code:RG0456-v

#include <stdio.h>
#include <string.h>

#define MAX 20 // the maximum amount of characters 

void copyString(char first[], char second[]) { //first is the first array of string
// second is the copied version of the string array
    int i;
    for(i = 0; first[i] != '\0'; i++) { // looping through the first array until reaching a null character
        first[i] = second[i]; // copy the first array of sring to the seond array of the string
    }
    second[i] = '\0';
}

int main() {
    char string1[MAX + 1]; // getting the maximum number of characters for string 1
    char string2[MAX + 1];  // getting the maximum number of character for string 2 

    printf("Enter a string with a max characters of 20 \n");
    scanf("%20s", string1);

    strcpy(string2, string1); // copy the first string to the second string
     printf("Copied string using strcpy(): %s\n", string2);

    copyString(string2, string1); // use the function copyString to copy the first string to the second

    printf("Copied string custom function : %s\n", string2);

    return 0;
}