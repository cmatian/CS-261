//
//  linkedList.h
//  Worksheet Testing Ground
//
//  Created by Chris Matian on 4/19/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define TYPE int
#ifndef linkedList_h
#define linkedList_h

// Structures
struct link {
    TYPE value;
    struct link *next;
};

struct linkedListStack {
    struct link *firstLink;
};

// Prototypes
void linkedListStackInit (struct linkedListStack *);
void linkedListStackFree (struct linkedListStack *);
void linkedListStackPush (struct linkedListStack *, TYPE);
TYPE linkedListStackTop (struct linkedListStack *);
void linkedListStackPop (struct linkedListStack *);
int linkedListStackIsEmpty (struct linkedListStack *);


#endif /* linkedList_h */


