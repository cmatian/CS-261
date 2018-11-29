/*********************************************************************
 ** Program Filename: linkedListMain.c
 ** Author: Christopher Matian
 ** Date: 04/23/2018
 ** Email: matianc@oregonstate.edu
 *********************************************************************/

#include "linkedList.h"
#include <stdio.h>

int main(){
	struct LinkedList* l = linkedListCreate(); 
	linkedListAddFront(l, (TYPE)1);
    linkedListAddBack(l, (TYPE)2);
    linkedListAddBack(l, (TYPE)3);
    linkedListAddFront(l, (TYPE)4);
    linkedListAddFront(l, (TYPE)5);
    linkedListAddBack(l, (TYPE)6);
    printf("%i\n", linkedListFront(l));
    printf("%i\n", linkedListBack(l));
    linkedListPrint(l);
    linkedListRemoveFront(l);
    linkedListRemoveBack(l);
    printf("\n");
	linkedListPrint(l);
    
    printf("\n");
    printf("\n");
    
/* BAG */
	
    struct LinkedList* k = linkedListCreate();
    linkedListAdd(k, (TYPE)10);
    linkedListAdd(k, (TYPE)11);
    linkedListAdd(k, (TYPE)13);
    linkedListAdd(k, (TYPE)14);
    linkedListRemove(k, (TYPE)11);
    linkedListPrint(k);
    linkedListDestroy(k);
    printf("\n");
	return 0;
}

