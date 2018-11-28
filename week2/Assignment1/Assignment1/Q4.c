/* CS261- Assignment 1 - Q.4*/
/* Name: Christopher Matian
 * Date: 1/19/2018
 * Solution description: Creates an array of 10 students, gives them a unique ID and random score, and sorts them by score.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i, j;
    struct student temp;
    
    for ( i = 0; i < n; i++) {
        
        j = 0;
        
        while( j < n ) {
            
            if( students[i].score < students[j].score ) {
                
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
                
            }
            j++;
        }
        
    }
    
}

int main(){
    // Seeding random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    /*Declare an integer n and assign it a value.*/
    
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    
    struct student *students = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        students[i].score = ((rand() % 100) + 1);
    }
    
    /*Print the contents of the array of n students.*/
    printf("Unsorted Students by Score\n");
    for ( int i = 0; i < n; i++ ) {
        
        printf("Student ID: %d\tScore: %d\n", students[i].id, students[i].score);
        
    }

    /*Pass this array along with n to the sort() function*/
    
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("\nSorted Students by Score\n");
    for ( int i = 0; i < n; i++ ) {
        
        printf("Student ID: %d\tScore: %d\n", students[i].id, students[i].score);
        
    }
    
    return 0;
}
