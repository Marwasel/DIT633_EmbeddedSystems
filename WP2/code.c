// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 2023
// Work package 2
// Exercise 4
// Submission code:RG0456-v

#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte;  
// functions declarations
int pack_bits(char *, int);
// Main funcion and error handling 
int main(int argc, char const *argv[]){
    if(argc > 6 && argc <0){ // if there are not enough or adequet amount of argument

    printf("The arguments that have been passed are not enough!");
    return 1;
    }
byte value = 0;
value += atoi(argv[1]) << 7; // leftshifting the first argument 7 times. bit no 7
value += atoi(argv[2]) << 4; // leftshifing the second argument 4 times
value += atoi(argv[3]) << 2; // leftshifting the third argument 2 times
value += atoi(argv[4]) << 1; // leftshifting the fourth argument 1 time. bit no 0
value += atoi(argv[5]);
printf("Hex: %x\n", value);
return 0;
}
// pack bits into bytes function by entering an input 
int pack_bits(char *input, int currentArgument) {
     int value = atoi(input); // get the int value of the input

     if(currentArgument == 1 || currentArgument == 4 || currentArgument == 5){ // if there are first, 4th and 5th arguments
     if (value == 1 || value == 0) { // the values should be either 0 or 1 
        return 1;
     }

     }
     else if(currentArgument == 2) { // if it is the second argument
        if(value >= 0 && value <= 4){ //the value should be between 0 and 4
            return 1;
        }
     }
     else if(currentArgument == 3) { //if it is the third argument
        if(value >= 0 && value <= 2){ // the value should be between 0 and 2
            return 1;
        }
     }
return 0;

}
