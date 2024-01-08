// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
	int value;
	struct node *next;
};

// print the linked list value
void printLista(struct node *p) {
	while (p != NULL) {
    printf("%d\n", p->value);
    p = p->next;
}
}

int inserisciInTesta(struct node **head){	//work

	struct node *newNode;
	int a;

	printf("specifica il valore da inserire in lista (int): ");
	scanf("%d", &a);
	getchar();

	newNode = malloc(sizeof(struct node));

	newNode->value = a;
	newNode->next = *head;
	*head = newNode;

	return 0;
}

int rimuoviInTesta(struct node **head){ //work

	struct node *temp;

	temp = *head;
	*head = (*head)->next;
	free(temp);

	return 0;
}

int inserisciInCoda(struct node **head){	//work
	struct node *temp = *head;
	while(temp->next != NULL)
		temp = temp->next;

	struct node *newNode;
	int a;

	printf("specifica il valore da inserire in lista (int): ");
	scanf("%d", &a);
	getchar();

	newNode = malloc(sizeof(struct node));

	temp->next = newNode;
	newNode->value = a;
	newNode->next = NULL;
}


int rimuoviInCoda(struct node **head){ //work

	struct node *temp = *head;
	struct node *temp2;
	while(temp->next != NULL){
		temp2 = temp;
		temp = temp->next;
	}

	temp2->next = NULL;
	free(temp);
	return 0;
}

int main() {
	// Initialize nodes pointer
	struct node *head;
	struct node *one = NULL;
	struct node *two = NULL;

	// Allocate memory
	one = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));

	// Assign value values
	one->value = 1;
	two->value = 2;

	// Connect nodes
	one->next = two;
	two->next = NULL;

	// printing node-value
	head = one;

		printLista(head);
		rimuoviInCoda(&head);
		printLista(head);

	return 0;
}