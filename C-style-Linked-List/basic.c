#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct node {
	Type data;
	struct node *next;
} Node;

typedef struct list {
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
	if (!temp) {
		(*L)->head = newNode;
		return;
	}
	while (temp->next) 
		temp = temp->next;
	temp->next = newNode;
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
		push_back (&L, i);
	print (L);
	return 0;
}
