/* CS261- Assignment 1 - Q.1*/
/* Name: Christopher Matian
 * Date: 04/04/2018
 * Solution description:
 This solution first starts off by generating 10 random ID's and storing them into the idArray. Afterwards, it will take
 the student structure and generate an array of 10 students. The students are assigned their own unique ID (using the idArray), and a
 random score is generated for them. The scores are then summed up and divided by 10 to determine the average. Another for-loop runs
 which determines what the min and max values are starting with the first indexed student score. It cycles through each index and compares them,
 Finally, the student array that was allocated is deallocated using a call to the deallocate() function which passes in the student array of structures.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* s = malloc(10 * sizeof(struct student));
     /*return the pointer*/
    return s;
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


void generate(struct student* students){
     /*Generate random and unique ID and random scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int idArray[10];
    
    generateRandomID(idArray, 10);
    
    
    for (int i = 0; i < 10; i++) {
        students[i].id = idArray[i];
        students[i].score = rand() % 101;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for(int i = 0; i < 10; i++) {
        printf("ID: %d\tScore: %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min, max;
    
    double sum, avg;
    
    // Initialize variables
    avg = 0.0;
    sum = 0.0;
    min = students[0].score;
    max = students[0].score;
    
    for(int i = 0; i < 10; i++) {
        
        // Compute min and max
        if(students[i].score > max) {
            
            max = students[i].score;
            
        } else if (students[i].score < min) {
            
            min = students[i].score;
            
        }
        
        // Add the values to sum
        sum += students[i].score;
    }
    
    // Compute the average
    avg = sum / 10;
    
    // Print the min, max, and avg scores
    printf("The minimum score is: %d\n", min);
    printf("The maximum score is: %d\n", max);
    printf("The average score is: %f\n", avg);
    
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    
    // Seed time for random values
    //srand((unsigned int)time(NULL));
    
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
