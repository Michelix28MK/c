#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ptr1, *ptr2;

void set_strings(char *string)
{
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }
}

int main(void){
    char a[100], b[100], transcribe[100], answer;

    printf("File da copiare: ");
    fgets(a, sizeof(a), stdin);
    printf("File su cui copiare: ");
    fgets(b, sizeof(b), stdin);

    set_strings(a);
    set_strings(b);
//check file d'origine
    ptr1 = fopen(a, "r");
    if (ptr1 == NULL)
    {
        printf("Error: File da copiare inesistente!");
        return 1;
    }
//check file destinazione
    ptr2 = fopen(b, "r");
    if (ptr2 != NULL)
    {
        printf("\nIl file è esistente, lo si vuole sovrescrivere? (y/n)");
        scanf("%c", &answer);
        if (answer != 'y')
        {
            printf("Error: cambia file di destinazione");
            return 1;
        }
    }
//trscrizione file
    rewind(ptr1);
    fclose(ptr2);
    ptr2 = fopen(b, "w");
    
    while ((answer = getc(ptr1)) != EOF)
    {
        fprintf(ptr2,"%c", answer);
    }
//chiusura file
    fclose(ptr2);
    fclose(ptr1);
    printf("copiatura completata");

    return 0;
}