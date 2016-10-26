#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct node {		
	Type data;
	struct node *next;
} Node;

typedef struct list {		//List definition contains head of the list
	Node *head;
} List;

Node *makeNode (Type n) {
	Node *newNode = malloc (sizeof (Node));
	newNode->data = n;
	newNode->next = NULL;
	return newNode;
}

void push_front (List **L, Type n) {
	Node *newNode = makeNode (n);
	newNode->next = (*L)->head;
	(*L)->head = newNode;
}

void push_back (List **L, Type n) {
	Node *newNode = makeNode (n), *temp = (*L)->head;
	if (!temp) {		//Checking 'empty list' condition
		(*L)->head = newNode;
		return;
	}
	while (temp->next) 
		temp = temp->next;
	temp->next = newNode;
}

void push_after (Node *t, int n) {
	Node *newNode = makeNode (n);
	newNode->next = t->next;
	t->next = newNode;
}

void print (List *L) {
	Node *temp = malloc (sizeof (Node));
	temp = L->head;
	while (temp) {
		printf ("%d\t", temp->data);
		temp = temp->next;
	}
	printf ("\n");
}

int main () {
	List *L = malloc (sizeof (List));
	for (int i = 0; i < 4; ++i)
		push_front (&L, i);
	Node *temp = L->head;
	for (int i = 0; i < 3; ++i) 
		temp = temp->next;
	push_after (temp, 5);
	print (L);
	return 0;
}
