/* CS261- Assignment 1 - Q.2*/
/* Name: Christopher Matian
 * Date: 04/04/2018
 * Solution description:
 Rather simple solution which generates a random number and passes them into the foo function.
 The function uses pointers for the first two arguments, and the third argument is a non-pointer.
 The result is that a and b will mutate whereas c will not mutate (outside of the function). 
 */
#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    *a += 1;
    
    /* Decrement  b */
    *b -= 1;
    
    /* Assign a+b to c */
    c = (*a + *b);
    
    /* Return c */
    return c;
}

int main(){
    //srand((unsigned int)time(NULL));
    
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z;
    
    x = rand() % 11;
    y = rand() % 11;
    z = rand() % 11;
    
    /* Print the values of x, y and z */
    printf("X: %d\nY: %d\nZ: %d\n", x, y, z);
    
    /* Call foo() appropriately, passing x,y,z as parameters */
    int result = foo(&x, &y, z);
    
    /* Print the values of x, y and z */
    printf("X: %d\nY: %d\nZ: %d\n", x, y, z);
    
    /* Print the value returned by foo */
    printf("Value returned by the function: %d\n", result);
    
    return 0;
}
    
    

