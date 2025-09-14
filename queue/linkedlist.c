#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *nodetype;

typedef struct {
    nodetype front;
    nodetype rear;
} queue;

void init(queue*);
void display(queue);

void enqueue(queue*,char);
void dequeue(queue*);

char front(queue);
char rear(queue);

int main() {
    queue Q;
    init(&Q);

    enqueue(&Q, 'G');
    enqueue(&Q, 'I');
    enqueue(&Q, 'A');
    enqueue(&Q, 'N');

    display(Q);

    dequeue(&Q);

    display(Q);


    printf("FRONT: %c\n", front(Q));
    printf("REAR: %c\n", rear(Q));

    return 0;
}

void init(queue*Q) {
    Q->front=NULL;
    Q->rear=NULL;
}

void display(queue Q) {
    for(nodetype trav = Q.front; trav!=NULL; trav=trav->link) {
        printf("%c ", trav->data);
    }
    printf("\n");
}

void enqueue(queue* Q,char data) {
    nodetype newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = NULL;

        if (Q->front == NULL) {
            Q->front = newNode;
        } else {
            Q->rear->link = newNode;
        }

        Q->rear = newNode;
    }
}

void dequeue(queue* Q) {
    nodetype temp = Q->front;
    Q->front = Q->front->link;
    free(temp);

    if (Q->front == NULL) Q->rear = NULL;
}

char front(queue Q) {
    return Q.front->data;
}
char rear(queue Q) {
    return Q.rear->data;

}
