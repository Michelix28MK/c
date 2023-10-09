#include <stdio.h>
#include <stdbool.h>

int n, k, c=1, a;
bool go = true;

int main(){

    printf("Si otterrà la somma di numeri consecutivi contenuti nel numero inserito:\n\n");
    do
    {
        printf("inserire il valore di N che sia maggiore di 0: ");
        scanf("%d", &n);

        if (n <= 0)
            printf("\n\nil valore non è maggiore di 0");
    } while (n <= 0);
    
    do
    {
        a += c; 
        //printf("\nValore di c: %d, il valore di a: %d, ilvalore di k: %d\n", c, a, k);
        if (a<=n)
        {
            k++;
            c++;
        }
        else
        {
            go = false;
        }
    } while (go);
    
    printf("Il valore di k e\' :%d", k);

    return 0;
}