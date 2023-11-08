#include <stdio.h>

int sommatoria = 0;
int val_sommato = 0;

int main()
{
    do
    {
        sommatoria += val_sommato;
        //printf("%d\n", val_sommato); chek dei numeri sommati
        val_sommato++;
    } while (val_sommato <= 1000);
    printf("La somma dei primi numeri naturali da 1 a 1000 è: ");
    printf("%d\n",sommatoria);
    
    return 0;
}
