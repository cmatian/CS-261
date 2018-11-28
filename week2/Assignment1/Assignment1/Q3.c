/* CS261- Assignment 1 - Q.3*/
/* Name: Christopher Matian
 * Date: 1/19/2018
 * Solution description: Creates an array of integers and sorts them using the sort function
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    
    int i,
        j,
        temp;
    
    for ( i = 0; i < n; i++) {
        
        j = 0;
        
        while( j < n ) {
            
            if( number[i] < number[j] ) {
                
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
                
            }
            j++;
        }
        
    }

    
}

int main(){
    // Seeding random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *numArr = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    
    for ( int i = 0; i < n; i++ ) {
        numArr[i] = ((rand() % 100) + 1);
    }
    
    /*Print the contents of the array.*/
    printf("Unsorted Numbers\n");
    for ( int i = 0; i < n; i++ ) {
        
        printf("%d ", numArr[i]);
        
    }
    

    /*Pass this array along with n to the sort() function of part a.*/
    sort( numArr, n );
    
    /*Print the contents of the array.*/
    printf("\n\nSorted Numbers\n");
    for ( int i = 0; i < n; i++ ) {
        
        printf("%d ", numArr[i]);
        
    }
    
    
    return 0;
}
