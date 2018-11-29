/*
 * This is the file in which you'll write the functions required to 
implement
 * a stack using two queues.  Make sure to add your name and 
@oregonstate.edu
 * email address below:
 *
 * Name: Christopher Matian
 * Email: matianc@oregonstate.edu
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef TYPE
#define TYPE int
#endif

/**************************************************
 All of the initial Queue functions
 ***************************************************/
struct link {
	TYPE value;
	struct link * next;
};

struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
	int size;
};

/*
* This function takes a queue and allocates the memory. It then
* creates a sentinel and assigns the first link and last link
* to the sentinel.
*/
void listQueueInit(struct listQueue *q) {
    
    // FIXME: you must write this
    q = malloc(sizeof(struct listQueue));
    q->size = 0;
    
    // Sentinel Production
    struct link *sentinel = malloc(sizeof(struct link));
    assert(sentinel != NULL);
    sentinel->next = NULL;
    
    // Set queue link to sentinel
    q->firstLink = q->lastLink = sentinel;
}

/*
 * This function creates a new queue. Parts of the create include 
allocating
 * the memory, initializing all of the values and returning a pointer to 
the newly
 * created queue.
 */
struct listQueue * listQueueCreate()
{
    //FIXME: you must write this
    struct listQueue *q = malloc(sizeof(struct listQueue));
    
    listQueueInit(q);
    
    return q;
	
}


/*
* This function returns a 1 or 0 based on the statement looking at
* the first link. If the next value is null it is empty, and will return 1
*/
int listQueueIsEmpty(struct listQueue *q) {
	
    //FIXME: you must write this
    // Check that a queue exists
    assert(q != NULL);
    
    // Will return the head as 1 (if it's not empty) and 0 if it's not empty
    return q->firstLink == NULL;

}

/*
 * This function adds a new link and value to the back of the queue. It 
takes
 * a list and a type variable, allocates the memory and adjusts the proper 
links
 * to make the connection. No return value.
 */
void listQueueAddBack(struct listQueue *q, TYPE e) {
	
    // FIXME: you must write this
    // Check that queue exists
    assert(q != NULL);
    
    // Allocate memory for a new link to add
    struct link* newLink = malloc(sizeof(struct link));
    
    // Make sure that the new link was created properly
    assert(newLink);
    
    // Set the value and next pointers
    newLink->value = e;
    newLink->next = NULL;
    
    // If the tail exists, set the tail's next pointer to the new link
    if (q->lastLink) {
        
        q->lastLink->next = newLink;
        
    }
    // Otherwise the tail is equal to the new link
    q->lastLink = newLink;
    
    // If the head doesn't exist
    if (!q->firstLink) {
        
        // Set the head equal to the new link
        q->firstLink = newLink;
        
    }
    
    q->size++;

}

/*
 * This function takes a list argument and removes the link at the front.
 */
void listQueueRemoveFront(struct listQueue *q) {

    
    // FIXME: you must write this
    // Is the queue created & does it have a head
    assert(q != NULL);
    
    if ( q->firstLink ) {
    
        // Create a target pointer to the head
        struct link* target = q->firstLink;
        
        // Set the queue head equal to the target's next pointer
        q->firstLink = target->next;
        
        // If the tail is equal to the target it will set the tail to null
        if (q->lastLink == target) {
            
            q->lastLink = NULL;
            
        }
        
        q->size--;
        
        // Free the target
        free(target);
        
    } else {
        
        printf("Command failed - stack is empty.\n");
        
    }

}

/*
 * Function returns the value at the front of the list.
 */
TYPE listQueueFront(struct listQueue *q) {
	
    // FIXME: you must write this
    assert(q && q->firstLink);
    return q->firstLink->value;

}


/*
* This function is a tester function that iterates through the list
* and prints out the values at each link.
*/
void printList(struct listQueue* l)
{
	assert(l != 0);
	
	struct link * printMe = l->firstLink->next;

	while (printMe!= NULL)
	{
		printf("Value: %d\n", printMe->value);
		printMe = printMe->next;
	}
}

/**************************************************
Stack Implementation
***************************************************/

struct linkedListStack {
	struct listQueue *Q1;
	struct listQueue *Q2;
	int structSize;
};

/*
 * This function initializes the values of the created Stack. Initializes 
both 
 * queues and the structSize.
 */
void linkedListStackInit(struct linkedListStack * s)
{
	// FIXME: you must write this
    s->Q1 = listQueueCreate();
    s->Q2 = listQueueCreate();
    s->structSize = 0;
    
 }

