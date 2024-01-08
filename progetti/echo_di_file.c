#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

int echo(char *s)
{
    fptr = fopen(s, "r");
    if (fptr == NULL)
        return -1;

    char st[100];
    while (fgets(st, sizeof(st), fptr))
    {
        printf("%s", st);
    }
    fclose(fptr);
    return 0;
}
int main (void)
{
    int error;
    char string[100];

    printf("Inserisic il nome del file da aprire: ");
    fgets(string, sizeof(string), stdin);

    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }
    
    error = echo(string);

    if (error != 0)
        printf("Error: %d", error);    
    
    return 0;
}
