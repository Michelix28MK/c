#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 8
/**
 * IL GIOCO DEGLI SCACCHI
 * team 1: 1T, 2C, 3A, 4K, 5Q, 6P
 * team 2: 7t, 8c, 9a, 10k, 11q, 7p
 */
int main(void)
{
    unsigned tavola[DIM][DIM];
    int turno = 0;

    void set_tavola(unsigned tavola[][DIM]); // utilizzabile per reset e set iniziale

    int trova_re(unsigned tavola[][DIM], int funzione); // controlla la presenza di entrambi i re

    char trova_pedina(unsigned tavola[][DIM], int numeri, int lettere);

    void show_tavola(unsigned tavola[][DIM]); // mostra a schermo la situzione sulla tavola

    void next_move(unsigned tavola[][DIM], int *numero_giocatore);

    set_tavola(tavola);
    do
    {
        show_tavola(tavola);
        next_move(tavola, &turno);
    } while (trova_re(tavola, 1));

    show_tavola(tavola);
    trova_re(tavola, 0);

    return 0;
}

void set_tavola(unsigned tavola[][DIM])
{
    for (size_t i = 0; i < DIM; i++) // azzera la memoria
    {
        for (size_t j = 0; j < DIM; j++)
        {
            tavola[i][j] = 0;
        }
    }
    for (size_t i = 0; i <= DIM / 2; i++) // posiziona le pedine
    {
        tavola[0][i] = (i + 1); // imposta famiglia reale 1 (1-5)
        tavola[0][DIM - i - 1] = (i + 1);
        tavola[1][i] = 6; // imposta pedoni 1
        tavola[1][DIM - i - 1] = 6;
        tavola[6][i] = 12; // imposta pedoni 2
        tavola[6][DIM - i] = 12;
        tavola[7][i] = (i + 7); // imposta famiglai reale 2 (7-11)
        tavola[7][DIM - i - 1] = (i + 7);
    }
    tavola[0][4] = 4;   // re
    tavola[0][3] = 5;   // q
    tavola[7][4] = 10; // re
    tavola[7][3] = 11;  // q
    printf("la tavola e\' stata impostata per una nuova partita:\n\n il giocatore 1 ha le pedine MAIUSCOLE (QK)\n");
}

int trova_re(unsigned tavola[][DIM], int funzione)
{
    int re1 = 0, re2 = 0, risultato;

    for (size_t i = 0; i < DIM; i++)
        for (size_t j = 0; j < DIM; j++)
            if (tavola[i][j] == 4)
                re1 = 1;
            else if (tavola[i][j] == 11)
                re2 = 1;
    if (funzione) // se il secondo parametro è 1 allora si cerca se entrambi i re sono presenti sulla tavole, se invece è 0 si vuole sapere quale giocatore ha vinto.
        if (re1 && re2)
            risultato = 1;
        else
            risultato = 0;
    else if (re1)
        printf("\n\nIl giocatore 1 Ha VINTO!");
    else if (re2)
        printf("\n\nIl Giocatore 2 Ha VINTO!");

    return risultato;
}

char trova_pedina(unsigned tavola[][DIM], int numeri, int lettere)
{
    char pedina;
    switch (tavola[numeri][lettere])
    {
    case 7:
        pedina = 't';
        break;
    case 1:
        pedina = 'T';
        break;
    case 8:
        pedina = 'c';
        break;
    case 2:
        pedina = 'C';
        break;
    case 9:
        pedina = 'a';
        break;
    case 3:
        pedina = 'A';
        break;
    case 10: // re
        pedina = 'k';
        break;
    case 4:
        pedina = 'K';
        break;
    case 11: // regina
        pedina = 'q';
        break;
    case 5:
        pedina = 'Q';
        break;
    case 12:
        pedina = 'p';
        break;
    case 6:
        pedina = 'P';
        break;
    default:
        if ((lettere + numeri) % 2)
            pedina = ' ';
        else
            pedina = '\333';
        break;
    }

    return pedina;
}

