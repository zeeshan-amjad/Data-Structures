#include <stdio.h>
#include <stdlib.h>

typedef int QueueEntry;

typedef struct node {
        QueueEntry data;
        struct node *next;
} Node;

typedef struct queue {
        Node *front;
        Node *rear;
        int size;
} Queue;

void initialize (Queue *q) {
        q->front = NULL;
        q->rear = NULL;
        q->size = 0;
}

void makeNode (Node *n, QueueEntry e) {
        n->data = e;
        n->next = NULL;
}

void push (Queue *q, QueueEntry e) {
        Node *n = malloc (sizeof (Node));
        makeNode (n, e);
        if (q->rear)
                q->rear->next = n;
        q->rear = n;
        if (!(q->front))
                q->front = n;
        q->size += 1;
}

void pop (Queue *q) {
        if (q->front == NULL) {
                printf ("!!!UNDERFLOW!!!\n");
                return;
}
        Node *temp = malloc (sizeof (Node));
        temp = q->front;
        q->front = q->front->next;
        free (temp);
        q->size -= 1;
}

void display (Queue *q) {
        Node *temp = malloc (sizeof (Node));
        temp = q->front;
        while (temp) {
                printf ("%d ", temp->data);
                temp = temp->next;
        }
        printf ("\n");
}

int main () {
        Queue *q1 = malloc (sizeof (Queue)), *q2 = malloc (sizeof (Queue));
        initialize (q1), initialize (q2);

        printf ("\t#### Stack Using Queue ####\n\n");
        int i = 0;
        while (1) {
                printf ("1. Push\n2. Pop\n3. Count\n4. Display\n0. Exit\n\n");
                int ch;
                scanf ("%d", &ch);
                if (!ch)
                        break;
                switch (ch) {
                        case 1: printf ("Value = ");
                                int n;
                                scanf ("%d", &n);
                                if (!i)
                                        push (q1, n);
                                else
                                        push (q2, n);
                                break;
                        case 2: if (!i) {
                                        while (q1->size > 1) {
                                               push (q2, q1->front->data);
                                                pop (q1);
                                        }
                                        pop (q1);
                                }
                                else {
                                        while (q2->size > 1) {
                                                push (q1, q2->front->data);
                                                pop (q2);
                                        }
                                        pop (q2);
                                }
                                if (!i) initialize (q1);
                                else initialize (q2);
                                i = 1 - i;
                                break;
                        case 3: if (!i)
                                        printf ("Nodes = %d\n", q1->size);
                                else
                                        printf ("Nodes = %d\n", q2->size);
                                break;
                        case 4: printf ("Nodes = ");
                                if (!i)
                                        display (q1);
                                else
                                        display (q2);
                                break;
                }
                printf ("\n");
        }

        return 0;
}
