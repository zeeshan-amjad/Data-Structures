#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct node {		
	Type data;
	struct node *next;
} Node;

typedef struct list {		//List definition has a pointer to the head of a list.
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
	if (!temp) {		//Checking 'empty list' condition.
		(*L)->head = newNode;
		return;
	}
	while (temp->next) 
		temp = temp->next;
	temp->next = newNode;
}

void push_after (Node *t, Type n) {	//t is a pointer to the target node after which insertion is to be done.
	Node *newNode = makeNode (n);
	if (!t) {		//checking 'null target' condition.
		t = newNode;
		return;
	}	
	newNode->next = t->next;
	t->next = newNode;
}

void delete (List **L, Type n) {	//deletes the first occurrence of the node having data n.
	Node *temp = (*L)->head;
	if (temp->data == n) {		//when the first node needs to be deleted.
		(*L)->head = temp->next;
		free (temp);
		return;
	}
	while (temp->next && temp->next->data != n)	//iterating to the node before target node.
		temp = temp->next;
	if (!temp->next)		//when node not found.
		return;
	Node *f = temp->next;
	temp->next = temp->next->next;
	free (f);
}

void delete_pos (List **L, int n) {	//deletes the node at position n (zero - indexed).
	Node *temp = (*L)->head;
        if (!n) {          		//when the first node needs to be deleted.
                (*L)->head = temp->next;
                free (temp);
                return;
        }
	int i = 1;
	while (temp->next && i < n) {     //iterating to the node before target node.
                temp = temp->next;
		i++;
	}
	if (!temp->next)                //when node not found.
                return;
        Node *f = temp->next;
        temp->next = temp->next->next;
        free (f);
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
	delete_pos (&L, 7);
	print (L);
	return 0;
}
