//
//  main.c
//  BSTIterator
//
//  Created by Chris Matian on 6/14/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include <stdio.h>

struct BSTIterator
{
    struct DynArr *stk;
    struct BSTree *tree;
};

void BSTIteratorInit (struct BSTree *tree, struct BSTIterator *itr)
{
    itr->tree = tree;
    itr->stk = newDynArr(); /* Dyn arr imp of a stack */
}

int BSTIteratorHasNext (struct BSTIterator * itr)
{
    BNode *n;
    
    if(isEmptyDynArr(itr->stk)) {
        
        slideLeft(itr->tree->root);
        
    } else {
        
        n = topDynArr(itr->stk);
        popDynArr(itr->stk);
        slideLeft(n->right);
        
    }
    
    if(!isEmptyDynArr(itr->stk)) {
        return 1;
    } else {
        return 0;
    }
}

TYPE BSTIteratorNext (struct BSTIterator *itr)
{
    return (topDynArr(itr->stk))->val;
}

void _slideLeft(struct Node *cur, struct BSTIterator *itr)
{
    while(cur != null) {
        dynArrayPush(Itr->stk, cur);
        cur = cur->left;
    }
}

void treeSort (TYPE *data, int n)
{
    // sort values in array data
    AVLtree tree;
    AVLIterator itr;
    int i = 0,
        count = 0
    ;
    AVLtreeInit (&tree);
    
    for(i=0; i < n ; i++) {
        AVLAddTree(&tree, data[i]);
    }
    // assuming you have an iterator
    AVLIteratorInit(&tree, &itr);
    
    while(AVLIteratorHasNext(&itr)) {
        data[count] = AVLIteratorNext(&itr);
        count = count + 1;
    }
}


void treeSort (TYPE *data, int n)
{
    // sort values in array data
    AVLtree tree;
    int count = 0;
    
    AVLtreeInit (&tree);
    
    for(int i = 0; i < n; i++) {
        AVLAddTree(&tree, data[i]);
    }
    // Assuming no iterator
    _treeSortHelper(tree->root, data, &count);
}

void _treeSortHelper( AVLNode *cur, TYPE *data, int *count)
{
    if(cur != 0) {
        _treeSortHelper(cur->left, data, count);
        data[*count] = cur->val;
        *count = *count + 1;
        _treeSortHelper(cur->right, data, count);
    }
}










int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
