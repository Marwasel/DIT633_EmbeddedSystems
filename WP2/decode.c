// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 2023
// Work package 2
// Exercise 4
// Submission code:RG0456-v

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {


unsigned char input = (unsigned char)strtol(argv[1], NULL, 16); //convert the character string to a long integer value

// Unpack byte into original values
// extract the leftmost bit in a binary representation of a number and store it in engine_on
// the extracted bit is shifted right by 7 bits using the right shift operator (>>)
unsigned char engine_on = (input & (1 << 7)) >> 7;

// extract the values of bits 5 to 7(represents 3 bits) of the input variable and store in gear_pos
// >> 4 at the end then shifts the result of the AND operation to the right 4 times,
unsigned char gear_pos = (input & (7 << 4)) >> 4;

// extract the values of bits 3 to 4 of the input variable and store in key_pos
// >> 2 at the end then shifts the result of the AND operation to the right 2 times
 unsigned char key_pos = (input & (3 << 2)) >> 2;

// extract the value of bit 2 of the input variable and store it in brake1
// >> 1 at the end then shifts the result of the AND operation to the right 1 time
unsigned char brake1 = (input & (1 << 1)) >> 1;

// extract the least significant bit of the input variable and store it in brake2
unsigned char brake2 = input & 1;

// if the user inputs too few or too many arguments 
  if (argc > 2 || argc < 2) {
    printf("Invalid number of arguments\n"); // get an error message
    return -1;
  }
  char one = argv[1][0]; // set a char variable to the first character 
  char two = argv[1][1]; // set a char ariable to the second character

// check if the format of hexadecimal entered is valid
if(!(((one <=  'F' && one >= 'A') && (two <= 'F' && two >= 'A')) ||((one <= '9' && one >= '0') && (two <= '9' && two >= '0')))) {
    printf("Not valid hexadecimal value!");
    return 0;
}else {
  
  printf("Name Value\n-\n");
  printf("engine_on %d\n", engine_on);
  printf("gear_pos %d\n", gear_pos);
  printf("key_pos %d\n", key_pos);
  printf("brake1 %d\n", brake1);
  printf("brake2 %d\n", brake2);
  return 0;
}
}
