#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 8
/**
 * definisci il numero dei giocatori --> user1 = {da 1 a 16}, user1 = {da 17 a 32}
 * cella vuota bianca = 33, cella vuota nera =34
*/
int main (){

    int tavola[8][8], mn[3], turno = 0;

    void set_tavola(int tavola[][DIM]); //utilizzabile per reset e set iniziale
    char trova_pedina(int tavola[][DIM], int numeri, int lettere);
    void show_tavola(int tavola[][DIM]); // mostra a schermo la situzione sulla tavola
    void next_move(int tavola[][DIM], int *turno, int numeri[]);
    /*
    void move_pedone();
    void move_re();
    void move_regina();
    void move_torre();
    void move_cavallo();
    void move_fante();
    void clear_cella();
    */

    set_tavola(tavola);
    show_tavola(tavola);
    next_move(tavola, &turno, mn);

    return 0;
}

void set_tavola(int tavola[][DIM]){ //azzera e pulisci i valori delle celle

    for (int i = 2; i <= DIM; i++)
    {
        for (int j = 0; i < DIM; i++)
        {
            tavola[i][j] = 0;
        } 
    }

    for (int i = 0; i < DIM; i++)
    {
        tavola[0][i]= (i+1); //imposta famiglia reale 1
        tavola[7][i]= (i+17); //imposta famiglai reale 2
        tavola[1][i]= (i+9); //imposta pedoni 1
        tavola[6][i]= (i+25); //imposta pedoni 2
    }
    printf("la tavola e\' stata impostata per una nuova partita:\n ");
}
char trova_pedina(int tavola[][DIM], int numeri, int lettere){
    char pedina;
    switch (tavola[numeri][lettere])
    {
        case 17: //torre
        case 24:
            pedina = 't';
            break;
        case 1:
        case 8:
            pedina = 'T';
            break;
        case 18: //cavallo
        case 23:
            pedina = 'c';
            break;
        case 2:
        case 7:
            pedina = 'C';
            break;
        case 19: //alfiere
        case 22:
            pedina = 'a';
            break;
        case 3:
        case 6:
            pedina = 'A';
            break;
        case 21:
            pedina = 'k';
            break;
        case 4:
            pedina = 'K';
            break;
        case 20:
            pedina = 'q';
            break;
        case 5:
            pedina = 'Q';
            break;
        
        default:

            if (tavola[numeri][lettere] > 8 && tavola[numeri][lettere]<=16){
                pedina = 'P';
            }
            else if (tavola[numeri][lettere]> 24 && tavola[numeri][lettere]<=32){
                pedina = 'p';
            }else{
                numeri+lettere % 2 ? pedina = 'w': pedina = 'b';
            }
            break;
    }

    return pedina;
}
void show_tavola(int tavola[][DIM]){ //mostra la situazione della tavola dopo ogni mossa
    char c;
    for (int i = 0; i < DIM; i++)
    {   
        printf("\n\t|"); //apro la riga
    
        for (int j = 0; j < DIM; j++) //determina il tipo di pedina
        {   
            c = trova_pedina(tavola, i, j);
            printf(" %c ", c);
            printf("|"); //chiudo la casella e la riga a fine ciclo
        }
        
    }
}

void next_move(int tavola[][DIM], int *numero_giocatore, int numeri[]){
    char conferma, pedina, lettere_tavola[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int lettere[1];
    do
    {
        printf("\n\nIl %d giocatore definisca la mossa da fare\n\n seleziona la pedina da spostare [lettera posizione][numero posizione]: ", *numero_giocatore+1);
        scanf("%c%d",&lettere[0], &numeri[0]);
        getchar();//buttare l'invio
        printf("seleziona la nuova posizione della pedina[lettera nuova posizione][numero nuova posizione]: ");
        scanf("%c%d - %c%d", &lettere[1], &numeri[1]);
        getchar();//butto l'invio

        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i <= strlen(lettere_tavola) ; i++)
            {
                lettere[j] == lettere_tavola[i] ?/*da inserire alternativa*/:numeri[2+j]=i;
            }
        }
        pedina = trova_pedina(tavola, numeri[0], numeri[2]);
        
        printf("la tua mossa è spostare %c in  %c%d(y/n): ", pedina, lettere[1], numeri[1]);
        scanf("%c", &conferma);

    }while (conferma != 'y');
    
}
//identifica tipo movimenti e mosse accettabili
/*
void move_pedone(int posX, int posY, int utente, int pos1X, int pos1Y);
void move_re(int posX, int posY, int utente, int pos1X, int pos1Y);
void move_regina(int posX, int posY, int utente, int pos1X, int pos1Y);
void move_torre(int posX, int posY, int utente, int pos1X, int pos1Y);
void move_cavallo(int posX, int posY, int utente, int pos1X, int pos1Y);
void move_fante(int posX, int posY, int utente, int pos1X, int pos1Y);
*/