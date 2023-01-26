#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max_8bit_number  255  // Maximum decimal number that has 8 digits 
#define Max_integer  2147483647 // Maximum integer value that can be hold by the C compiler 
#define Short_binary  8 // When the value of decimal number that has been entered by the user is less than 8 digits, binary number of 8 bits will show
#define long_binary  16 // Display of 16 bits if the digits of decimal number is more than 8 and less than 16 

// method that converts the decimal number to binary number by getting the input and checking the length of the array
void decimalToBinary(long input, int length);

int main(int argc, char *argv[])
{
    unsigned long long longChecker;
    const char *numberError2 = "Please enter a number! you entered non-numeric value!";
    const char *numberError1 = "Number you entered is so large!";
    const char *helpMessage = "Enter the proper value as a decimal number and receive the binary veersion of the number";
    long int input;
    int integerChecker;

    input = atoi(argv[1]); // save the char value into long integer
// if the value that has been entered is larger than the max value that the compiler can handle, we can save it as long long to handle the errors in the way
    longChecker = atoi(argv[1]);
    // checking if the value in number 
    integerChecker = *argv[1];

    if(strcmp(argv[1], "-h") == 0) // if the user puts -h, they can get help about how to use the program
    {
        // printing the help message
        printf("%s", helpMessage);
        // exit with program with the code 2
        return 2;
    }
    else if(longChecker > Max_integer) {
        // if the decimal number that has been entered is larger than the maximum long that can be compiled by C
        printf("%s", numberError1);
        // exit the program with code 2 
        return 2;
    }
    else if(isdigit(integerChecker) == 0) // if the argument has values that are not numbers
    {
        printf("%s", numberError2);
        // exit the program with number 2
        return 2;
    }
    else {

    if (input <= Max_integer){ // if the number entered is decimal
    
        // convert number using 8 digits binary
        decimalToBinary(input, Short_binary);
    }
    else if (input > Max_8bit_number) // if the number is more than 8 digits
    {
        decimalToBinary(input, long_binary);
    }
    //exit code with 0
    return 0;
    }
}
// implementation of conversion from decimal to binary
 void decimalToBinary(long input, int length)
 {
    int i; // use a variable i for the loop
    int output[length]; // use an array to save binary values 

    // iterating over the loop 
    for(i = 0; i< length; i++)
    {
    //place 0 instead of possible existing values
    output[i] = 0;
    }
    // calculate the binary value by iterating over the input 
    for (i =0; input > 0; i++) {
        // get the remainder of the value divided by two and store it in the array

        output[i] = input % 2;
        
        // get the quotient for the next loop 
        input =  input / 2;
    }
    // print the binary number starting by the last element 
    for(i = (length - 1); i >= 0; i--)
    {
        printf("%d", output[i]);
    }
 }
