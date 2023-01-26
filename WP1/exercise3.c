// (C) Nazli moghaddam , Marwa Selwaye, Jonna johansson , group: 16 __ (2023) 
// Work package 1
// Exercise 3
// Submission code: 123569KL 



/*
The computer generates a random number between 1 and 100.
The user is prompted to guess the number and the input is read using the scanf function.
The computer checks if the user's guess is too low, too high, or if the guess is correct, 
and prints the appropriate message.
If the user's guess is not correct and the number of guesses is less than the maximum allowed, 
the user is prompted to guess again.
The game ends when the user's guess is correct, or the maximum number of guesses is reached.
The user is prompted to play again or end the game.
The program checks if the input is valid (1 to 100) and prints an error message if it's not. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// represents max times a user is allowed to guess
const int maxNumber = 5;


int getRandomNumber() {
// takes the current time as a seed value using the srand function
  srand(time(0));
  // using the modulus operator we get a number between 0 - 99 and adding +1 to make it 1-100
 return rand() % 100 + 1;
}


int getNumberGuessed() {
// declare variable
int numberGuessed;
// print masage to the user to prompt a guess entry
  printf("Guess a number between 1 and 100: ");
// read the user's input and store it in the numberGuessed variable.
    scanf("%d", &numberGuessed);
// returns the value of the numberGuessed variable to the calling function.
    return numberGuessed;

}


void checkNumberGuessed(int numberGuessed, int number, int guessCount) {

// The program should only except guessed numbers in the range of 1 ...100.
 if (numberGuessed < 1 || numberGuessed > 100) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");

     // if the number guessed is below the generated number
    } else if (numberGuessed < number) {  
        printf("Your guess is too low. \n");
          guessCount++; //increment the guessCount
    
    // if the number guessed is above the generated number
    } else if (numberGuessed > number) {  
        printf("Your guess is too high. \n");
        guessCount++; //increment the guessCount
    
    // If the guess is currect then print this
    } else {
        printf("You have guessed %d times and your guess is correct!", guessCount + 1);
    }
}


int main() {

 // Initialize the number of guesses.
int number, numberGuessed, guessCount = 0;
char playAgain; // store user choice

 do {
        number = getRandomNumber();   // call to generate a new random number every new game
        guessCount = 0;    // reset guessCount to 0 in every new game

    do {
        //calls the getNumberGuessed function to get the user to enter a guess.
        numberGuessed = getNumberGuessed();
        // calls the checkNumberGuessed function to check if the user's guess is too low, too high, or correct.
        checkNumberGuessed(numberGuessed, number, guessCount); 
        //  increments the guessCount variable by 1 to keep track of the number of guesses.
             guessCount += 1;
    } 
    // continue to run as long as the user's guess is not correct and the number of guesses is less than maxNumber.
      while (guessCount < maxNumber && numberGuessed != number);

// check if the user has reached the maximum number of guesses 
// and if the user has reached the maximum number of guesses, the program prints the message
         if (guessCount >= maxNumber) {
            printf("You reached the maximum number of guesses.\n");
        }

    // The program then asks the user if they want to play again and user respons accordingly
       do {
     printf("Do you want to play again? (press y if yes, n if no.) \n ");
    scanf(" %c", &playAgain);
    
// the program doesnt allow the user to enter an invalid answer othan than y or n
    if(playAgain != 'y' && playAgain != 'Y'  && playAgain != 'N'  && playAgain != 'n') {
      printf("Please enter a valid input (y or n).\n");
    }

} while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');
}
      while (playAgain == 'y' || playAgain == 'Y');
       return 0;

}
