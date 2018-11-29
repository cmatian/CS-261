//
//  linkedList.c
//  Worksheet Testing Ground
//
//  Created by Chris Matian on 4/19/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include "linkedList.h"

void linkedListStackInit (struct linkedListStack *s) {
    
    s->firstLink = 0;
    
}

void linkedListStackFree (struct linkedListStack *s) {
    
    while (!linkedListStackIsEmpty(s)) {
        linkedListStackPop(s);
    }
    
}

void linkedListStackPush (struct linkedListStack *s, TYPE d) {
    
    struct link *newLink = malloc(sizeof(struct link));
    assert(newLink != NULL);
    
    newLink->value = d;
    newLink->next = s->firstLink;
    s->firstLink = newLink;
    
}

TYPE linkedListStackTop (struct linkedListStack *s) {
    assert(!linkedListStackIsEmpty(s));
    return s->firstLink->value;
}

void linkedListStackPop (struct linkedListStack *s) {
    assert(!linkedListStackIsEmpty(s));
    
    struct link *garbage = s->firstLink;
    
    s->firstLink = s->firstLink->next;
    
    garbage->next = NULL;
    
    free(garbage);
    
}

int linkedListStackIsEmpty (struct linkedListStack *s) {
    
    if (s->firstLink == NULL) {
        
        return 1;
        
    }
    
    return 0;
}
