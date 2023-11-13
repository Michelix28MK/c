#include <stdio.h>
#define DIM 100
int equal_to(char *s, char *t);

int main(void){
    char s[DIM], t[DIM];
    printf("inserisci la prima riga: ");
    fgets(s, DIM, stdin);

    printf("inserisci la seconda riga: ");
    fgets(t, DIM, stdin);

    printf("\n%d", equal_to(s, t));

    return 0;
}

equal_to( char *s, char *t){
    
    int risultato = 0;

    if (sizeof(s) == sizeof(t))
    {
        for (int i = 0; i < sizeof(s); i++)
        {
            !(s[i] == t[i])? risultato = 1 : 1==1 ;
        }
    } else if (sizeof(s)< sizeof(t)){
        
        for (int i = 0; i < sizeof(t); i++)
        {
            !(s[i] == t[i])? risultato = 0 : 1==1;
        }
    } else{
        for (int i = 0; i < sizeof(s); i++)
        {
            !(s[i] == t[i])? risultato = 0 : 1==1;
        }
    }
        
    return risultato;
}