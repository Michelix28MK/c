#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define bit 8

int a, b;

int main() {

    printf("inserisci il numero binario a 8 cifre per la conversione:\n");

    for (int i = 0; i < bit; i++)
    {
        printf("inserisci il %d elemento: ", i+1);
        scanf("%d", &a);
        b += pow(2,i) * a;
    }

    printf("\nil valore del numero e\' %d: ", b);

    return 0;
}