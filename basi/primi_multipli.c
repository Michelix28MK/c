#include <stdio.h>

int n, k, r = 0;

int main(){
    do
    {
        printf("inserire il valore di N che sia maggiore di 0: ");
        scanf("%d", &n);

        if (n <= 0)
            printf("\n\nil valore non è maggiore di 0");
    } while (n <= 0);
    do
    {
        printf("inserire il valore di K che sia maggiore di 0: ");
        scanf("%d", &k);

        if (k <= 0)
            printf("\n\nil valore non è maggiore di 0");
    } while (k <= 0);

    printf("Gli N multipli di K sono: ");

    for (int i = 0; i < n; i++)
    {
        r += k;
        printf("%d\n", r);
    }
    return 0;
}