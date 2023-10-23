#include <stdio.h>

int main() {

    int i, j, n, flag = 1;

    do {
        printf("Inserisci una cifra massima per calcolare i numeri primi: ");
        scanf("%d", &n);

    } while (n<=0);

    printf("Numeri primi fino a %d:", n);

    for (i = 2; i <= n; i++){//counter

        for (j = 2; j < i; j++){ //divisore

            if (i % j == 0)
                flag = 0; // Il numero non è primo se è divisibile per i
        }

        if (flag) 
            printf("\n%d ", i);
        flag = 1;
    }

    printf("\n FINE");

    return 0;
}
