/* CS261- Assignment 1 - Q.4*/
/* Name: Christopher Matian
 * Date: 04/05/2018
 * Solution description:
 My solution involved first producing an array which held a maximum of 100 characters, then asking the user for a string input.
 After, I would validate the information by looping through each char in the array. If it found an uppercase char it would set the flag to 0.
 If the flag was still true (1), it would execute the camelCase function which takes in the word and loops through each char. If the function
 hits an underscore symbol during the loop it will set the next char to uppercase.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}


void camelCase(char* word){
     /*Convert to camelCase*/
    int index = 0;
    
    for (int i = 0; word[i] != '\0'; i++) {
        
        if ( word[i] == '_' ) {
            
            word[i + 1] = toUpperCase(word[i + 1]);
            
        } else {
            
            word[index++] = word[i];
            
        }
    }
    word[index] = '\0';
    
    // printf("\nThe new string length is: %d\n", index);
    
}

int main(){
    /*Read the string from the keyboard */
    char ch[100];
    int flag = 1;
    
    printf("Enter a lowercase word for camelCasing in this format: 'some_word_to_turn_into_a_camel'\n");
    scanf("%s", ch);
    
    for(int i = 0; ch[i] != '\0'; i++) {
        
        if ((ch[i] >= 'A' && ch[i] <= 'Z') ||
            (ch[i] == '!' ||
             ch[i] == ' ' ||
             ch[i] == '@' ||
             ch[i] == '#' ||
             ch[i] == '$' ||
             ch[i] == '%' ||
             ch[i] == '^' ||
             ch[i] == '&' ||
             ch[i] == '*' ||
             ch[i] == '(' ||
             ch[i] == ')' ||
             ch[i] == '-' ||
             ch[i] == '=' ||
             ch[i] == '+' ||
             ch[i] == '`' ||
             ch[i] == '~' ||
             ch[i] == '<' ||
             ch[i] == '>' ||
             ch[i] == '?' ||
             ch[i] == '.' ||
             ch[i] == ',' ||
             ch[i] == '/' ||
             ch[i] == '|' ||
             ch[i] == '\\' ||
             ch[i] == '[' ||
             ch[i] == ']' ||
             ch[i] == '{' ||
             ch[i] == '}' ||
             ch[i] == ':' ||
             ch[i] == ';' ||
             ch[i] == '\'' )) {
            
            flag = 0;

        }
    }
    
    /*Call camelCase*/
    if (flag == 1) {
        camelCase(ch);
    } else {
        
        printf("Invalid input, please enter a string that contains only underscore or lowercase characters.\n");
        
    }
    
    /*Print the new the string */
    if ( flag == 1 ) {
        printf("\nThe new camelCase string is: %s\n", ch);
    }
    
    return 0;
}
