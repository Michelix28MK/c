#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a = 97;
int z = 122;

void set_string(char *s)
{
    int len = strlen(s);
    if (len > 0  && s[len-1] == '\n')
    {
        s[len-1] = '\0';
    }
}
void cifra(char *stringa, int k)
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (!((int)stringa[i]<a) || ((int)stringa[i]>z)) //solo caratteri minuscoli
        {
            //printf("\n%c + %d =>", stringa[i], k);
            if ((stringa[i] + k) > z)
                stringa[i] += (k - 25);
            else
                stringa[i] += k;
            //printf("%c", stringa[i]);
        }
    }
}
void decifra(char *stringa, int k)
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (!((int)stringa[i]<a) || ((int)stringa[i]>z))
        {
            //printf("\n%c - %d =>", stringa[i], k);
            if ((stringa[i] - k) < a)
                stringa[i] -= (k + 25);
            else
                stringa[i] -= k;
            //printf("%c", stringa[i]);
        }
    }
}
struct riga
{
    int numero_puntatori;
    char *caratteri[BUFSIZ];
};

int LeggiRiga(struct riga *righe_lette, FILE *testo)
{   
    char appoggio_cattura_riga[BUFSIZ];
    int lunghezza_riga;
    // leggo la riga
    if(fgets(appoggio_cattura_riga, BUFSIZ, testo) == NULL)
        return 0;
    // definisco lunghezze
    lunghezza_riga = strlen(appoggio_cattura_riga);
    //malloc
    righe_lette->caratteri[righe_lette->numero_puntatori] = (char*)malloc(sizeof(char) * lunghezza_riga);
    //assegnazione
    strcpy(righe_lette->caratteri[righe_lette->numero_puntatori], appoggio_cattura_riga);
    //incremento counter
    righe_lette->numero_puntatori++;

    return 1;
}

int main(void)
{   // genero la struttura per la lettura
    struct riga file_letto;
    file_letto.numero_puntatori = 0;

    FILE *ptr;
    char titolo[BUFSIZ], save;
    int shift, fine_file, funzionalita;
    //funzionalità
    printf("\n 1 - cifra \n 2 - decifra \n\n scelta: ");
    scanf("%d", &funzionalita);
    getchar();
    //selezione file
    printf("Inserisci il nome del file da cifrare: ");
    fgets(titolo, BUFSIZ, stdin);
    set_string(titolo);
    ptr = fopen(titolo, "r");
    if (ptr == NULL)
    {
        printf("Err: File insesistente");
        return 1;
    }
    
    printf("Fattore di spostamento: ");
    scanf("%d", &shift);
    getchar();
    //leggi file
    fine_file = LeggiRiga(&file_letto, ptr);
    while (fine_file)
        fine_file = LeggiRiga(&file_letto, ptr);
    
    //esegui funzionalità
    if (funzionalita == 1)
    {
        for (size_t i = 0; i < file_letto.numero_puntatori; i++)
        {
            cifra(file_letto.caratteri[i], shift);
        }   
    }
    else
    {
        for (size_t i = 0; i < file_letto.numero_puntatori; i++)
        {
            decifra(file_letto.caratteri[i], shift);
        }
    }
    fclose(ptr);
    //stampa file
    printf("\n\nIl file è stato cifrato: ");
    for(int i = 0; file_letto.numero_puntatori > i; i++)
        printf("\n%s", file_letto.caratteri[i]);
    //libero malloc
    printf("\n\nSalvare il testo in un nuovo file (y/n): ");
    scanf("%c", &save);
    getchar();

    if (save == 'y')
    {   //titolo
        printf("\nInserisci il titolo.txt: ");
        fgets(titolo, BUFSIZ, stdin);
        //apri file
        set_string(titolo);
        ptr = fopen(titolo, "w");
        rewind(ptr);

        for (size_t i = 0; i < file_letto.numero_puntatori; i++)
        {
            fprintf(ptr, "%s", file_letto.caratteri[i]);
        }
        printf("\nFine copiatura");
    }
    return 0;
}