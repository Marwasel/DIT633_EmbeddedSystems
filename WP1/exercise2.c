// (C) Nazli moghaddam , Marwa Selwaye, Jonna johansson , group: 16 __ (2023) 
// Work package 1
// Exercise 2
// Submission code: 123569KL 


/*
This program is used for message encryption.
The user enters a message they want to encrypt.
The user enters the number of characters to shift.
The program prints out the encrypted text.
The program is repeated until EOF indicated the program ends, e.g. when the user enters ctrl + z for Windows
*/


//Included libraries
#include<stdio.h>
#include <stdlib.h>

//variables
char message [50]; //user input message up to 50 characters
int i;
char character; //character in message
int shift; //number of characters to shift

// Main function in the program
int main()
{
    do{
        //prints to console when starting the program, user inputs message they what to encrypt
        printf("Enter message: ");

        //scans the message, if message not equal to EOF continue.
        if (scanf("%s", &message) != EOF){

            printf("Enter number of characters you want to shift: ");
            scanf("%d", &shift);

        //loops through every character in the message
        for(i = 0; message[i] != '\0'; i++){
            //assignes a value to every character
            character = message[i];

            //if the character value is between A-Z -->
            if (character >= 'A' && character <= 'Z'){

                //change the value of the character by adding the number of shifts
                character = character + shift;

                //if the character is greater than Z
                if(character > 'Z'){

                    //remove Z add A and subtract 1 to get the correct new value of the character 
                    character = character -'Z' + 'A' -1;
                }

                //save the new character value
                message[i] = character;
            }

            //if the value of the character is between a-z -->
            else if (character >= 'a' && character <= 'z'){

                //change the value of the character by adding the number of shifts
                character = character + shift;

                //if the character is greater than z
                if (character > 'z'){

                    //remove z add a and subtract 1 to get the correct new value of the character 
                    character = character -'z' + 'a' -1;
                }

                //save the new character value
                message[i] = character;
            }

            //input is not a character between A-Z or a-z, return -1
            else{
                printf("Message can only contain characters between A-Z or a-z");
                return -1;
            }
        }

        //prints the new encrypted message 
        printf("%s %s %s","New message: ", message, "\n");
        }
        
        //the message is equal to EOF, return 0
        else {
            return 0;
        }

    //message equals to NULL, return 0
    }while (message != NULL);
    return 0;
}