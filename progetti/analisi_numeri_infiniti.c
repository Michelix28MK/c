#include <stdio.h>

int a, p, c;

int main() {

    printf("inserire la quantità desiderata di numeri (con -1 si termina il processo):\n");

    while (a != -1)
    {
        printf("\ninserisci un ulteriore elemento: ");
        scanf("%d", &a);

        if (a%2 == 0)
            p++;

        c++;
        
    }
    
    printf("\nsono stati inseriti %d numeri dei quali %d erano pari", c-1, p);

    return 0;
}