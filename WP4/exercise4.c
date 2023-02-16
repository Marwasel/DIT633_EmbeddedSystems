// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 4
// Exercise 4
// Submission code: 5384557753 

#include <stdio.h>
   

    int search_number(int number, int tab[], int size){ // function for searching for the index of the number in the array tab
        for(int j= 0; j<size; j++) { // looping through the indexes of the array 
            if(tab[j] == number) {// if the number with the index j in the array equals to the number we identified in the main function
                printf("position of %d in the array is %d", number, j);
                return j; // return the number of the index 
            }

        }
        return -1; // else return -1
    }
// resources : https://www.geeksforgeeks.org/bubble-sort/
void swap(int* xp, int* yp) //using two pointers xp and yp to integers
{
    int temp = *xp; // assigning the value temp to the first integer
    *xp = *yp; // assigning the first value to the second value
    *yp = temp; // assigning the second value to temp 
}
    void sort ( int number,int tab []) { // using sort function to bubble sort the array
       int i, j;
    for (i = 0; i < number - 1; i++) { // number of elements in the sorted array
        for (j = 0; j < number - i - 1; j++){ //j as a defining position for comparison
            if (tab[j] > tab[j + 1]){ //comparing the current element with the next element
                swap(&tab[j], &tab[j + 1]); // moving the larger value to the right position

            }
        }
    }
    for (i = 0; i < number; i++) // looping through the array 
    printf("%d ", tab[i]);// printing the final array in the console
    }
 
    int main()
{
    int n;
    int test[] = {1,2,34,5,67,3,23,12,13,10 }; // a test array
    int size = sizeof(test) / sizeof(test[0]); // gives the number of elements in the array 
    printf("Enter a number to be searched in the array"); //asking the user to enter the number to be searched in the array 
	scanf("%d", &n); //storing the number entered in variable n 
    search_number(n,test,size);
    printf("\n");
    sort(size,test);
    return 0;
}
//  int main() {
//     int tab[] = {1,2,34,5,67,3,23,12,13,10 };
//     int number = 3;
//     int size = sizeof(tab) / sizeof(tab[0]);
//     int index =  search_number(number, tab, size);
//     if (index == -1) {
//         printf("%d not found in the array\n", number);
//     } else {
//         printf("%d found at index %d in the array\n", number, index);
//     }
//     return 0;
// }



    