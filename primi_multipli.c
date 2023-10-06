#include <stdio.h>

int n, k, r = 0;

int main(){
    do
    {
        printf("%s", "inserire il valore di N che sia maggiore di 0: ");
        scanf("%d", &n);

        if (n <= 0)
            printf("%s", "\n\nil valore non è maggiore di 0");
    } while (n <= 0);
    do
    {
        printf("%s", "inserire il valore di K che sia maggiore di 0: ");
        scanf("%d", &k);

        if (k <= 0)
            printf("%s", "\n\nil valore non è maggiore di 0");
    } while (k <= 0);

    printf("%s\n", "Gli N multipli di K sono: ");

    for (int i = 0; i < n; i++)
    {
        r += k;
        printf("%d\n", r);
    }
    return 0;
}