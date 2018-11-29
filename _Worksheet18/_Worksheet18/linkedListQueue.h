//
//  linkedListQueue.h
//  _Worksheet18
//
//  Created by Chris Matian on 4/19/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#ifndef linkedListQueue_h
#define linkedListQueue_h
#define TYPE int
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct link {
    TYPE value;
    struct link * next;
};

struct listQueue {
    struct link *firstLink;
    struct link *lastLink;
};

void listQueueInit (struct listQueue *);
void listQueueAddBack (struct listQueue *, TYPE);
TYPE listQueueFront (struct listQueue *);
void listQueueRemoveFront (struct listQueue *);
int listQueueIsEmpty (struct listQueue *);

#endif /* linkedListQueue_h */
