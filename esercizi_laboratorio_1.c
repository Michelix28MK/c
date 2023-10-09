#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int a = INT_MAX, b[2];
float num = FLT_MIN;

int main (){

    printf("Esercizio1: scrivere un programma che stampi:\nHello word\n");
    printf("\nEsercizio2: scrivere un programma che stampi: \n Hellow,\n word\n");
    printf("\nEsercizio3: Scrivi un programma che tabulizza il testo: \n\tdato1 \tdato2 \n\tdato3 \tdato4\n");
    printf("\nEsercizio4: stampa la scritta Ciao tramite codici Hashii: \103 \111 \101 \117"); //codice octa ascii
    printf("\nEsercizio5: Stamnpa i limit di variabile di:\n\tcarattere (%d | %d) \tinteri(%d | %d)\n", CHAR_MIN, CHAR_MAX, INT_MIN, INT_MAX);
    printf("\nEsercizio6: Stamnpa i limit di variabile di:\n\tfloat (%g | %g) \tduble(%g | %g)", FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX);

    a++;
    printf("\nEsercizio7: assegna 'INT_MAX' a una varaiabile e incremente di uno, il risultato è %d", a);

    num = num/FLT_MAX;

    printf("\nEsercizio8: il valore di 'FLT_MIN'/'FLT_MAX' e\' : %f", num);
    printf("\nEsercizio9: inserisci un valore numerico ce verrà stampato: ");
    scanf("%d", &a);
    printf("il numero e\' %d", a);
    printf("\nEsercizio10: inserisci 2 valori di cui si restituirà delle operazioni:\n ");

    for (int i = 0; i < 2; i++)
    {   
        printf("\nInserire il %d valore: ", i+1);
        scanf("%d", &b[i]);
    }
    printf("\n\tsomma: %d \tsottrazione: %d \tprodotto: %d \trapporto: %d \tmodulo: %d", (b[1]+b[2]), (b[1]-b[2]), (b[1]*b[2]), (b[1]/b[2]), (b[1]%b[2]));
     //testare a pezzi per identificare il problema
    return 0;
}