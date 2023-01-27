// (C) Nazli moghaddam , Marwa Selwaye, Jonna Johansson , group: 16 __ (2023) 
// Work package 1
// Exercise 1
// Submission code: 123569KL 

/* 
The program asks the user to pick a number between 1-5.
Depending on the number the user picks, a different message is printed. 
If the user selects a number < 1 or > 5 the program ends.
*/


//Included libraries
#include <stdio.h> 

//variables
int input; //user input variable

//user input responses
char first [14] = "you pressed 1"; //printed sentence when user press number 1
char second [10] = "this is 2"; //printed sentence when user press number 2
char third [9] = "number 3"; //printed sentence when user press number 3
char fourth [14] = "you pressed 4"; //printed sentence when user press number 4
char fifth [10] = "this is 5"; //printed sentence when user press number 5
char other [23]= "this number is not 1-5"; //printed sentence when user press number lower than 1 or greater than 5

//main function in the program
int main(){

    do{
        //print to console when starting the program
        printf("%s", "Pick a number between 1-5, choose wisely!\n");

        //scans the userinput 
        scanf("%d", &input);

        //if the user picks number 1
        if (input == 1){
            //prints the sentence named first
            printf("%s\n", first);
        }

        //if the user picks number 2
        else if (input == 2){
            //prints the sentence named second
            printf("%s\n", second);
        }

        //if the user picks number 3
        else if (input == 3){
            //prints the sentence named third
            printf("%s\n", third);
        }

        //if the user picks number 4
        else if (input == 4){
            //prints the sentence named fourth
            printf("%s\n", fourth);
        }

        //if the user picks number 5
        else if (input == 5){
            //prints the sentence named fifth
            printf("%s\n", fifth);
        }

        //if the user picks number lower than 1 or greater than 5
        else {
            //prints the sentence named other
            printf("%s", other);

            //exits program
            break;
        }

    //condition that keeps the program running while input is a number between 1-5
    } while (1 <= input <= 5);

    //successful execution of the program
    return 0;
}