#include <stdio.h>

int n, k;

int main(){
    
    CICLO_N:
    printf("%s", "inserire il valore di N che sia maggiore di 0: ");
    scanf("%d", &n);

    if (n <= 0){

        printf("%s", "\n\nil valore non è maggiore di 0");
        goto CICLO_N;
    }

    CICLO_K:
    printf("%s", "inserire il valore di K che sia maggiore di 0: ");
    scanf("%d", &k);

    if (k <= 0){
        printf("%s", "\n\nil valore non è maggiore di 0");
        goto CICLO_K;
    }

    if (n%k == 0)
    {
        printf("%s\n", "N è divisibile per K ");
    }
    else{
        printf("%s\n", "N non è divisibile per K");
    }
    return 0;
}