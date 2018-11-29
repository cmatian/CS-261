/*
 * CS 261 Data Structures
 * Assignment 5
 * Name: Christopher Matian
 * Date: 05/29/2018
 */

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char *word = nextWord(file);
    
    while (word) {
        hashMapPut(map, word, 1);
        free(word);
        word = nextWord(file);
    }
    
    free(word);
}

/* Levenshtein Function */
int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return(column[s1len]);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"/quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
        
        // Convert to lower case for comparison
        int idx = 0;
        while(inputBuffer[idx]) {
            
            inputBuffer[idx] = tolower(inputBuffer[idx]);
            idx++;
            
        }
        
        int index = HASH_FUNCTION(inputBuffer) % hashMapCapacity(map);
        if(index < 0) {
            
            index += hashMapCapacity(map);
            
        }
        
        HashLink *current = map->table[index];
        
        if(strcmp(inputBuffer, "/quit") == 0) {
            
            quit = 1;
            printf("Exiting Spellchecker\n");
            
        } else if (hashMapContainsKey(map, inputBuffer)) {
                
            printf("The word is spelled correctly\n");

        } else {
            
            int suggestion = 0;
            
            printf("Could not find the word in the dictionary, did you mean...\n");
            while(current) {
                // Generate a levenshtein difference
                current->value = levenshtein(inputBuffer, current->key);
                if (suggestion != 5) {
                    
                    if(current->value <= 3) {
                        
                        printf("%s\n", current->key);
                        suggestion++;
                        
                    }
            
                }

                current = current->next;

            }
        }
    }
    
    hashMapDelete(map);
    return 0;
}
