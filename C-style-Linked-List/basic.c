#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef int Type;

typedef struct node {		
	Type data;
	struct node *next;
} Node;

typedef struct list {		//List definition has a pointer to the head of a list.
	Node *head;
	int size;
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

int size (List *L) {
	int s = 0;
	Node *temp = L->head;
	while (temp) {
		s++;
		temp = temp->next;
	}
	return s;
}

bool search (List *L, Type n) {		//returns true if element is found.
	Node *temp = L->head;
	while (temp) {
		if (temp->data == n)
			return true;
		temp = temp->next;
	}
	return false;
}

void swap (List **L, Type a, Type b) {		//swap two nodes by links.
	if (a == b)			//when nodes are same.
		return;
	
	Node *prevA = NULL, *curA = (*L)->head;
	while (curA && curA->data != a) {		//setting first node.
		prevA = curA;
		curA = curA->next;
	}

	Node *prevB = NULL, *curB = (*L)->head;
	while (curB && curB->data != b) {		//setting second node.
		prevB = curB;
		curB = curB->next;
	}

	if (!curA || !curB)		//when either node is not found.
		return;

	if (prevA)			
		prevA->next = curB;
	else				//when a node is the head node.
		(*L)->head = curB;

	if (prevB)
		prevB->next = curA;
	else
		(*L)->head = curA;

	Node *temp = curB->next;	
	curB->next = curA->next;
	curA->next = temp;
}

Type getNode (List *L, int n) {		//1-indexed
	if (n > size (L))
		return INT_MIN;
	Node *temp = L->head;
	for (int i = 1; temp && i < n; ++i) 
		temp = temp->next;
	return temp->data;
}

Type getNodeFromEnd (List *L, int n) {	//1-indexed
	Node *slow = L->head, *fast = L->head;
	if (n > size (L))
		return INT_MIN;
	for (int i = 1; i <= n; ++i)
		fast = fast->next;
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}

Type getMid (List *L) {
	if (!L->head)
		return INT_MIN;
	Node *slow = L->head, *fast = L->head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
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
	for (int i = 0; i < 5; ++i)
		push_front (&L, i);
	Node *temp = L->head;
	for (int i = 0; i < 3; ++i) 
		temp = temp->next;
	push_after (temp, 5);
	print (L);
	swap (&L, 3, 5);
	print (L);
	printf ("%d\n", getNode (L, 1));
	return 0;
}
