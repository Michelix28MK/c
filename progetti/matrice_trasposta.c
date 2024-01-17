#include <stdio.h>
#include <stdlib.h>

int main (void)
{   
    int t[10][10], m[10][10], c ,d;
    do
    {
        printf("Quante righe e colonne: ");
        scanf("%d", &c);
        //gets("\n");
    } while (c < 0 || c > 10);
    //compila matrice

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Inserisci l'elemento (%d %d): ", i, j);
            scanf("%d", &m[i][j]);
            //gets();
        }
    }

    for (size_t i = 0; i < c; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            t[j][i] = m[i][j];
        }
        
    }

    printf("\n");
    
    for (int i = 0; i < c; i++)
    {
        printf("|");
        for (int j = 0; j < c; j++)
        {   
            printf(" %d |", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < c; i++)
    {
        printf("|");
        for (int j = 0; j < c; j++)
        {   
            printf(" %d |", t[i][j]);
        }
        printf("\n");
    }
    
    //inverti


    return 0;
}