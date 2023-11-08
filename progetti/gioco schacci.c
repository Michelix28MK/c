#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 8
/**
 * IL GIOCO DEGLI SCACCHI
 * 
 * definisci il numero dei giocatori --> user1 = {da 1 a 16}, user1 = {da 17 a 32}
 * cella vuota bianca = 33, cella vuota nera =34
*/
int main (){

    int tavola[8][8], mn[5], turno = 0;

    void set_tavola(int tavola[][DIM]); //utilizzabile per reset e set iniziale

    char trova_pedina(int tavola[][DIM], int numeri, int lettere);

    void show_tavola(int tavola[][DIM]); // mostra a schermo la situzione sulla tavola

    void next_move(int tavola[][DIM], int *turno);

    void move_pedone();
    void move_re();
    void move_regina();
    void move_torre();
    void move_cavallo();
    void move_alfiere();
    void clear_cella();

    set_tavola(tavola);
    show_tavola(tavola);
    //da inserire funzione controllo della morte del re per terminare la partita
    next_move(tavola, &turno);

    return 0;
}

void set_tavola(int tavola[][DIM]){
    for (int i = 0; i <= DIM; i++) //azzera la memoria
    {
        for (int j = 0; j <= DIM; j++)
        {
            tavola[i][j] = 0;
        } 
    }
    for (int i = 0; i < DIM; i++) //posiziona le pedine
    {
        tavola[0][i]= (i+1); //imposta famiglia reale 1
        tavola[1][i]= (i+9); //imposta pedoni 1
        tavola[7][i]= (i+17); //imposta famiglai reale 2
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
        case 21: //re
            pedina = 'k';
            break;
        case 4:
            pedina = 'K';
            break;
        case 20: //regina
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
                if((lettere+numeri)%2)
                    pedina = 'w';
                    else
                    pedina = 'b';
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
        printf(" %d ", i+1);
    }
    printf("\n\t  A   B   C   D   E   F   G   H");
}

void next_move(int tavola[][DIM], int *numero_giocatore){
    
    int numeri[4] = {0,0,0,0};
    char lettera[2]={'x', 'y'}, lettere_tavola[8] = {"ABCDEFGH"}, pedina,  conferma;
    do
    { 
        printf("\n\nIl %d giocatore definisca la mossa da fare\n\nSeleziona la pedina da spostare e seleziona la nuova posizione della pedina [lettera posizione][numero posizione] [lettera nuova posizione][numero nuova posizione]: ", *numero_giocatore+1);
        scanf("%c%d %c%d",&lettera[0], &numeri[0], &lettera[1], &numeri[1]); //raccoglie la mossa
        getchar();

        for (int i = 0; i < sizeof(lettera); i++) //trovo l'indice della lettera
        {
            for (int j = 0; j < sizeof(lettere_tavola); j++) //ricordiamoci di non sbagliare il size of :P 
            {
                if(lettera[i] == lettere_tavola[j]){
                    numeri[i+2] = j;
                    //printf("\n per la lettera %c = %c",lettera[i], lettere_tavola[j]);
                }
            }
        }
        pedina = trova_pedina(tavola, numeri[0]-1, numeri[2]);
        
        printf("la tua mossa è spostare %c in  %c%d (y/n): ", pedina, lettera[1], numeri[1]);
        scanf("%c", &conferma);
        getchar();

    }while (conferma != 'y');

    switch (pedina)
    {
    case 't':
    case 'T':
        move_torre(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'c':
    case 'C':
        move_cavallo(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'a':
    case 'A':
        move_alfiere(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'q':
    case 'Q':
        move_regina(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'k':
    case 'K':
        move_re(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    default:
        break;
    }
}
//identifica tipo movimenti e mosse accettabili

void move_pedone(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_re(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_regina(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_torre(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_cavallo(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_alfiere(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}