void show_tavola(unsigned tavola[][DIM])
{ // stampa la tavola dopo ogni mossa
    char c;
    printf("\n\t     A   B   C   D   E   F   G   H\n"); // estetica in console
    for (int i = DIM-1; i >= 0; i--)
    {
        printf("\t    -------------------------------\n");
        printf("\t %d |", i + 1); // apro la riga
        for (int j = 0; j < DIM; j++) // determina il tipo di pedina
        {
            c = trova_pedina(tavola, i, j);
            printf(" %c ", c);
            printf("|"); // chiudo la casella e la riga a fine ciclo
        }
        printf(" %d \n", i + 1);
    }
    printf("\t    -------------------------------\n\t     A   B   C   D   E   F   G   H");
}

void next_move(unsigned tavola[][DIM], int *numero_giocatore)
{
    int numero[4], chek = 1;
    char lettera[2], lettere_tavola[9] = {"ABCDEFGH"}, pedina, conferma;

    int move_re(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina);

    void move_pedone(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X);

    int move_torre(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina);

    void move_cavallo(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X);

    int move_alfiere(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina);

    void move_regina(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X);

    do
    {
        do
        {
            chek = 0;
            printf("\n\nturno del (%d) giocatore\n\n Pattern [lettera posizione][numero posizione] [lettera nuova posizione][numero nuova posizione] \nMossa : ", *numero_giocatore + 1);
            scanf("%c%d %c%d", &lettera[0], &numero[0], &lettera[1], &numero[1]); // raccoglie la mossa
            getchar();                                                            // butta l'acapo
            // converto la coppia lettare-numero in numero-numero
            for (size_t i = 0; i < sizeof(lettera); i++) // trovo l'indice della lettera
                for (size_t j = 0; j < sizeof(lettere_tavola); j++)
                    if (lettera[i] == lettere_tavola[j])
                        numero[i + 2] = j;
            // controllo il fuori mappa
            if (((numero[1] - 1 < 0) || (numero[1] - 1 > 7)) || (numero[3] < 0 || numero[3] > 7))
            {
                printf("\ncoordinata di destinazione fuori mappa\n");
            }
            // controllo l'appartenenza
            if ((!*numero_giocatore && tavola[numero[0] - 1][numero[2]] > 6) || (*numero_giocatore && tavola[numero[0] - 1][numero[2]] < 7))
            {
                printf("\n\nErr: selezionata una pedina non posseduta");
                chek = 1;
            }
        } while ((numero[1] - 1 < 0) || (numero[1] - 1 > 7) || (numero[3] < 0) || (numero[3] > 7) || chek);

        pedina = trova_pedina(tavola, numero[0] - 1, numero[2]);

        printf("\nSpostare %c in  %c%d (y/n): ", pedina, lettera[1], numero[1]);
        scanf("%c", &conferma);
        getchar();

    } while (conferma != 'y');

    switch (pedina)
    {
    case 't':
    case 'T':
        printf("\n\nspostamento torre ");
        move_torre(tavola, numero[0] - 1, numero[2], numero_giocatore, numero[1] - 1, numero[3], 0);
        break;
    case 'c':
    case 'C':
        printf("\n\nspostamento cavallo ");
        move_cavallo(tavola, numero[0] - 1, numero[2], numero_giocatore, numero[1] - 1, numero[3]);
        break;
    case 'a':
    case 'A':
        printf("\n\nspostamento alfiere ");
        move_alfiere(tavola, numero[0] - 1, numero[2], numero_giocatore, numero[1] - 1, numero[3], 0);
        break;
    case 'q':
    case 'Q':
        printf("\n\nspostamento regina ");
        move_regina(tavola, numero[0] - 1, numero[2], numero_giocatore, numero[1] - 1, numero[3]);
        break;
    case 'k':
    case 'K':
        printf("\n\nspostamento re ");
        move_re(tavola, numero[0] - 1, numero[2], numero_giocatore, numero[1] - 1, numero[3], 0);
        break;
    case 'p':
    case 'P':
        printf("\n\nspostamento pedone ");
        move_pedone(tavola, numero[0] - 1, numero[2], numero_giocatore, numero[1] - 1, numero[3]);
        break;
    default:
        printf("\nError: non hai selezionato una pedina!");
        break;
    }
}

