/* 
Author: Christopher Matian
Date: 2/04/2018
Class: CS 261
*/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
    
    struct Link *front = (struct Link *)malloc(sizeof(struct Link));
    assert(front);
    
    struct Link *back = (struct Link *)malloc(sizeof(struct Link));
    assert(back);
    
    front->prev = back;
    front->next = NULL;
    
    back->prev = NULL;
    back->next = front;
    
    list->frontSentinel = front;
    list->backSentinel = back;
    list->size = 0;
	
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	
    struct Link * newLink = (struct Link *)malloc(sizeof(struct Link));
    
    struct Link * lastLink = link->prev;
    
    link->prev = newLink;
    lastLink->next = newLink;
    
    newLink->prev = lastLink;
    newLink->next = link;
    
    newLink->value = value;
    
    list->size++;
    
    
    
}

/*
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	
    assert(list->size > 0);
    
    struct Link *garbage = link;
    struct Link *before = link->prev;
    struct Link *after = link->next;
    
    before->next = after;
    after->prev = before;
    
    garbage->next = NULL;
    garbage->prev = NULL;
    free(garbage);
    
    list->size--;
    
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	
    struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
    struct Link *lastFront;
    
    lastFront = list->frontSentinel->prev;
    
    lastFront->next = newLink;
    list->frontSentinel->prev = newLink;
    
    newLink->next = list->frontSentinel;
    newLink->prev = lastFront;
    
    newLink->value = value;
    
    list->size++;
    
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	
    struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
    struct Link *lastBack;
    
    lastBack = list->backSentinel->next;
    
    lastBack->prev = newLink;
    list->backSentinel->next = newLink;
    
    newLink->prev = list->backSentinel;
    newLink->next = lastBack;
    
    newLink->value = value;
    
    list->size++;
    
    
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	
    assert(list->size > 0);
    return list->frontSentinel->prev->value;
    
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	
    assert(list->size > 0);
    return list->backSentinel->next->value;
    
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
    assert(list->size > 0);
    
    struct Link * target = list->frontSentinel->prev;
    
    struct Link * newFront = list->frontSentinel->prev->prev;
    
    newFront->next = list->frontSentinel;
    list->frontSentinel->prev = newFront;
    
    target->prev = NULL;
    target->next = NULL;
    free(target);
    target = NULL;
    
    list->size--;
    
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	
    assert(list->size > 0);
    
    struct Link * target = list->backSentinel->next;
    
    struct Link * newBack = list->backSentinel->next->next;
    
    newBack->prev = list->backSentinel;
    list->backSentinel->next = newBack;
    
    target->prev = NULL;
    target->next = NULL;
    free(target);
    target = NULL;
    
    list->size--;
    
    
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	
    if ( list->size == 0 ) {
        
        return 1;
        
    }
    
    return 0;
    
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// Is there something in the list?
    assert(list->size > 0);
    
    // Create a tracker node/link that is set to the previous pointer of the frontSentinel
    struct Link * tracker = list->frontSentinel->prev;
    
    // While the tracker is not 0, it will print the values in the list
    while(tracker->prev != 0) {
        
        printf("%d ", tracker->value);
        tracker = tracker->prev;
        
    }
    
    printf("\n");
    
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
    // Calls addBack function passes in the list and value arguments
    linkedListAddBack(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	
    // Check that there is something in the list - otherwise it will exit with an error
    assert(list->size > 0);
    struct Link * target = list->frontSentinel->prev;
    
    // Loop through list and check to see if the value matches the passed in value. Return 1 if it exists, otherwise return 0
    while (target->prev > 0) {
        
        if (target->value == value) {
            
            return 1;
            
        }
        target = target->prev;
        
    }
    
    return 0;
    
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	
    // Check that the list holds values and that the value we're trying to remove exists in the first place
    // Split into two assertions so it's easier to read
    assert(list->size > 0);
    assert(linkedListContains(list, value));
    
    // Create a target node
    struct Link * target = list->frontSentinel->prev;
    
    // Loop through the target list until it finds the value we're trying to remove
    while(target > 0) {
        
        // If the value is found
        if (target->value == value) {
            
            // Reassign the target next/prev pointers
            target->next->prev = target->prev;
            target->prev->next = target->next;
            
            // Set them to null
            target->next = NULL;
            target->prev = NULL;
            
            // Free the memory
            free(target);
            
            // Reduce the list size
            list->size--;
            
            // Break out of the function
            return;
            
        }
        // target is assigned to the target prev pointer
        target = target->prev;
    }
}
