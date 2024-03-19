/******************************************************************************

La Biblioteca

*******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;
//definisco la struttura del libro
struct libro
{
  char codice[6];
  char titolo[11];
  char autore[11];
  char editore[11];
  int anno_edizione;
  int copie;
};
//compila scheda
void inserisci_libro(libro archivio[], int* indice)
{
    cout << "\ninserimento di un libro\n\n";
    libro a;
    
    cout << "codice: ";
    cin >> a.codice;
    cout << "titolo: ";
    cin >> a.titolo;
    cout << "autore: ";
    cin >> a.autore;
    cout << "copie: ";
    cin >> a.copie;
    
    archivio[*indice] = a;
    (*indice)++;
    
    cout << "\n\nlibro registrato\n\n";
}
//mostra archivio
void mostra_archivio(libro archivio[], int indice)
{
    cout << "I libri registrati sono:";
    
    for(int i = 0; i < indice; i++)//prende ogni libro presente nell'archivio
    {
        cout<<endl<<" - "<<archivio[i].titolo<<endl;
    }
}
//codice e titolo di libri con copie < 3
void mostra_per_copie(libro archivio[], int indice)
{
    cout << "I libri con meno di 3 copie:";
    
    for(int i = 0; i < indice; i++)
    {
        if(archivio[i].copie <3)
        {
            cout<<endl<<" - Titolo: "<<archivio[i].titolo<<", codice: "<<archivio[i].codice<<endl;
        }
    }
}

void ordina_per_autore(libro archivio[], int indice)
{
    int falg = 1;
    
    while(falg){
        
        falg = 0;
        libro aiuto; //variabile d'appoggio
        
        for(int i = 0; i < indice; i++)
        {
            for(int j = 0; j < indice; j++)
            {
                if(archivio[i].autore < archivio[j].autore)
                { //scambio delle variabili
                    aiuto = archivio[i];
                    archivio[i] = archivio[j];
                    archivio[j] = aiuto;
                    
                    falg = 1; //ripetere il ciclo
                }    
            }
        }
    }
}

int media_per_autore(libro archivio[], int indice)
{
    char autore[11];
    int titoli = 0;
    int somma_copie = 0;
    int media;
    
    cout << "seleziona l'autore da ricercare: ";
    cin >> autore;
    
    for(int i = 0; i < indice; i++)
    {
        if(archivio[i].autore == autore)
        {
            titoli++;
            somma_copie+=archivio[i].copie;
        }    
    }
    
    if(titoli != 0)
    {
        media = somma_copie/titoli;
    }else{
        media = 0;
    }
    cout << "\nmedia delle copie pubblicate dell'autore "<<autore<<": "<<media;
    return media;
}

int main()
{
    int libri_registrati = 0;
    libro archivio[10];
    int indice_menu;
    int help = 1;
    
    //menu
    while(help){
        cout << "\n1)inserisci il libro \n2)stampa archivio \n3)filtro per copie \n4)ordina per autore \n5)media copie per autore \nDiversamente si chiuderà\n\n Scelta: ";
        cin >> indice_menu;
        
        switch(indice_menu)
        {
            case 1:
                inserisci_libro(archivio, &libri_registrati);
                break;
            case 2:
                mostra_archivio(archivio, libri_registrati);
                break;
            case 3:
                mostra_per_copie(archivio, libri_registrati);
                break;
            case 4:
                ordina_per_autore(archivio, libri_registrati);
            case 5:
                cout << media_per_autore(archivio, libri_registrati);
                break;
            default:
                cout << "chiusura programma!";
                help = 0;
                break;
        }        
    }
    return 0;
}