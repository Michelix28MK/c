#include <stdio.h>

int a, b;

int main(){

    do
    {
        printf("inserire il valore di A diverso da 0 : ");
        scanf("%d", &a);
        
    } while (a == 0);

    printf("\ninserire il valore di B : ");
    scanf("%d", &b);

    printf("\nL'equazione da risolvere e\': %dx + (%d) = 0", a ,b);

    b = -b;

    if (a<0 && b<0)
    {
        a = -a;
        b = -b;   
    }
    
    printf("la soluzione e\' x = %d/%d",b ,a);
    return 0;
}