void move_pedone(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X)
{
    /**
     * REGOLE DI MOVIMENTO
     * può andare solo in avanti
     * alla prima mossa può spostarsi di 2 a tutte le altre può spostarsi di 1
     * può mangiare solo in diagonale di 1
     */
    unsigned primo_spostamento_Y, spostamento_Y_doppio_valido, spostamento_Y_singolo_valido, spostamento_X_valido, spostamento_X_nullo, cella_frontale_libera, due_cella_frontali_libere, nemico_nella_cella_DX, nemico_nella_cella_SX, fine_tavola, exit;
    char pedina;

    if (*utente)
    { // pedine a disposizione dalla 7 alla 12
        primo_spostamento_Y = (posY == 6);
        spostamento_Y_doppio_valido = (pos1Y - posY < 0) && (pos1Y - posY > -3);
        spostamento_Y_singolo_valido = (pos1Y - posY < 0) && (pos1Y - posY > -2); // spostamento in avanti standard
        spostamento_X_valido = (pos1X - posX < 2) && (pos1X - posX > -2);         // spostamento laterale da -1 e +1
        spostamento_X_nullo = (pos1X - posX == 0);
        cella_frontale_libera = !tavola[posY - 1][posX];
        due_cella_frontali_libere = (!tavola[posY - 2][pos1X]) && cella_frontale_libera; // se libera restituisce 1 se occupata restituisce 0| sistemare il metodo di controllo
        nemico_nella_cella_DX = (tavola[posY - 1][posX + 1] < 7) && (tavola[posY - 1][posX + 1] > 0);
        nemico_nella_cella_SX = (tavola[posY - 1][posX - 1] < 7) && (tavola[posY - 1][posX - 1] > 0);
        fine_tavola = (pos1Y == 0) && (pos1Y == (posY - 1));
    }
    else
    { // pedine a disposizione dalla 1 alla 6 alla
        // determino se la posizione davanti è libera
        primo_spostamento_Y = (posY == 1);
        spostamento_Y_doppio_valido = (pos1Y - posY > 0) && (pos1Y - posY < 3);
        spostamento_Y_singolo_valido = (pos1Y - posY > 0) && (pos1Y - posY < 2); // spostamento in avanti standard
        spostamento_X_valido = (pos1X - posX < 2) && (pos1X - posX > -2);        // spostamento laterale da -1 e +1
        spostamento_X_nullo = (pos1X - posX == 0);
        cella_frontale_libera = !tavola[posY + 1][posX];
        due_cella_frontali_libere = (!tavola[posY + 2][pos1X]) && cella_frontale_libera; // se libera restituisce 1 se occupata restituisce 0| sistemare il metodo di controllo
        nemico_nella_cella_DX = (tavola[posY + 1][posX + 1] > 6);
        nemico_nella_cella_SX = (tavola[posY + 1][posX - 1] > 6);
        fine_tavola = (pos1Y == 7) && (pos1Y == (posY + 1));
    }
    if ((primo_spostamento_Y && spostamento_Y_doppio_valido && due_cella_frontali_libere && spostamento_X_nullo) /*avanzamento doppio*/ ||
        (spostamento_Y_singolo_valido && cella_frontale_libera && spostamento_X_nullo) /*avanzamento dingolo*/ ||
        (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_DX) /*mangia DX*/ ||
        (spostamento_Y_singolo_valido && !spostamento_X_nullo && spostamento_X_valido && nemico_nella_cella_SX) /*mangia SX*/)
    {
        tavola[pos1Y][pos1X] = tavola[posY][posX];
        tavola[posY][posX] = 0;
        *utente = !*utente;
    }
    else
    {
        printf("Error: Mossa non valida! ripetere il turno.\n");
    }

    if (fine_tavola) // se il pedone selezionato riesce ad arrivare alla fine allora gli si fascegliere una figura con cui sostituirlo
    {
        do
        {
            exit = 0;
            printf("\nCon cosa vuoi sostituire il tuo pedone: ");
            scanf("%c", &pedina);
            getchar();

            switch (pedina)
            {
            case 'T':
            case 't':
                printf("\n\ntorre ");
                tavola[pos1Y][pos1X] -= 5;
                break;
            case 'C':
            case 'c':
                printf("\n\nsostituzione in alfiere ");
                tavola[pos1Y][pos1X] -= 4;
                break;
            case 'A':
            case 'a':
                printf("\n\nsostituzione in alfiere ");
                tavola[pos1Y][pos1X] -= 3;
                break;
            case 'Q':
            case 'q':
                printf("\n\nsostituzione in regina ");
                tavola[pos1Y][pos1X] -= 1;
                break;
            default:
                printf("Error: non hai selezionato una pedina!");
                exit = 1;
                break;
            }
        } while (exit != 0);
    }
}

