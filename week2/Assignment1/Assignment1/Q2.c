/* CS261- Assignment 1 - Q.2*/
/* Name: Christopher Matian
 * Date: 1/19/2018
 * Solution description: Highlights mutability of variable definitions using pointers.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    
    /*Set b to half its original value*/
    *b /= 2;
    
    /*Assign a+b to c*/
    
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5,
        y = 6,
        z = 7;
    
    /*Print the values of x, y and z*/
    printf("First Print of Integers.\n");
    printf("The value of int X is: %d\n", x);
    printf("The value of int Y is: %d\n", y);
    printf("The value of int Z is: %d\n\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int result = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("The return value of result is: %d\n\n", result);
    
    /*Print the values of x, y and z again*/
    printf("Second Print of Integers.\n");
    printf("The value of int X is: %d\n", x);
    printf("The value of int Y is: %d\n", y);
    printf("The value of int Z is: %d\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
    
    /*
     Yes, the value is manipulated and returned within the function, but the original int declaration is unchanged because
     it was not passed in by its address variable, and the function was not pointing to it as it was for the other two ints.
     */
    
    return 0;
}
    
    
