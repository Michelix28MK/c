#include <stdio.h>
#include <stdlib.h>

void bubble_sort_dcr(double *array, int numeri);

int main(void)
{
    double *array;
    int numero;

    printf("\nquanti numeri voglione essere registrati?");
    scanf("%d", &numero);

    array = (double *)malloc(sizeof(double) * numero);

    if (array == NULL)
    {
        printf("Error: malloc assignment fail!");
        return -1;
    }

    for (int i = 0; i < numero; i++)
    {

        printf("\ninserisci il %d elemento:", i + 1);
        scanf("%lf", &array[i]);
        getchar();
    }

    bubble_sort_dcr(array, numero);

    for (int i = 0; i < numero; i++)
        printf("\nil %d valore è: %lf", i + 1, array[i]);

    free(array); // libera lamemoria del puntatore

    return 0;
}

void bubble_sort_dcr(double *array, int numeri)
{
    int finito = 1, assist;

    do
    {
        finito = 1;
        for (int i = 1; i < numeri; i++)
            if (array[i - 1] < array[i])
            {
                assist = array[i - 1];
                array[i - 1] = array[i];
                array[i] = assist;
                finito = 0;
            }
    } while (finito);
}