int move_re(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina)
{
    /**
     * REGOLE DI MOVIMENTO
     *
     * spostamento in ogni direzione di 1
     */
    int exit = 0;
    unsigned libera_amica;
    unsigned movimento_nullo = ((pos1X - posX) == 0) && ((pos1Y - posY) == 0);
    unsigned spostamento_x = (pos1X - posX > -2) && (pos1X - posX < 2);
    unsigned spostamento_y = (pos1Y - posY > -2) && (pos1Y - posY < 2);

    if (*utente) // 7 - 12
        libera_amica = ((tavola[pos1Y][pos1X] < 7));
    else // 1-6
        libera_amica = ((tavola[pos1Y][pos1X] > 6) || (tavola[pos1Y][pos1X] == 0));

    if (spostamento_x && spostamento_y && !movimento_nullo && libera_amica)
    {
        tavola[pos1Y][pos1X] = tavola[posY][posX];
        tavola[posY][posX] = 0;
        *utente = !*utente;
    }
    else
    {
        regina ? printf("\nricerca del movimento corretto...") : printf("Error: Mossa non valida! ripetere il turno.\n");
        exit = 1;
    }
    return exit;
}

int move_torre(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina)
{
    /**
     * REGOLE DI MOVIMENTO
     *
     * spostamento su un solo asse illimitatamente
     */
    int exit = 0;
    unsigned movimento_nullo = ((pos1X - posX) == 0) && ((pos1Y - posY) == 0);
    unsigned movimento_1 = ((pos1X - posX) == 0) && ((pos1Y - posY) != 0);
    unsigned movimento_2 = ((pos1X - posX) != 0) && ((pos1Y - posY) == 0);
    unsigned libera_amica;
    unsigned libero_percorso = 0;

    if (movimento_1 == 1 && pos1Y - posY < 0)
    {
        for (size_t i = posY - 1; i < pos1Y; i--)
        {
            libero_percorso += tavola[i][posX];
        }
    }
    else if (movimento_1 == 1 && pos1Y - posY > 0)
    {
        for (size_t i = posY + 1; i < pos1Y; i++)
        {
            libero_percorso += tavola[i][posX];
        }
    }
    else if (movimento_2 == 1 && pos1Y - posY > 0)
    {
        for (size_t i = posY + 1; i < pos1Y; i++)
        {
            libero_percorso += tavola[posY][i];
        }
    }
    else if (movimento_2 == 1 && pos1Y - posY < 0)
    {
        for (size_t i = posY - 1; i < pos1Y; i--)
        {
            libero_percorso += tavola[posY][i];
        }
    }

    if (*utente)
        libera_amica = tavola[pos1Y][pos1X] < 7;
    else
        libera_amica = ((tavola[pos1Y][pos1X] > 6) || (tavola[pos1Y][pos1X] == 0));

    if ((!movimento_nullo && movimento_1 && libera_amica && !libero_percorso) || (!movimento_nullo && movimento_2 && libera_amica && !libero_percorso))
    {
        tavola[pos1Y][pos1X] = tavola[posY][posX];
        tavola[posY][posX] = 0;
        *utente = !*utente;
    }
    else
    {
        regina ? printf("\nricerca del movimento corretto...") : printf("Error: Mossa non valida! ripetere il turno.\n");
        exit = 1;
    }
    return exit;
}

