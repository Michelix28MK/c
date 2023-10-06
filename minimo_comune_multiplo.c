#include <stdio.h>

int n, k, c;

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
        printf("%s", "\n Il minimo comune multiplo e': ");
        printf("%d", n);
    } else {
        //imposto la partenza del processo
        c = n;

        do
        {
            c += n;

        } while (c%k != 0);
        
        printf("%s", "\n Il minimo comune multiplo e': ");
        printf("%d", c);
    }
    return 0;
}