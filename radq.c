#include <stdio.h>
#include <math.h> //Intestazione necessaria per double sqrt(double)

int main(void){
    double d;
    do{
        printf("Inserisci un numero reale non negativo: ");
        scanf("%lf",&d);
    } while (d<0);

    printf("La radice quadrata di %g e' %g.\n",d,sqrt(d));
    return 0;
}