void move_cavallo(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X)
{
    unsigned movimento_nullo = ((pos1X - posX) == 0) && ((pos1Y - posY) == 0);
    unsigned movimento_V = ((pos1Y - posY) == 2 || (pos1Y - posY) == -2) && ((pos1X - posX) == 1 || (pos1X - posX) == -1);
    unsigned movimento_O = ((pos1Y - posY) == 1 || (pos1Y - posY) == -1) && ((pos1X - posX) == 2 || (pos1X - posX) == -2);
    unsigned libera_amica;

    if (*utente)
        libera_amica = tavola[pos1Y][pos1X] < 7;
    else
        libera_amica = ((tavola[pos1Y][pos1X] > 6) || (tavola[pos1Y][pos1X] == 0));

    if ((!movimento_nullo && movimento_O && libera_amica) || (!movimento_nullo && movimento_V && libera_amica))
    {
        tavola[pos1Y][pos1X] = tavola[posY][posX];
        tavola[posY][posX] = 0;
        *utente = !*utente;
    }
    else
    {
        printf("Error: Mossa non valida! ripetere il turno.\n");
    }
}

int move_alfiere(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X, int regina)
{
    int exit = 0;
    unsigned movimento_nullo = ((pos1X - posX) == 0) && ((pos1Y - posY) == 0);
    unsigned movimento_valido = (((pos1X - posX) == (pos1Y - posY)) || ((pos1X - posX) == (-1 * (pos1Y - posY)))); // sicuramente diagonale
    unsigned libera_amica;
    unsigned libero_percorso = 0;

    if (pos1Y - posY > 0 && pos1X - posX > 0)
    {
        for (size_t i = posY + 1, j = posX + 1; i < pos1Y; i++, j++)
        {
            libero_percorso += tavola[i][j];
        }
    }
    else if (pos1Y - posY > 0 && pos1X - posX < 0)
    {
        for (size_t i = posY + 1, j = posX - 1; i < pos1Y; i++, j--)
        {
            libero_percorso += tavola[i][j];
        }
    }
    else if (pos1Y - posY < 0 && pos1X - posX > 0)
    {
        for (size_t i = posY - 1, j = posX + 1; j < pos1X; i--, j++)
        {
            libero_percorso += tavola[i][j];
        }
    }
    if (pos1Y - posY < 0 && pos1X - posX < 0)
    {
        for (size_t i = posY - 1, j = posX - 1; j < pos1X; i--, j--)
        {
            libero_percorso += tavola[i][j];
        }
    }

    if (*utente)
        libera_amica = tavola[pos1Y][pos1X] < 7;
    else
        libera_amica = ((tavola[pos1Y][pos1X] > 6) || (tavola[pos1Y][pos1X] == 0));

    if (!movimento_nullo && movimento_valido && libera_amica && !libero_percorso)
    {
        tavola[pos1Y][pos1X] = tavola[posY][posX];
        tavola[posY][posX] = 0;
        *utente = !*utente;
    }
    else
    {
        regina ? printf("\nricerca del movimento corretto...") : printf("Error: Mossa non valida! ripetere il turno.\n");
        exit = 1;
    }
    return exit;
}

void move_regina(unsigned tavola[][DIM], int posY, int posX, int *utente, int pos1Y, int pos1X)
{
    /*
     * REGOLE DI MOVIMENTO
     *
     * spostamento del re, della torre e dell'alfiere
     */

    if (!move_re(tavola, posY, posX, utente, pos1Y, pos1X, 1) || !move_torre(tavola, posY, posX, utente, pos1Y, pos1X, 1) || !move_alfiere(tavola, posY, posX, utente, pos1Y, pos1X, 1))
        printf("\n");
    else
        printf("\nError: Mossa non valida! ripetere il turno.\n");
}