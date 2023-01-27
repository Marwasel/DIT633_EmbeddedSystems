// (C) Nazli moghaddam , Marwa Selwaye, Jonna johansson , group: 16 __ (2023) 
// Work package 1
// Exercise 3
// Submission code: 123569KL 



#include<stdio.h>    
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
//save the binary number as long
long binaryval=atoi(argv[1]), hexadecimalval = 0, i = 1, remainder;

int success=0;
if(binaryval== '\0'){//used to check if the user puts a numeric value 
success=1;
}
if(strcmp(argv[1],"-h")==0){//used to check for -h
    printf("information\n");
    success=1;
}
if(success==0){

     while (binaryval != 0){
    //obtain the remainder of the input number 
      remainder = binaryval % 10;
      //Multiply the number with variable i 
      hexadecimalval = hexadecimalval + remainder * i;
      //Multiply the variable i by 2 
      i = i * 2;
      //override the binaryval with the quotient 
      binaryval = binaryval / 10;
      //until binaryval becomes 0
   }
   // print binary number as hexadecimal number 
   printf("Equivalent hexadecimal value: 0%lX\n", hexadecimalval);
}
   if(success==0){
    return 0;
   }else{
    printf("The value you entered is not valid!\n");
    return 2;
   }
}
// refrence to this piece of code : https://www.sanfoundry.com/c-program-convert-binary-hex/