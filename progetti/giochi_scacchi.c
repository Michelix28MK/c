#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 8
/**
 * IL GIOCO DEGLI SCACCHI
 * 
 * definisci il numero dei giocatori --> user1 = {da 1 a 16}, user1 = {da 17 a 32}
 * 
 * funzione check_re 
 *
*/
int move_pedone(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X);

int move_re(int tavola[][DIM], int posX, int posY, int *utente, int pos1X, int pos1Y);
/*
void move_regina(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y);

void move_torre(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y);

void move_cavallo(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y);

void move_alfiere(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y);
*/
int main (){

    int tavola[8][8], turno = 0, exit = 0;

    void set_tavola(int tavola[][DIM]); //utilizzabile per reset e set iniziale

    char trova_pedina(int tavola[][DIM], int numeri, int lettere);

    void show_tavola(int tavola[][DIM]); // mostra a schermo la situzione sulla tavola

    int next_move(int tavola[][DIM], int *numero_giocatore);

    set_tavola(tavola);
    do
    {
        show_tavola(tavola);
        //da inserire funzione controllo della morte del re per terminare la partita
        exit = next_move(tavola, &turno);
    } while (exit);
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
    printf("la tavola e\' stata impostata per una nuova partita:\n\n il giocatore 1 ha le pedine maiuscole (QK)\n");
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
                    pedina = ' ';
                    else
                    pedina = '\333';
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

int next_move(int tavola[][DIM], int *numero_giocatore){
    
    int numeri[4], exit = 0;
    char lettera[2], lettere_tavola[9] = {"ABCDEFGH"}, pedina,  conferma;
    do
    { 
        do
        {
            printf("\n\nIl %d giocatore definisca la mossa da fare\n\nSeleziona la pedina da spostare e seleziona la nuova posizione della pedina [lettera posizione][numero posizione] [lettera nuova posizione][numero nuova posizione] : ", *numero_giocatore+1);
            scanf("%c%d %c%d",&lettera[0], &numeri[0], &lettera[1], &numeri[1]); //raccoglie la mossa
            getchar();

            for (int i = 0; i < sizeof(lettera); i++) //trovo l'indice della lettera
            {
                for (int j = 0; j < sizeof(lettere_tavola); j++) //ricordiamoci di non sbagliare il size of :P 
                {
                    if(lettera[i] == lettere_tavola[j]){
                        numeri[i+2] = j;
                    }
                }
            }
            if (((numeri[1]-1< 0) || (numeri[1]-1>7)) || (numeri[3]<0 || numeri[3]>7))
            {
                printf("\ncoordinata di destinazione fuori mappa\n");
            }
            
        } while (((numeri[1]-1< 0) || (numeri[1]-1>7)) || (numeri[3]<0 || numeri[3]>7));
        
        pedina = trova_pedina(tavola, numeri[0]-1, numeri[2]);
        
        printf("la tua mossa e\' spostare %c in  %c%d (y/n): ", pedina, lettera[1], numeri[1]);
        scanf("%c", &conferma);
        getchar();

    }while (conferma != 'y');

    switch (pedina)
    {
    case 't':
    case 'T':
        //move_torre(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'c':
    case 'C':
        //move_cavallo(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'a':
    case 'A':
       // move_alfiere(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'q':
    case 'Q':
        //move_regina(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'k':
    case 'K':
        move_re(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'p':
    case 'P':
        move_pedone(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    default:
        printf("Error: non hai selezionato una pedina!");
        exit = 1;
        break;
    }

    return exit;
}
//identifica tipo movimenti e mosse accettabili

int move_pedone(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X){
    int exit = 0;
    /**
     * REGOLE DI MOVIMENTO
     * può andare solo in avanti
     * alla prima mossa può spostarsi di 2 a tutte le altre può spostarsi di 1
     * può mangiare solo in diagonale di 1
    */
    if (*utente)
    {       // pedine a disposizione dalla 25 alla 32
        int primo_spostamento_Y = (posY == 6);
        int spostamento_Y_doppio_valido = (pos1Y - posY < 0) && (pos1Y - posY > -3);
        int spostamento_Y_singolo_valido = (pos1Y - posY < 0) && (pos1Y - posY > -2); //spostamento in avanti standard
        int spostamento_X_valido = (pos1X - posX < 2) && (pos1X - posX > -2);//spostamento laterale da -1 e +1
        int spostamento_X_nullo = (pos1X - posX == 0);
        int cella_frontale_libera = !tavola[posY-1][posX];
        int due_cella_frontali_libere = (!tavola[posY-2][pos1X]) && cella_frontale_libera; //se libera restituisce 1 se occupata restituisce 0| sistemare il metodo di controllo
        int nemico_nella_cella_DX = (tavola[posY-1][posX+1] > 16);
        int nemico_nella_cella_SX = (tavola[posY-1][posX-1] > 16);

        if ((primo_spostamento_Y && spostamento_Y_doppio_valido && due_cella_frontali_libere && spostamento_X_nullo)/*avanzamento doppio*/ ||
            (spostamento_Y_singolo_valido && cella_frontale_libera && spostamento_X_nullo)/*avanzamento dingolo*/ ||
            (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_DX) /*mangia DX*/ ||
            (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_DX) /*mangia SX*/)
        {
            tavola[pos1X][pos1Y] = tavola[posX][posY];
            tavola[posX][posY] = 0;
            *utente = !*utente;
        }else{
            printf("Error: Mossa non valida! ripetere il turno.");
            exit = 1;
        }
    }else{ //pedine a disposizione dalla 9 alla 16 alla 
        //determino se la posizione davanti è libera
        int primo_spostamento_Y = (posY == 1);
        int spostamento_Y_doppio_valido = (pos1Y - posY > 0) && (pos1Y - posY < 3);
        int spostamento_Y_singolo_valido = (pos1Y - posY > 0) && (pos1Y - posY < 2); //spostamento in avanti standard
        int spostamento_X_valido = (pos1X - posX < 2) && (pos1X - posX > -2);//spostamento laterale da -1 e +1
        int spostamento_X_nullo = (pos1X - posX == 0);
        int cella_frontale_libera = !tavola[posY+1][posX];
        int due_cella_frontali_libere = (!tavola[posY+2][pos1X]) && cella_frontale_libera; //se libera restituisce 1 se occupata restituisce 0| sistemare il metodo di controllo
        int nemico_nella_cella_DX = (tavola[posY+1][posX+1] > 16);
        int nemico_nella_cella_SX = (tavola[posY+1][posX-1] > 16);

        if ((primo_spostamento_Y && spostamento_Y_doppio_valido && due_cella_frontali_libere && spostamento_X_nullo)/*avanzamento doppio*/ ||
            (spostamento_Y_singolo_valido && cella_frontale_libera && spostamento_X_nullo)/*avanzamento dingolo*/ ||
            (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_DX) /*mangia DX*/ ||
            (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_DX) /*mangia SX*/)
        {
            tavola[pos1X][pos1Y] = tavola[posX][posY];
            tavola[posX][posY] = 0;
            *utente = !*utente;

        }else{
            printf("Error: Mossa non valida! ripetere il turno.");
            exit = 1;
        }

    }
    int fine_tavola = (pos1Y == 7) && (pos1Y == posY + 1) || (pos1Y == 0) && (pos1Y == posY - 1);
    if (fine_tavola) //se il pedone selezionato riesce ad arrivare alla fine allora gli si fascegliere una figura con cui sostituirlo
    {
        printf(" con cosa vuoi sostituire il tuo pedone?"); //da sviluppare
    }

    return exit;
}

int move_re(int tavola[][DIM], int posX, int posY, int *utente, int pos1X, int pos1Y){

    int exit = 0;

    int movimento_nullo = (tavola[pos1Y][pos1X] == !tavola[posY][posX]);
    int spostamento_x = (pos1X > posX -2) && (pos1X < posX +2);
    int spostamento_y = (pos1Y > posY -2) && (pos1Y < posY +2);
    
    if (spostamento_x && spostamento_y && !movimento_nullo)
    {
        tavola[pos1X][pos1Y] = tavola[posX][posY];
        tavola[posX][posY] = 0;
        *utente = !*utente;
    }else{
        printf("Error: Mossa non valida! ripetere il turno.");
        exit = 1;
    }
    return exit;  
}
/*
void move_torre(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_cavallo(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_alfiere(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_regina(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){
}*/