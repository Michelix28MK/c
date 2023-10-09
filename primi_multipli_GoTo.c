#include <stdio.h>

int n, k, i, r = 0;

int main(){
    
    CICLO_N:
    printf("inserire il valore di N che sia maggiore di 0: ");
    scanf("%d", &n);

    if (n <= 0){

        printf("\n\nil valore non è maggiore di 0");
        goto CICLO_N;
    }

    CICLO_K:
    printf("inserire il valore di K che sia maggiore di 0: ");
    scanf("%d", &k);

    if (k <= 0){
        printf("\n\nil valore non è maggiore di 0");
        goto CICLO_K;
    }

    printf("Gli N multipli di K sono: ");

    CICLO_MULTIPLI:
    i++;
    r += k;
    printf("%d\n", r);

    if (i < n)
        goto CICLO_MULTIPLI;
    
    return 0;
}