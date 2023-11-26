#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 8
/**
 * IL GIOCO DEGLI SCACCHI
 * 
 * to do:
 * 
 * funzione sostituzione pedone a fine tavola!
 * movimento torre
 * movimento cavallo
 * movimento alfiere
 * fix re e trova re!
 *

void move_cavallo(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y);

void move_alfiere(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y);
*/
int main (void){

    int tavola[DIM][DIM], turno = 0;

    void set_tavola(int tavola[][DIM]); //utilizzabile per reset e set iniziale

    int trova_re(int tavola[][DIM], int funzione);

    char trova_pedina(int tavola[][DIM], int numeri, int lettere);

    void show_tavola(int tavola[][DIM]); // mostra a schermo la situzione sulla tavola

    int next_move(int tavola[][DIM], int *numero_giocatore);

    set_tavola(tavola);
    do
    {
        show_tavola(tavola);
        next_move(tavola, &turno);
    } while (trova_re(tavola, 1));

    trova_re(tavola, 0);

    return 0;
}

void set_tavola(int tavola[][DIM]){
    for (int i = 0; i < DIM; i++) //azzera la memoria
    {
        for (int j = 0; j < DIM; j++)
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

int trova_re(int tavola[][DIM], int funzione){

    int re1 = 0, re2 = 0, risultato;

    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            if (tavola[i][j] == 4)
                re1 = 1;
            else if (tavola[i][j] == 21)
                re2 = 1; 
    if (funzione)    
        if (re1 && re2)
            risultato = 1;
        else
            risultato = 0;
    else
        if (re1)
            printf("Il giocatore 2 Ha VINTO!");
        else if (re2)
            printf("Il Giocatore 1 Ha VINTO!");

    return risultato;
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
    printf("\n\t     A   B   C   D   E   F   G   H\n\t    -------------------------------"); //estetica in console
    for (int i = 0; i < DIM; i++)
    {
        printf("\n\t %d |", i+1); //apro la riga
        for (int j = 0; j < DIM; j++) //determina il tipo di pedina
        {   
            c = trova_pedina(tavola, i, j);
            printf(" %c ", c);
            printf("|"); //chiudo la casella e la riga a fine ciclo
        }
        printf(" %d ", i+1);
    }
    printf("\n\t    -------------------------------\n\t     A   B   C   D   E   F   G   H");
}

int next_move(int tavola[][DIM], int *numero_giocatore){
    
    int numeri[4], exit = 0;
    char lettera[2], lettere_tavola[9] = {"ABCDEFGH"}, pedina,  conferma;

    int move_re(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina);

    int move_pedone(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina);

    void move_torre(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina);

    void move_regina(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X);

    do
    { 
        do
        {
            printf("\n\nIl %d giocatore definisca la mossa da fare\n\nSeleziona la pedina da spostare e seleziona la nuova posizione della pedina [lettera posizione][numero posizione] [lettera nuova posizione][numero nuova posizione] : ", *numero_giocatore+1);
            scanf("%c%d %c%d",&lettera[0], &numeri[0], &lettera[1], &numeri[1]); //raccoglie la mossa
            getchar();

            for (int i = 0; i < sizeof(lettera); i++) //trovo l'indice della lettera
                for (int j = 0; j < sizeof(lettere_tavola); j++) //ricordiamoci di non sbagliare il size of :P 
                    if(lettera[i] == lettere_tavola[j])
                        numeri[i+2] = j;
                        
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
        printf("\n\nspostamento torre ");
        move_torre(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3], 0);
        break;
    case 'c':
    case 'C':
        printf("\n\nspostamento alfiere ");
        //move_cavallo(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'a':
    case 'A':
        printf("\n\nspostamento alfiere ");
       // move_alfiere(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'q':
    case 'Q':
        printf("\n\nspostamento regina ");
        move_regina(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3]);
        break;
    case 'k':
    case 'K':
        printf("\n\nspostamento re "); 
        move_re(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3], 0);
        break;
    case 'p':
    case 'P':
        printf("\n\nspostamento pedone ");
        move_pedone(tavola, numeri[0]-1, numeri[2], numero_giocatore, numeri[1]-1, numeri[3], 0);
        break;
    default:
        printf("Error: non hai selezionato una pedina!");
        exit = 1;
        break;
    }

    return exit;
}
//identifica tipo movimenti e mosse accettabili

