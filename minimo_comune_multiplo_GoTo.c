#include <stdio.h>

int n, k, c;

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
    //sorting
    if (n<k)
    {
        c=n;
        n=k;
        k=c;
    }
    //parto dal più grande
    //controllo la divisibilità reciproca
    //sommo sommo n a sestesso.
    if (n%k == 0)
    {
        printf("\n Il minimo comune multiplo e': ");
        printf("%d", n);
    } else {
        //imposto la partenza del processo
        c = n;

        RICERCA_MCM:
        c += n;

        if (c%k != 0)
            goto RICERCA_MCM;

        printf("\n Il minimo comune multiplo e': ");
        printf("%d", c);
    }
    return 0;
}