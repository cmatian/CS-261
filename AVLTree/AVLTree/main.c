//
//  main.c
//  AVLTree
//
//  Created by Chris Matian on 6/14/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//
#include <assert.h>
#include <stdio.h>
#define TYPE int

struct AVLnode {
    TYPE value;
    struct AVLnode *left;
    struct AVLnode *right;
    int height;
};

int _h(struct AVLnode * current)
{
    if (current == 0) {
        return -1;
    }
    
    return current->height;
}

void _setHeight (struct AVLnode * current)
{
    int lch = h(current->left);
    int rch = h(current->right);
    if (lch < rch) current->height = 1 + rch;
    else current->height = 1 + lch;
}

struct AVLnode * _AVLnodeAdd (struct AVLnode* current, TYPE newValue) {
    struct AVLnode * newnode;
    if (current == 0) {
        
        newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
        assert(newnode != 0);
        newnode->value = newValue;
        newnode->left = newnode->right = 0;
        return newnode;  //why don’t we balance here ??
        
    } else if (LT(newValue, current->value)) {
        current->left = AVLnodeAdd(current->left, newValue);
    } else {
        current->right = AVLnodeAdd(current->right, newValue);
    }
    
    return balance(current);    /* <-   NEW  the call on balance */
}


int _bf (struct AVLnode * current)
{
    return h(current->right) - h(current->left);
}


struct AVLnode * _balance (struct AVLnode * current)
{
    int cbf = _bf(current);
    if (cbf < -1) {
        if (bf(current->left) > 0) // double rotation
            current->left = rotateLeft(current->left);
        return rotateRight(current); // single rotation
    } else if (cbf > 1) {
        if (bf(current->right) < 0)
            current->right = rotateRight(current->right);
        return rotateLeft(current);
    }
    setHeight(current);
    return current;
}

struct AVLnode * _rotateLeft (struct AVLnode * current)
{
    struct AVLnode * newtop = current->right;
    current->right = newtop->left;
    newtop->left = current;
    setHeight(current);
    setHeight(newtop);
    return newtop;
}

struct AVLnode * _rotateRight (struct AVLnode * current)
{
    struct AVLnode * newtop = current->left;
    current->left = newtop->right;
    newtop->right = current;
    setHeight(current);
    setHeight(newtop);
    return newtop;
}

void removeAVLTree(struct AVLTree *tree, TYPE val)
{
    if (containsAVLTree(tree, val)) {
        tree->root = _removeNode(tree->root, val);
        tree->cnt--;
    }
}

TYPE _leftMost(struct AVLNode *cur)
{
    while(cur->left != 0)
    {
        cur = cur->left;
    }
    return cur->val;
}

struct AVLNode *_removeLeftmost(struct AVLNode *cur)
{
    struct AVLNode *temp;
    if(cur->left != 0)
    {
        cur->left = _removeLeftmost(cur->left);
        return _balance(cur);
    }
    temp = cur->right;
    free(cur);
    return temp;
}


struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val) {
    
    struct AVLNode *temp;
    if(EQ(val, cur->val))
    {
        if(cur->right != 0)
        {
            cur->val =  _leftMost(cur->right);
            cur->right =_removeLeftmost(cur->right);
            return _balance(cur);
        } else {
            temp = cur->left;
            free(cur);
            return temp;
        } }
    else if(LT(val, cur->val)) {
        cur->left  = _removeNode(cur->left, val);
    }
    else {
        cur->right = _removeNode(cur->right, val);
    }
    
    return _balance(cur);
}




int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


