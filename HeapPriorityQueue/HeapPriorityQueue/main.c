//
//  main.c
//  HeapPriorityQueue
//
//  Created by Chris Matian on 6/14/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include <stdio.h>
#define TYPE int


void HeapRemoveFirst(struct dyArray *heap)
{
    int last = dyArraySize(heap) - 1;
    
    assert(last != 0);
    
    // Copy the last element to the first position
    dyArrayPut(heap, 0, dyArrayrGet(heap, last));
    
    // Remove Last Element
    dyArrayRemoveAt(heap, last);
    
    // Rebuild Heap
    adjustHeap(heap, last, 0);
}

void swap (struct dyArray *v, int i, int j)
{
    // Swap Elements i j
    TYPE temp = dyArrayGet(v, i);
    dyArrayPut(v, i, dyArrayGet(v, j));
    dyArrayPut(v, j, temp);
}

int indexSmallest (struct dyArray *v, int i, int
{
    // Return Index of Small Element
    if(LT(dyArrayGet(v, i), dyArrayGet(v, j)) {
        return i;
    }
    return j;
}
       
TYPE heapGetFirst(struct dyArray *heap) {
   assert(dyArraySize(heap) > 0);
   return dyArrayGet(heap, 0);
}
       
void _adjustHeap (struct dyArray * heap, int max, int pos)
{
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;
    if (rightChild < max) {
        // We have Two Children
        // Get Index of smallest child
        int smallest = indexSmallest(heap, leftChild, rightChild);
        
        if (heap[pos] > heap[smallest]) {
            // Swap with smallest child
            swap(heap,pos,smallest);
            
            // Adjust heap
            _adjustHeap(max,smallest);
        }
    } else if (leftchild < max) {
        // We have one child
        if (heap[pos] > heap[leftchild]) {
            // Swap with smallest Child
            swap(heap,pos,leftChild);
            
            // Adjust Heap
            _adjustHeap(max,leftChild);
        }
    }
}
       
void heapAdd (struct dyArray * heap, TYPE newValue)
{
    // Add to end - now need to adjust position
    dyArrayAdd(heap, newValue);
    
    int parent;
    int pos = dyArraySize(heap);
    
    while(pos != 0) {
        parent = (pos-1)/2;
        
        if(heap[pos] < heap[parent]) {
            swap(heap,parent,pos);
            pos = parent;
        } else {
            return;
        }
    }
}















int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
