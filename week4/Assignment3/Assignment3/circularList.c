/*
 Author: Christopher Matian
 Date: 2/04/2018
 Class: CS 261
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
    
    list->sentinel = (struct Link *)malloc(sizeof(struct Link));
    
    assert(list->sentinel != 0);
    
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    list->sentinel->value = 0;
    
    list->size = 0;
    
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// Create a new link and allocated memory for it
    struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
    
    // Set the next and prev pointers to null
    newLink->next = NULL;
    newLink->prev = NULL;
    
    // Set the value
    newLink->value = value;
    
    // Return the link
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	
    // Create new link using createLink
    struct Link *newLink = createLink(value);
    
    // Set the pointers
    newLink->next = link->next;
    newLink->prev = link;

    newLink->next->prev = newLink;
    newLink->prev->next = newLink;
    
    // Increase the list size
    list->size++;
    
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
    // Reassign pointers after
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    link->next = NULL;
    link->prev = NULL;
    
    // Free the link memory and set it to null
    free(link);
    link = NULL;
    
    // Reduce the list size
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
    // Check that the list is not empty
    assert(!circularListIsEmpty(list));
    
    // While the list is not empty...
    while (!circularListIsEmpty(list)) {
        
        // Garbage collection
        struct Link * temp = list->sentinel->next;
        // Call removeLink and remove the passed in arguments
        removeLink(list, temp);
        
    }

    // Free the memory
    free(list->sentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
    // Call addLinkAfter and pass in the parameters from above
    addLinkAfter(list, list->sentinel, value);
    
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
    // Call addLinkAfter and pass in the parameters from above
    addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
    // Return the value using the sentinel's next pointer and the value it's pointing to
    return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
    
    // Returns the value using sentinel's previous pointer and the value it's pointing to
    return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// Use removeLink and pass in the list, and the link to remove
    removeLink(list, list->sentinel->next);
    
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// Use removeLink and pass in the list, and the link to remove
    removeLink(list, list->sentinel->prev);
    
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	
    if ( list->size == 0 ) {
        
        return 1;
        
    }
    
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
    int size = list->size;
    
    struct Link *tracker = list->sentinel->next;
    
    printf("Deque List Front -> Back\n");
    
    while ( size > 0 ) {
        
        printf("%g ", tracker->value);
        
        tracker = tracker->next;
        size--;
        
    }
    
    printf("\n");
    
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
    
    assert(!circularListIsEmpty(list));
	
    // Create a node to keep track of
    struct Link * tracker = list->sentinel;
    
    // Loop through the list
    for ( int i = 0; i < list->size + 1; i++ ) {
        
        // Create a temp node that points to tracker's next pointer
        struct Link *temp = tracker->next;
        
        // Set the next value equal to the prev
        tracker->next = tracker->prev;
        
        // Set the prev equal to the temp
        tracker->prev = temp;
        
        // Set the tracker to the next tracker's pointer
        tracker = tracker->next;
        
    }
    
    
    
    
}
