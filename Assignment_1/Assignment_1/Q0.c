/* CS261- Assignment 1 - Q.0*/
/* Name: Christopher Matian
 * Date: 04/04/2018
 * Solution description:
 Simple solution that generates a random number for x. I then pass the variable by reference to the fooA function.
 The fooA function takes the variables and prints out various details - the value that the reference is pointing to, the
 address that is pointed to by the iptr, and the address of the iptr itself. Then the function manipulates the original value that was
 passed in and we use printf outside of the function to determine whether the change registered. 
 */
 

#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

void fooA(int *iptr){
     /*Print the value of iptr*/
    printf("The value of iptr* is: %d\n", *iptr);
    
     /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr is: %p\n", iptr);

     /*Print the address of iptr itself*/
    printf("The address of the iptr itself is: %p\n", &iptr);
    
     /*Change the value of iptr itself*/
    *iptr = 100;
         
}

int main(){
    //srand((unsigned int)time(NULL));
    
    /*declare an integer x and initialize it randomly to a value in [0,10] */
    int x = rand() % 11; // Provides a range of 0 - 10
    
    /*Print the address of x*/
    printf("The address of int x: %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("The value of x is: %d\n", x);

    /*Answer the question */
    /*
     Yes, it's different. The reason is that we used a pointer to access the original integer and change the value that it was pointing to directly. If we had passed in the argument integer as just an int (x) and not as a reference (&x), we would have been unable to manipulate the data
     because the function produces a copy and manipulates that copy only. The value would have retained it's original value. 
     */
    
    return 0;
   
    
}


