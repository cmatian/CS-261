//
//  main.c
//  Hash Table (Open Address)
//
//  Created by Chris Matian on 6/14/18.
//  Copyright © 2018 Chris Matian. All rights reserved.
//

#include <stdio.h>

void initOpenHashTable (struct openHashTable * ht, int size) {
    assert (size > 0);
    ht->table = (TYPE **) malloc(size * sizeof(TYPE *));
    assert(ht->table != 0);
    for (int i = 0; I < size; i++) {
        // Initialize as Empty
        ht->table[i] = 0;
    }
    ht->tablesize = size;
    ht->count = 0;
}

int openHashTableSize (struct openHashTable *ht)
{
    return ht->count;
}

void openHashTableAdd (struct openHashTable * ht, TYPE *newValue)
{
    int idx;
    ht->count++;
    // Make sure we have space and under the load factor threshold
    if ((ht->count / (double) ht->tablesize) > 0.75) {
        _resizeOpenHashTable(ht);
    }
    idx = HASH(newValue) % ht->tablesize;
    
    /* To be safe, use only positive arithmetic. % may behave very differently on diff
     implementations or diff languages . However, you can do the following to deal with a
     negative result from HASH */
    if (idx < 0) {
        idx += ht->tablesize;
    }
    
    while(idx >= 0) {
        
        if(idx == ht->tablesize) {
            idx = 0;
        }
        
        if(ht->table[idx] == 0) {
            ht->table[idx] = newValue;
            idx = -1;
        } else {
            idx++;
        }
    }
}

int openHashTableBagContains (struct openHashTable *ht, TYPE newValue) {
    int idx;
    idx = HASH(newValue) % ht->tablesize;
    
    if (idx < 0) {
        idx += ht->tablesize;
    }
    
    while(ht->table[idx] != 0) {
        if(compare(ht->table[idx], newValue) == 0) {
            return 1;
        }
        idx++;
        
        if(idx == ht->tableSize) {
            idx = 0;
        }
    }
    
    return 0;
}

void _resizeOpenHashTable (struct openHashTable *ht) {
    int i;
    int oldSize = ht­>tablesize;
    int newSize = 2 * oldSize;
    TYPE ** temp = ht­>table;
    initOpenHashTable(ht, newSize);
    for (i = 0; i < oldSize; i++) {
        if (temp[i] != 0) {
            openHashTableAdd(ht, temp[i]);
        }
    }
    free(temp);
}






















int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
