#include <stdio.h>

int main () {

    double a, b;
    int operatore = 0;

    while (operatore == 0)
    {
        printf("inserisci il valore di a e b ([valore a] [valore b]): ");
        scanf("%lf %lf", &a, &b);
        printf("selezionare l'operazione da eseguire 1-4 (+ - / *): ");
        scanf("%d", &operatore);

        switch (operatore)
        {
            case 1:
                printf("%lf + %lf = %lf", a, b, a+b);
                break;

            case 2:
                printf("%lf - %lf = %lf", a, b, a-b);
                break;

            case 3:
                if (b == 0)
                    printf("Err: Non e\' pssibile dividere per zero!");
                else
                    printf("%lf / %lf = %lf", a, b, a/b);

                break;

            case 4:
                printf("%lf * %lf = %lf", a, b, a*b);
                break;

            default:
                printf("E\' stato inserito un operatore non valido!");
        }
        printf("spegnimento? 0-1 (si/no): ");
        scanf("%d", &operatore);
    }

    return 0;
}