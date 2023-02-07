// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 2023
// Work package 2
// Exercise 3
// Submission code:RG0456-v

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON;

//read a person's name
PERSON input_record(void);
// create a file and add a dummy data to it that we defined below
 void write_new_file(PERSON *inrecord) {
 FILE *fileptr;
    fileptr=fopen("exercise.bin", "wb");// opens the file and create one if it doesn't exist
    fwrite(inrecord, sizeof(PERSON),1,fileptr); // writting the input //for checking the empty file I comment this out
    fclose(fileptr);
}
 // append a person to the file 
 void append_file(PERSON *inrecord){
 FILE *fileptr;
 PERSON person;
 if ((fileptr=fopen("exercise.bin", "rb")) == NULL){  //check if the file exist
    printf("The file doesn't exist!");
 }
 else {
    fileptr=fopen("exercise.bin", "ab");
    fwrite(inrecord, sizeof(PERSON), 1, fileptr); // writting the input
    fclose(fileptr);
 }
 }
 void search_by_firstname(char *name){ //declare a char name(input) and compare to the name in the data
    FILE *file;
    PERSON person;
    if((file=fopen("exercise.bin", "rb")) == NULL){ // checks if the file exists
        printf("The file doesn't exist!"); //error message if the file doesn't exist
    }
    else{
        file = fopen("exercise.bin","rb"); // open the file

        while(fread(&person, sizeof(PERSON), 1, file) == 1 ) { // reading 1 person from the file handler(reading maximum one element)
            if (strcasecmp(name, person.firstname) == 0 || strcasecmp(name, person.famname) == 0) { // compare the input with the data in the file
                printf("%s %s %s \n", person.firstname, person.famname, person.pers_number); // print all the information of the user 
            }
        }

    }
 
fclose(file);

 };
 void printfile(void){
     FILE *file;
    PERSON person;
    file  = fopen("exercise.bin", "rb"); // open the file 
    if (file != NULL) { // if the file is not null
        
        fseek(file, 0, SEEK_END); // search in the end of the file
                
        if (ftell(file) == 0) // if the file contains 0 elements
        {
            
            printf("The file you are searching in is empty.\n");
        }
    }
        fseek(file, 0, SEEK_SET); // searching and moving the file to the beginning of the file 
        file = fopen("exercise.bin", "rb"); // open the file 

 while(fread(&person, sizeof(PERSON), 1, file) == 1 ) { // reading 1 person from the file handler(reading maximum one element)
                printf("%s %s %s \n", person.firstname, person.famname, person.pers_number); // print all the information of the user 
            }
        }

// displying the menu
 void display_menu() {
        printf("1. Create a new and delete the old file.\n");
        printf("2. Add a new person to the file.\n");
        printf("3. Search for a person in the file.\n");
        printf("4. Print out all in the file.\n");
        printf("5. Exit the program.\n");
        printf("Enter your choice:");
 } 
 

int main(void) {
    char choice[1];
    PERSON ppost; //for creating the first data input
    PERSON person;
    // input dummy data // for checking the fail-safe I comment out the dummy data
    strcpy(ppost.firstname, "name");
    strcpy(ppost.famname, "lastname");
    strcpy(ppost.pers_number, "0923875236");
    
    display_menu();
    scanf("%c",&choice[0]); //check for the user input 


        switch (choice[0]) // use switch to check for the input the user enters 
        {
            case '1': 
           write_new_file(&ppost); //create a new file and add the first dummy person
            break;

            case '2':
            printf("Enter your first name. \n"); 
            scanf(" %20s", person.firstname);
            printf("Enter your last name. \n");
            scanf(" %20s", person.famname);
            printf("Enter your personal number. \n");
            scanf(" %13s", person.pers_number);
            append_file(&person);
            break;

            case '3':
            printf("Enter the first name to search for. \n");
            scanf("%s", person.firstname);
            search_by_firstname(person.firstname); // search by the first name 
            break;

            case '4':
            printfile(); // print all the elements in the file
            break;

            case '5':
            return 0; //exit the program
            break;

    }
}