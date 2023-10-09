#include <stdio.h>

int n, k;

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

    if (n%k == 0)
    {
        printf("N è divisibile per K ");
    }
    else{
        printf("N non è divisibile per K");
    }
    return 0;
}