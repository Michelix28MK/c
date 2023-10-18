#include <stdio.h>
#include <math.h>

int main(){

    float a, b, c, delta, sol1, sol2;

    do
    {
        printf("inserire il valore di A diverso da 0 : ");
        scanf("%f", &a);
        
    } while (a == 0);

    printf("\ninserire il valore di B : ");
    scanf("%f", &b);
    printf("\ninserire il valore di C : ");
    scanf("%f", &c);

    printf("\nL'equazione da risolvere e\': %dx^2 + (%d)x + = 0", a ,b, c);
    // calcolo del delta

    delta= (b,2) - 4 * a * c;

    sol1 = (-b + sqrt(delta))/(2 * a);
    sol2 = (-b - sqrt(delta))/(2 * a);
    
    if (delta > 0)
    {
        printf("le soluzioni reali sono %f e %f", sol1, sol2);
    }else if (delta< 0)
    {
        printf("non seistono soluzioni reali per questa deisquazione (delta negativo)");
    } else{
        printf("esiste una soluziono reale che è %f", sol1);
    }
    
    

    
    printf("la soluzione e\' x = %d/%d",b ,a);
    return 0;
}