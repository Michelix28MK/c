#include <stdio.h>
float a,b;
char c;
int main() {
    printf("insersci l'operazione da risolvere ([numero1][operatore][numero2]): \n");
    scanf("%f%c%f", &a, &c, &b);

    switch (c)
    {
        case '+':
            printf("= %f", a+b);
            break;

        case '-':
            printf("= %f", a-b);
            break;

        case '*':
            printf("= %f", a*b);
            break;

        case '/':
            b==0?printf("scarabottolo non approva la tua scelta peccaminosa, confessati davanti all LC2"):printf("= %f", a/b);
            break;
        default:
            printf("operatore errato! \n"); 
            break;
    }
}

//da risolvere esercizio dei doppi con meno spazio possibile!! (00 di domenica)