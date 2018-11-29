/* CS261- Assignment 1 - Q.3*/
/* Name: Christopher Matian
 * Date: 04/05/2018
 * Solution description:
 My solution consists of creating a function which produces a bunch of random, unique IDs and then storing them into an idArray.
 After, I allocate memory for however many students I want, and set the ID (using the idArray) and random score for each student.
 Finally I sort the score using a simple sort - it basically looks at each index and determines if it's bigger.
 If it's bigger it swaps positions. Otherwise it skips over and looks at the next index.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <time.h>

struct student{
	int id;
	int score;
};

// Sorting based on lowest to highest
void sort(struct student* students, int n) {
    
    struct student temp;
    
     /*Sort the n students based on their score*/
    for (int i = 0; i < n; i++) {
        
        for (int j = i + 1; j < n; j++ ) {
            
            if ( students[i].score > students[j].score ) {
                
                temp = students[i];
                
                students[i] = students[j];
                
                students[j] = temp;
                
            }
        }
    }
}

// Random ID generation.
void generateRandomID(int idArray[], int size) {
    
    for(int i = 0; i < size; i++) {
        
        idArray[i] = 1 + rand() % size; // Range of 1 to whatever size is
        
        for (int j = 0; j <= (i - 1); j++) {
            
            if(idArray[i] == idArray[j]) {
                i--;
            }
        }
    }
}

int main(){
    
    //srand((unsigned int)time(NULL));
    
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    
    // Array container for random ID's
    int idArray[n];
    
    // Generate random ID's
    generateRandomID(idArray, n);
    
    /*Allocate memory for n students using malloc.*/
    struct student* s = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(int i = 0; i < n; i++) {
    
        // Set ID to the unique ID we generated above
        s[i].id = idArray[i];
    
        // Generate a random score
        s[i].score = rand() % 101;
        
    }
    
    /*Print the contents of the array of n students.*/
    printf("===== Before Sorting ======\n");
    printf("IDs\t\tScores\n"); // Header
    printf("===\t\t======\n"); // Styling
    for(int i = 0; i < n; i++) {
        printf("ID: %d\tScore: %d\n", s[i].id, s[i].score); // Student ID/Score
    }
    printf("\n"); // Styling

    /*Pass this array along with n to the sort() function*/
    sort(s, n);
    
    
    /*Print the contents of the array of n students.*/
    printf("===== After Sorting ======\n");
    printf("IDs\t\tScores\n"); // Header
    printf("===\t\t======\n"); // Styling
    for(int i = 0; i < n; i++) {
        printf("ID: %d\tScore: %d\n", s[i].id, s[i].score); // Student ID/Score
    }
    
    return 0;
}