int move_pedone(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina){
    int exit = 0;
    /**
     * REGOLE DI MOVIMENTO
     * può andare solo in avanti
     * alla prima mossa può spostarsi di 2 a tutte le altre può spostarsi di 1
     * può mangiare solo in diagonale di 1
    */
   int primo_spostamento_Y, spostamento_Y_doppio_valido, spostamento_Y_singolo_valido, spostamento_X_valido, spostamento_X_nullo, cella_frontale_libera, due_cella_frontali_libere, nemico_nella_cella_DX, nemico_nella_cella_SX, fine_tavola;

    if (*utente)
    {       // pedine a disposizione dalla 25 alla 32
        primo_spostamento_Y = (posY == 6);
        spostamento_Y_doppio_valido = (pos1Y - posY < 0) && (pos1Y - posY > -3);
        spostamento_Y_singolo_valido = (pos1Y - posY < 0) && (pos1Y - posY > -2); //spostamento in avanti standard
        spostamento_X_valido = (pos1X - posX < 2) && (pos1X - posX > -2);//spostamento laterale da -1 e +1
        spostamento_X_nullo = (pos1X - posX == 0);
        cella_frontale_libera = !tavola[posY-1][posX];
        due_cella_frontali_libere = (!tavola[posY-2][pos1X]) && cella_frontale_libera; //se libera restituisce 1 se occupata restituisce 0| sistemare il metodo di controllo
        nemico_nella_cella_DX = (tavola[posY-1][posX+1] < 16 && tavola[posY-1][posX+1] > 0);
        nemico_nella_cella_SX = (tavola[posY-1][posX-1] < 16 && tavola[posY-1][posX+1] > 0);
        fine_tavola = (pos1Y == 0) && (pos1Y == (posY - 1));
    }else{ //pedine a disposizione dalla 9 alla 16 alla 
        //determino se la posizione davanti è libera
        primo_spostamento_Y = (posY == 1);
        spostamento_Y_doppio_valido = (pos1Y - posY > 0) && (pos1Y - posY < 3);
        spostamento_Y_singolo_valido = (pos1Y - posY > 0) && (pos1Y - posY < 2); //spostamento in avanti standard
        spostamento_X_valido = (pos1X - posX < 2) && (pos1X - posX > -2);//spostamento laterale da -1 e +1
        spostamento_X_nullo = (pos1X - posX == 0);
        cella_frontale_libera = !tavola[posY+1][posX];
        due_cella_frontali_libere = (!tavola[posY+2][pos1X]) && cella_frontale_libera; //se libera restituisce 1 se occupata restituisce 0| sistemare il metodo di controllo
        nemico_nella_cella_DX = (tavola[posY+1][posX+1] > 16);
        nemico_nella_cella_SX = (tavola[posY+1][posX-1] > 16);
        fine_tavola = (pos1Y == 7) && (pos1Y == (posY + 1));
    }
    if ((primo_spostamento_Y && spostamento_Y_doppio_valido && due_cella_frontali_libere && spostamento_X_nullo)/*avanzamento doppio*/ ||
        (spostamento_Y_singolo_valido && cella_frontale_libera && spostamento_X_nullo)/*avanzamento dingolo*/ ||
        (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_DX) /*mangia DX*/ ||
        (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_SX) /*mangia SX*/)
        {
            tavola[pos1Y][pos1X] = tavola[posY][posX];
            tavola[posY][posX] = 0;
            *utente = !*utente;
        }else{
            printf("Error: Mossa non valida! ripetere il turno.\n");
            exit = 1;
        }
    if (fine_tavola) //se il pedone selezionato riesce ad arrivare alla fine allora gli si fascegliere una figura con cui sostituirlo
    {
        printf("con cosa vuoi sostituire il tuo pedone?"); //da sviluppare
    }

    return exit;
}

int move_re(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina){
    /**
     * REGOLE DI MOVIMENTO
     * 
     * spostamento in ogni direzione di 1
    */
    int libera_amica;
    int exit = 0;
    int movimento_nullo = ((pos1X -posX) == 0) && ((pos1Y - posY) == 0);
    int spostamento_x = (pos1X - posX > -2) && (pos1X - posX < 2);
    int spostamento_y = (pos1Y - posY > -2) && (pos1Y - posY < 2);

    if(*utente)
        libera_amica = ((tavola[pos1Y][pos1X]<17));
    else
        libera_amica = ((tavola[pos1Y][pos1X]>16) || (tavola[pos1Y][pos1X] == 0));
    
    if (spostamento_x && spostamento_y && !movimento_nullo && libera_amica)
    {
        tavola[pos1Y][pos1X] = tavola[posY][posX];
        tavola[posY][posX] = 0;
        *utente = !*utente;
    }else{
        regina ? printf("\nin ricerca del movimento corretto...") : printf("Error: Mossa non valida! ripetere il turno.\n");
        exit = 1;
    }
    return exit;  
}

void move_regina(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X){
    /**
     * REGOLE DI MOVIMENTO
     * 
     * spostamento del re, della torre e dell'alfiere
    */

    if (move_pedone(tavola, posY, posX, utente, pos1Y, pos1X, 1) || move_re(tavola, posY, posX, utente, pos1Y, pos1X, 1))
        printf(" ");
    else
        printf("\nError: Mossa non valida! ripetere il turno.\n");
}
void move_torre(int tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina){
    /**
     * REGOLE DI MOVIMENTO
     * 
     * spostamento o in verticale o in orizzontale (no diagonale)
     * nessun limiti di celle
    */
}
/*
void move_cavallo(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
void move_alfiere(int tavola[][DIM], int posX, int posY, int utente, int pos1X, int pos1Y){

}
*/