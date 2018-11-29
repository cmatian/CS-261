//
//  main.c
//  _Worksheet18
//
//  Created by Chris Matian on 4/19/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//


#define TYPE int
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "linkedListQueue.h"

int main(int argc, const char * argv[]) {
    
    struct listQueue queue;
    
    listQueueInit(&queue);
    
    listQueueAddBack(&queue, 1); // Front
    listQueueAddBack(&queue, 2);
    listQueueAddBack(&queue, 3);
    listQueueAddBack(&queue, 4);
    listQueueAddBack(&queue, 5);
    
    printf("%d\n", listQueueFront(&queue)); // Print 1
    
    listQueueRemoveFront(&queue); // Remove 1
    listQueueRemoveFront(&queue); // Remove 2
    listQueueRemoveFront(&queue); // Remove 3
    listQueueRemoveFront(&queue); // Remove 4
    
    printf("%d\n", listQueueFront(&queue)); // Print 5
    
    return 0;
}
