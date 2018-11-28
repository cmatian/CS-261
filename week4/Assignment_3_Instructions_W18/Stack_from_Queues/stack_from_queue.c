/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name: Christopher Matian
 * Email: matianc@oregonstate.edu
 *
 * Source References: https://www.geeksforgeeks.org/implement-stack-using-queue/
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* All by yourself */
/* Stack like behavior using Two Queues */

/* Structure Definition & Function Prototypes */

// Link Structure
struct link {
    
    int value;
    struct link* next;
    
};

// Stack Structure
struct stack {
    
    struct queue* q1;
    struct queue* q2;
    
};

// Queue Structure
struct queue {
    
    struct link* head;
    struct link* tail;
    
    
};

// Prototypes for Queue
struct queue* createQueue();                        // Create a Queue
void freeQueue(struct queue* queue);                // Free the Queue
int isEmptyQueue(struct queue* queue);              // Return NULL if empty
void enQueue(struct queue* queue, int value);       // Adds to the back of the queue
int deQueue(struct queue* queue);                   // Remove from the front of the queue
int front(struct queue* queue);                     // Returns the value at the front of the queue

// Prototypes for Stack Functions
struct stack* createStack();                         // Creates the Stack
void freeStack(struct stack* stack);                 // Frees the Stack
int isEmptyStack(struct stack* stack);               // Returns NULL if empty
void pushStack(struct stack* stack, int value);      // Pushes a value to the stack
int popStack(struct stack* stack);                   // Removes a value from the stack;
int topStack(struct stack* stack);                   // Returns the value at the top of the stack


// Main (Contains tests for the stack of two queues)

int main() {
    
    struct stack *stack = createStack();
    
    pushStack(stack, 1);
    printf("%d\n", topStack(stack)); // Should be 1 [ Worked ]
    pushStack(stack, 2);
    printf("%d\n", topStack(stack)); // Should be 2 [ Worked ]
    pushStack(stack, 3);
    printf("%d\n", topStack(stack)); // Should be 3 [ Worked ]
    pushStack(stack, 4);
    printf("%d\n", topStack(stack)); // Should be 4 [ Worked ]
    pushStack(stack, 5);
    printf("%d\n", topStack(stack)); // Should be 5 [ Worked ]
    
    printf("%d\n", isEmptyStack(stack)); // Should be 0 if stack is not empty [ Worked ]
    
    popStack(stack);
    printf("%d\n", topStack(stack)); // Should be 4 [ Worked ]
    popStack(stack);
    printf("%d\n", topStack(stack)); // Should be 3 [ Worked ]
    popStack(stack);
    printf("%d\n", topStack(stack)); // Should be 2 [ Worked ]
    popStack(stack);
    printf("%d\n", topStack(stack)); // Should be 1 [ Worked ]
    popStack(stack);
    
    printf("%d\n", isEmptyStack(stack)); // Should be 1 if stack is empty [ Worked ]
    
    // printf("%d\n", topStack(stack)); // Assertion Should fail and exit the program [ Worked ]
    
    freeStack(stack);
    
    return 0;
}


// Function Definitions for Queue

// createQueue
// Initializes and creates a queue and assigns the head and tail pointers to null. Returns the queue.

struct queue* createQueue() {
    
    struct queue* queue = malloc(sizeof(struct queue));
    
    assert(queue);
    
    queue->head = NULL;
    queue->tail = NULL;
    
    return queue;
    
}

// freeQueue
// Accepts queue as a parameter and while it's not empty, it will call the dequeue function which removes items from the front
void freeQueue(struct queue* queue) {
    
    while (!isEmptyQueue(queue)) {
        // Remove from front while queue is not empty
        deQueue(queue);
        
    }
    // free the allocated memory
    free(queue);
    
}

// isEmptyQueue
// Returns null if the function is not empty, otherwise it will return 1 indicating that it is empty
int isEmptyQueue(struct queue* queue) {
    
    // Check that a queue exists
    assert(queue);
    
    // Will return the head as 0 (if it's not empty) and 0 if it's not empty
    return queue->head == NULL;
    
}
// enQueue
// Adds to the queue at the back
void enQueue(struct queue* queue, int value) {
    
    // Check that queue exists
    assert(queue);
    
    // Allocate memory for a new link to add
    struct link* newLink = malloc(sizeof(struct link));
    
    // Make sure that the new link was created properly
    assert(newLink);
    
    // Set the value and next pointers
    newLink->value = value;
    newLink->next = NULL;
    
    // If the tail exists, set the tail's next pointer to the new link
    if (queue->tail) {
        
        queue->tail->next = newLink;
        
    }
    // Otherwise the tail is equal to the new link
    queue->tail = newLink;
    
    // If the head doesn't exist
    if (!queue->head) {
        
        // Set the head equal to the new link
        queue->head = newLink;
        
    }
    
}

// deQueue
// Removes the item at the front of the queue
int deQueue(struct queue* queue) {
    
    // Is the queue created & does it have a head
    assert(queue && queue->head);
    
    // Create a target pointer to the head
    struct link* target = queue->head;
    // Create an int value that holds the target's value
    int value = target->value;
    // Set the queue head equal to the target's next pointer
    queue->head = target->next;
    
    // If the tail is equal to the target it will set the tail to null
    if (queue->tail == target) {
        
        queue->tail = NULL;
        
    }
    
    // Free the target
    free(target);
    
    // Return the value for print statements and other sibling functions
    return value;
    
}

// front
// Front will return the item at the front of the queue
int front(struct queue* queue) {
    
    assert(queue && queue->head);
    return queue->head->value;
    
}



// Function Definitions for Stack

// createStack();
// Will initialize and create a new stack using the two queue structures and the createQueue() function
struct stack* createStack() {
    
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    
    return stack;
    
    
}

// freeStack
// Will call the freeQueue function and free the queues inside of the pseudo stack. Afterwards, it will free the stack itself
void freeStack(struct stack* stack) {
    
    assert(stack);
    freeQueue(stack->q1);
    freeQueue(stack->q2);
    free(stack);
    
}

// isEmptyStack
// Checks whether or not the stack is empty or not; very similar to the isEmptyQueue function
int isEmptyStack(struct stack* stack) {
    
    assert(stack);
    return (isEmptyQueue(stack->q1) && isEmptyQueue(stack->q2));
    
}

// pushStack
// Pushes to the top of the stack
void pushStack(struct stack* stack, int value) {
    
    // Check that stack exists and call the enqueue function which will add to the second queue
    assert(stack);
    enQueue(stack->q2, value);
    
    // While queue 1 is not empty
    while(!isEmptyQueue(stack->q1)) {
        
        // push values from q2 using the front of q1
        enQueue(stack->q2, front(stack->q1));
        // Remove the item from the front of q1
        deQueue(stack->q1);
        
    }
    
    // Set q1 equal to q2 using a temp queue that holds q1's data
    struct queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    
    
}

// popStack
// Removes from the top of the stack using the dequeue function
int popStack(struct stack* stack) {
    
    assert(stack);
    return deQueue(stack->q1);
    
}

// topStack
// Returns the value at the top of the stack
int topStack(struct stack* stack) {
    
    assert(stack);
    return (front(stack->q1));
    
}

