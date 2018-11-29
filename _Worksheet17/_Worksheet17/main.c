//
//  main.c
//  Worksheet Testing Ground
//
//  Created by Chris Matian on 4/19/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define TYPE int

// Functions


// Main for testing
int main(int argc, const char * argv[]) {
    
    struct linkedListStack stack;
    
    linkedListStackInit(&stack);
    
    linkedListStackPush(&stack, 1);
    linkedListStackPush(&stack, 2);
    linkedListStackPush(&stack, 3);
    linkedListStackPush(&stack, 4);
    linkedListStackPush(&stack, 5);
    
    printf("%d\n", linkedListStackTop(&stack)); // 5
    
    linkedListStackPop(&stack);
    linkedListStackPop(&stack);
    linkedListStackPop(&stack);
    linkedListStackPop(&stack);
    
    printf("%d\n", linkedListStackTop(&stack)); // 1
    
    linkedListStackPop(&stack);
    
//    printf("%d\n", linkedListStackTop(&stack)); // Assertion fails because the stack is empty
    
    
    
    
    
    
    
    return 0;
}
