//
//  linkedListQueue.c
//  _Worksheet18
//
//  Created by Chris Matian on 4/19/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include "linkedListQueue.h"

void listQueueInit (struct listQueue *q) {
    struct link *node = (struct link *) malloc(sizeof(struct link));
    assert(node != 0); /* node is the sentinel */
    node->next = 0;
    q->firstLink = q->lastLink = node;
}


void listQueueAddBack (struct listQueue *q, TYPE e) {
    // Create the link node
    struct link *newLink = (struct link*)malloc(sizeof(struct link));
    assert(newLink != NULL);
    
    newLink->value = e;
    newLink->next = q->lastLink->next;
    q->lastLink->next = newLink;
    q->lastLink = newLink;
    
}


TYPE listQueueFront (struct listQueue *q) {
    
    assert(!listQueueIsEmpty(q));
    
    return q->firstLink->next->value;
}


void listQueueRemoveFront (struct listQueue *q) {
    
    assert(!listQueueIsEmpty(q));
    
    struct link *garbage = q->firstLink->next;
    
    q->firstLink->next = q->firstLink->next->next;
    
    free(garbage);
    
}


int listQueueIsEmpty (struct listQueue *q) {
    
    if(q->firstLink == q->lastLink) {
        
        return 1;
        
    }
    
    return 0;
    
}
