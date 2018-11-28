/* CS261- Assignment 1 - Q.1*/
/* 
 * Name: Christopher Matian
 * Date: 1/19/2018
 * Solution description: Allocates memory for 10 students and assigns unique ID numbers and random scores for each student
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *students = malloc(10 * sizeof(struct student));
    
     /*return the pointer*/
    return students;
    
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    
    for ( int i = 0; i < 10; i++ ) {
        // Unique ID
        students[i].id = i + 1;
        // Random Score
        students[i].score = ((rand() % 100) + 1);
    }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for ( int i = 0; i < 10; i++ ) {
        printf("ID: %d Score: %d\n", students[i].id, students[i].score);
    }
    
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int sum = 0,
        average,
        min,
        max;
    
    // Find Average Score
    for ( int i = 0; i < 10; i++ ) {
        
        //Add Scores together
        sum += students[i].score;
    }
    // Determine the sum
    average = sum / 10;
    
    // Find Minimum Score
    min = students[0].score;
    
    for ( int i = 0; i < 10; i++) {
        
        if ( students[i].score < min ) {
            min = students[i].score;
        }
    }
    
    // Find Maximum Score
    max = students[0].score;
    
    for ( int i = 0; i < 10; i++ ) {
        
        if ( students[i].score > max ) {
            max = students[i].score;
        }
        
    }
    
    printf("The minimum score is: %d\n", min);
    printf("The maximum score is: %d\n", max);
    printf("The average score is: %d\n", average);
    
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
    
}

int main(){
    // Seeding random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
