#include <stdio.h>
#include <stdlib.h>

#define UNO (n/100000000)%10
#define DUE (n/10000000)%10
#define TRE (n/1000000)%10
#define QUATTRO (n/100000)%10
#define CINQUE (n/10000)%10
#define SEI (n/1000)%10
#define SETTE (n/100)%10
#define OTTO (n/10)%10
#define NOVE n%10
#define EX printf("%c\n", letto);

int main() {
    unsigned int n;
    unsigned char letto;

    do
    {   
        printf("inserisci la cifra: ");
        letto = getchar();
        getchar();//scarico dell'invio
        printf("\033[A"); // Sposta il cursore su una riga sopra - codice di escape, che indica che seguiranno dei comandi di controllo ANSI.
        printf("\033[K"); //sovrascrive l'interariga su cui si trova il cursore
        
        switch (letto)
        {   
            case '1':
                if (UNO != 1){n += 100000000; EX} break;
            case '2':
                if (DUE != 2){n += 20000000; EX} break;
            case '3':
                if (TRE != 3){n += 3000000; EX} break;
            case '4':
                if (QUATTRO != 4){n += 400000; EX} break;
            case '5':
                if (CINQUE != 5){n += 50000; EX} break;
            case '6':
                if (SEI != 6){n += 6000; EX} break;
            case '7':
                if (SETTE != 7){n += 700; EX} break;
            case '8':
                if (OTTO != 8){n += 80; EX} break;
            case '9':
                if (NOVE != 9){n += 9; EX} break;
            case '0':
                printf("\nla sequenza e\' finita!"); break;
            default:
                printf("Error: \tCarattere inserito non valido! -->"); break;
        }
    } while (letto != '0');
    return 0;
}