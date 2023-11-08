 #include <stdio.h>

 /********************************************************
 * Calcola il m.c.d di due interi a, b > 0 applicando *
 * l'algoritmo delle sottrazioni successive di Euclide. *
 ********************************************************/

 int main(void){
    int a=214, b=128, c; //Deve essere a,b > 0
    
    printf("inserisci il primo valore: ");
    scanf("%d", &a);
    printf("\ninserisci il secondo valorie: ");
    scanf("%d", &b);

    if (a<0 || b<0)
    {
        printf("Error: una o entrambe le variabili inserite non sono maggiori di zero!");
        return -1;
    }

    printf("\nIl m.c.d. di %d e %d e': ",a,b);

    while (a != b){
        c++;
        if (a > b) //Se a > b,
            a -= b;//sostituisci a con a-b.
        else //Altrimenti,
        b -= a;//sostituisci b con b-a.
    }
    printf("%d\n nummero di cicli eseguiti sono %d",a, c);
return 0;
}