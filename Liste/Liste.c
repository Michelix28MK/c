#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void inserisciInTesta(struct node** head, int new_data)
{
    struct node* nuovo = (struct node*) malloc(sizeof(struct node));

    if (nuovo == NULL)
    {
        printf("Errore nella memoria!");
        exit(0);
    }
    
    nuovo->data = new_data; //assegno il valore
    nuovo->next = (*head); //assegno il nodo successivo
    //cambio indirizzo di testa
    (*head) = nuovo;
}

void cancellaInLista(struct node** head, int key)
{
    struct node* tmp = *head;
    struct node* prev = NULL;

    //il nodo da eliminare è la testa
    if (tmp->data = key && tmp != NULL)
    {
        *head = tmp->next;
        free(head);
        return;
    }
    //ricerca nodo
    while (tmp != NULL && tmp->data != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //nessun nodo ha il dato
    if (tmp == NULL)
    {
        return;
    }
    //Modifico il next del nodo
    prev->next = tmp->next;
    free(tmp);
}

int trovaNodo(struct node** head, int ricercato)
{
    struct node* corrente = *head;
    int i = 0;

    while (corrente != NULL)
    {
        i++;
        if (corrente->data == ricercato)
        {
            printf("Dato trovato! -> %d", i);
            return 1;
        }
        corrente = corrente->next;
    }
   return 0; 
}

void mostraLista(struct node* p)
{
    printf("\n");

    while (p != NULL)
    {
        printf("|%d| ->", p->data);
        p = p->next;
    }

    printf("NULL\n");
}

int main(void)
{
    struct node* head; //testa della lista
    struct node* nodo1;

    nodo1 = (struct node*) malloc(sizeof(struct node));

    nodo1->data = 1;
    nodo1->next = NULL;
    
    head = nodo1;

    mostraLista(head);

    inserisciInTesta(&head, 15);

    mostraLista(head);

    inserisciInTesta(&head, 81);

    mostraLista(head);

    inserisciInTesta(&head, 13);

    mostraLista(head);

    trovaNodo(&head, 15);

    return 0;
}