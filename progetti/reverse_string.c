#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fgetss(char *str)
{
    if( fgets (str, BUFSIZ, stdin)==NULL )
    {
        printf("Err:w");
        return -1;
    }

    int i = 0;
    for (;str[i] != '\n'; i++);
    str[i]= '\0';
    
    return 0;
}

int main (void)
{
    char str1[BUFSIZ], str2[BUFSIZ], c;
    printf("inserisci la stringa: ");
    fgetss(str1);

    printf("str1 = %s, dimensione = %d", str1, strlen(str1));
    size_t i = 0;
    for (; i < strlen(str1); i++)
    {
        str2[i] = str1[strlen(str1)-(1+i)];
    }
    str2[i+1] = '\0';

    printf("\nstr1 = %s, str2 = %s", str1, str2);

    return 0;
}