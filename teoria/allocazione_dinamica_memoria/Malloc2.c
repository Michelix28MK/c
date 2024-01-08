#include <stdio.h>

int main (){

    int show_menu();

    int selezione_menu;
    double *lista;

    do
    {
        selezione_menu = show_menu();

        switch (selezione_menu)
        {
        case 1:
            /* code */
            break;
        case 2:
            break;
        case 3:
            break;
        }

    } while (selezione_menu != 4);
    

    return 0;
}

int show_menu(){
    
    int a;

    printf("Seleziona un elemento dal menu:\n\n1. \tInserisci elenco di double\n2. \tOrdina elenco\n3. \tVisualizza elenco\n4. \tTermina\n\nNumero selezionato: ");
    scanf("%d", &a);

    return a;
}

void generate_list(int *a){

    int numero;

    printf("\nquanti numeri voglione essere registrati?");
    scanf("%d", &numero);

    a = (double *)malloc(sizeof(double) * numero);

    if (a == NULL)
    {
        printf("Error: malloc assignment fail!");
        return -1;
    }

    for (int i = 0; i < numero; i++)
    {

        printf("\ninserisci il %d elemento:", i + 1);
        scanf("%lf", &a[i]);
        getchar();
    }
}