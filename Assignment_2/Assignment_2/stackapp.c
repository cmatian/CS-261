/*******************************************************************************************
 **
 ** Christopher Matian
 ** 4/23/2018
 ** Assignment 2 - stackapp.c
 **
 *******************************************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    // Create a Stack to hold the characters we pump into it
    DynArr *stack = newDynArr(1);
    
    char ch;
    
    do {

        ch = nextChar(s);

        if (ch == '(' || ch == '[' || ch == '{') {

            pushDynArr(stack, ch);

        } else if ( ch == ')' || ch == ']' || ch == '}' ) {

            // Compare char ')'
            if ( ch == ')' ) {

                if( isEmptyDynArr(stack) == 1 || topDynArr(stack) != '(' ) {

                    deleteDynArr(stack);
                    return 0;

                } else {

                    popDynArr(stack);

                }

            // Compare char ']'
            } else if ( ch == ']' ) {

                if( isEmptyDynArr(stack) == 1 || topDynArr(stack) != '[' ) {

                    deleteDynArr(stack);
                    return 0;

                } else {

                    popDynArr(stack);

                }

            // Compare char '}'
            } else if ( ch == '}' ) {

                if( isEmptyDynArr(stack) == 1 || topDynArr(stack) != '{' ) {

                    deleteDynArr(stack);
                    return 0;

                } else {

                    popDynArr(stack);

                }
                
            }
            
        }
        
    } while(ch != '\0');
    
    if (sizeDynArr(stack) == 0) {
        
        deleteDynArr(stack);
        return 1;
        
    } else {
        
        deleteDynArr(stack);
        return 0;
        
    }
}

int main(int argc, char* argv[]){
    
	char* s = argv[1];
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else 
		printf("The string %s is not balanced\n", s);
	
	return 0;	
}

