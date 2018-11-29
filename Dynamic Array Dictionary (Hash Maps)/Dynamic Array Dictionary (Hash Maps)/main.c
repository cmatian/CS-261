//
//  main.c
//  Dynamic Array Dictionary (Hasp Maps)
//
//  Created by Chris Matian on 6/14/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include <stdio.h>


void dyArrayDictionaryGet (struct dynArray *da, KEYTYPE key, VALUETYPE *valptr)
{
    for (int i = 0; i < da->size; i++) {
        if (strcmp(da->data[i]->key, key) == 0) {
            *valptr = da->data[i]->value;
        }
    }
}

void dyArrayDictionaryPut (struct dynArray *da, KEYTYPE key, VALUETYPE val)
{
    struct association * ap;
    if (dyArrayDictionaryContainsKey(da, key)) {
        dyArrayDictionaryRemove(da, key);
    }
    ap = (struct association *) malloc(sizeof(struct association));
    assert(ap != 0);
    ap->key = key;
    ap->value = val;
    dyArrayAdd(da, ap);
}

int dyArrayDictionaryContainsKey (struct dynArray *da, KEYTYPE key)
{
    for(int i = 0; i < da->size; i++) {
        // Assuming DynArr has struct association called 'data'
        if(strcmp(key, da->data[i]->key) == 0) {
            return 1;
        }
    }
    return 0;
}

void dyArrayDictionaryRemove (struct dynArray *da, KEYTYPE key)
{
    struct association * ap;
    for(int i = 0; i < da->size; i++) {
        // Assuming DynArr has struct association called 'data'
        if(strcmp(key, da->data[i]->key) == 0) {
            struct association *temp;
            temp = da->data[i];
            removeAtDynArr(da, i);
            free(temp);
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
