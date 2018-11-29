/*********************************************************************
 ** Program Filename: circularList.c
 ** Author: Christopher Matian
 ** Date: 04/27/2018
 ** Email: matianc@oregonstate.edu
 *********************************************************************/

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
	// FIXME: you must write this
    struct Link *newSentinel = malloc(sizeof(struct Link));
    assert(newSentinel != NULL);
    
    // Assign the front and back nodes of the sentinel
    newSentinel->next = newSentinel;
    newSentinel->prev = newSentinel;
    
    // Assign the list argument to the sentinel we created above
    list->sentinel = newSentinel;
    
    // Initialize the size to 0
    list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
    // Allocate a new link
    struct Link *newLink = malloc(sizeof(struct Link));
    
    // Set the ptrs
    newLink->value = value;
    newLink->next = newLink->prev = NULL;
    
    // Return the newLink
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    // Create a newLink using the createLink function
    struct Link *newLink = createLink(value);

    // Add the link to the list AFTER the link argument
    newLink->next = link->next;
    newLink->prev = link;
    
    // Re-assign the link argument's pointers
    link->next->prev = newLink;
    link->next = newLink;
    
    // Increase the list size
    list->size++;
    
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
    assert(list->size > 0);
    
    // Re-assign the links that are tethered to the link we are removing
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    // Free the memory
    free(link);
    
    // Decrease the list size
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
	// FIXME: you must write this
    // Loop through each link and terminate them
    while (!circularListIsEmpty(list)) {
        circularListRemoveFront(list);
    }
    // Free the list sentinel link
    free(list->sentinel);
    
    // Free the list
    free(list);
    
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
    return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
    removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
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
	// FIXME: you must write this
    assert(!circularListIsEmpty(list));
    
    struct Link *current = list->sentinel->next;
    
    while (current != list->sentinel ) {
        
        printf("%f\t", current->value);
        
        current = current->next;
        
    }
    
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    struct Link *index = list->sentinel->next;
    struct Link *temp;
    
    list->sentinel->prev = index;
    
    do {
        
        temp = index->next;
        
        if ( temp->next == list->sentinel ) {
            
            list->sentinel->next = temp;
            
        }
        
        index->next = index->prev;
        
        index->prev = temp;
        
        index = temp;
        
    } while (index != list->sentinel );
    
    
    
    
}