/*
* This function creates the linked list stack. It allocates the memory and 
calls the
* initialization function to initialize all of the values. It then returns 
the stack.
*/
struct linkedListStack * linkedListStackCreate(){

    // FIXME: you must write this
    struct linkedListStack *stack = malloc(sizeof(struct linkedListStack));
    
    linkedListStackInit(stack);
    
    return stack;

}

/*
* This function returns 1 if the linked list stack is empty and otherwise 
returns a 0.
*/
int linkedListStackIsEmpty(struct linkedListStack *s) {

	// FIXME: you must write this
    assert(s);
    return (listQueueIsEmpty(s->Q1) && listQueueIsEmpty(s->Q2));

}

/*
 * This is the linked list acting as a stack push function. It takes 
 * a linked list stack argument and a value and pushes it onto the stack. 
The
 * funciton then also increases the size of the stack by 1. 
 */
void linkedListStackPush(struct linkedListStack *s, TYPE d) {
	
        // FIXME: you must write this
    
    // Check that stack exists and call the listQueueAddBack function which will add to the second queue
    assert(s);
    listQueueAddBack(s->Q2, d);
    
    // While queue 1 is not empty
    while(!listQueueIsEmpty(s->Q1)) {
        
        // push values from q2 using the front of q1
        listQueueAddBack(s->Q2, listQueueFront(s->Q1));

        // Remove the item from the front of q1
        listQueueRemoveFront(s->Q1);
        
    }
    
    // Set q1 equal to q2 using a temp queue that holds q1's data
    struct listQueue *temp = s->Q1;
    s->Q1 = s->Q2;
    s->Q2 = temp;
    
    // Increase the overall size
    s->structSize++;


}
/*
 * This funciton pops a value off of the stack. It does this by moving all 
values
 * that are currently on the stack to the other queue. The stack top is 
maintained
 * at the back of the queue list. 
 */
void linkedListStackPop(struct linkedListStack *s) {
	
    // FIXME: you must write this
    listQueueRemoveFront(s->Q1);
    
    // Decrease the oversall size
    s->structSize--;

}
/*
 * This function returns the value that is at the back of the queue that 
is 
 * maintaing the values of the stack. 
 */
TYPE linkedListStackTop(struct linkedListStack *s) {

    // FIXME: you must write this
    assert(s);
    return listQueueFront(s->Q1);

}

/*
 * This function gores through the stack and removes each link in the 
queue.
 * It then frees the struct itself. 
 */
void linkedListStackFree(struct linkedListStack *s){
	
      assert(s != 0);
	
	while (s->structSize != 0) 
	{
		linkedListStackPop(s);
	}

	free(s->Q1->firstLink);
	free(s->Q2->firstLink);
	free(s->Q1);
	free(s->Q2);

	free(s);



}

/*
 * Main is used to test the stack ADT.
 */
int main(int argc, char* argv[])
{
	struct linkedListStack *stack = linkedListStackCreate();

	//Test Stack
	//Push 4 values onto the stack
	printf("Pushing the value: 1\n");
	linkedListStackPush(stack, 1);
	printf("Pushed.\n\n");
    printf("Value at the top of stack: %d\n",
           linkedListStackTop(stack));

	printf("Pushing the value: 2\n");
	linkedListStackPush(stack, 2);
	printf("Pushed.\n\n");
    printf("Value at the top of stack: %d\n",
           linkedListStackTop(stack));

	printf("Pushing the value: 3\n");
	linkedListStackPush(stack, 3);
	printf("Pushed.\n\n");
    printf("Value at the top of stack: %d\n",
           linkedListStackTop(stack));

	printf("Pushing the value: 4\n");
	linkedListStackPush(stack, 4);
	printf("Pushed.\n\n");
    printf("Value at the top of stack: %d\n", 
           linkedListStackTop(stack));



	//Print value at the top and then remove it
	printf("Value at the top of stack %d now being popped. \n",linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));  
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	//Try to pop when the stack is empty prints error:
	printf("Trying to pop empty stack:\n");

	linkedListStackPop(stack);

	
	//Push and Pop alternating
	printf("Pushing the value: 10\n");
	linkedListStackPush(stack, 10);
	printf("Pushed.\n\n");

	printf("Pushing the value: 11\n");
	linkedListStackPush(stack, 11);
	printf("Pushed.\n\n");

	printf("One more pop:\n");
	linkedListStackPop(stack);
	printf("Value at the top of stack: %d\n", 
    linkedListStackTop(stack));

	linkedListStackFree(stack);

	return 0;

}


