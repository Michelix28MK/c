#include <stdio.h>
#include <stdlib.h>

void BubbleSort(double *a, int n)
{
    int c;
    double d;
    do
    {
        c = 1;
        for (size_t i = 1; i < n; i++)
        {
            if (a[i - 1] < a[i])
            {
                d = a[i - 1];
                a[i - 1] = a[i];
                a[i] = d;
                c = 0;
            }
        }

    } while (c != 1);
}

int main(void)
{
    int n;
    double *array;
    printf("Inserisci quanti valori vuoi inserire: ");
    scanf("%d", &n);

    array = (double *)malloc(n * sizeof(double));

    for (size_t i = 0; i < n; i++)
    {
        printf("inserisci il %d numero :", i + 1);
        scanf("%lf", &array[i]);
    }

    BubbleSort(array, n);

    for (size_t i = 0; i < n; i++)
    {
        printf("\n %lf", array[i]);
    }

    free(array);

    return 0;
}