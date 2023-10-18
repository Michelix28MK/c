#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char c;
    printf("inserisci un carattere: ");
    scanf("%c", &c);
    if (isalpha(c))
        printf("\nhai inserito un carattere dell'alfabeto");
    else
        printf("\nhai inserito un valore non appartenente all'alfabeto");

    if (isupper(c))
        printf("\ne\' maiuscolo");
    else
        printf("\nnot");

    if (islower(c))
        printf("\ne\' minoscolo");
    else
        printf("\nnot");
    
    return 0;
}