#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ptr;

void set_string(char *s)
{
    int len = strlen(s);
    if (len > 0  && s[len-1] == '\n')
    {
        s[len-1] = '\0';
    }
}

int check_eof(char *s)
{
    char carattere;
    for (size_t i = 0; i < strlen(s); i++)
    {
        carattere = s[i];
        if((carattere != '\x04') || (carattere != '\x1a'))
            s[i]= '\0';
    }
    if ((carattere == '\x04') || (carattere == '\x1a'))
        return 0;
    return 1;
}

int main (void)
{
    char name[100], riga[BUFSIZ], conferma;

    printf("Nome del file che si sta per scrivere: ");
    fgets(name, sizeof(name), stdin);//recupero il nome
    set_string(name);//controllo la formattazione

    ptr = fopen(name, "w"); //apro il file in write mod

    if (ptr != NULL)
    {
        printf("\nstai sovrascrivendo un file già esistente, continuare?(y/n) ");
        scanf("%c", &conferma);
        if (conferma != 'y')
            return -1;
    }

    printf("inizio trascrizione ... (Termina con: Ctrl + D Unix/ Ctrl + Z windows)\n");
    
    while (check_eof(riga))
    {
        fgets(riga, sizeof(riga), stdin);
        fprintf(ptr, "%s", riga);
    }

    printf("\noperazione di scrittura terminata!");

    return 0;
}