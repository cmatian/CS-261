/* CS261- Assignment 1 - Q.5*/
/* Name: Christopher Matian
 * Date: 1/19/2018
 * Solution description: Converts a string input to sticky caps. I.e. STICKY becomes sTiCkY. Modified the toUpperCase/toLowerCase functions to check for casing.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     
    return ch-'a'+'A';
    
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    
    return ch-'A'+'a';

}

void sticky(char* word){
     /*Convert to sticky caps*/
    
    // Even Characters 0, 2, 4, 6...
    for (int i = 0; word[i] != '\0'; i++ ) {
    
        if ( word[i] >= 'a' && word[i] <= 'z' ) {
            
            word[i] = toUpperCase(word[i]);
            
        }
        
    }
    
    // Odd Characters 1, 3, 5, 7...
    for ( int i = 1; word[i] != '\0'; i += 2) {
        
        word[i] = toLowerCase(word[i]);
        
    }
        
    
}

int main() {
    
    char word[25];
    
    /*Read word from the keyboard using scanf*/
    printf("Type in the word you want to convert to sticky caps (25 characters or less):");
    
    scanf("%25s", word);
    
    /*Call sticky*/
    
    sticky(word);
    
    /*Print the new word*/
    
    printf("%s \n", word);
    
    return 0;
}
