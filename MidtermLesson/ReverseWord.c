#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[100];
    char reversed_word[100];
    int len, i, j;
    printf("Enter the Word: ");
    fgets(word, sizeof(word), stdin);

    len = strlen(word);
    
    i = 0;
    for(j = len - 1; j >= 0; i++,j--){
        reversed_word[i] = word[j];
    }
    reversed_word[i] = '\0';

    printf("Reversed: ", reversed_word);

    return 0;
}