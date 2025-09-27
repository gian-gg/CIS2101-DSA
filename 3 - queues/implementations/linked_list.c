#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *link;
} *nodetype;

typedef struct {
    nodetype front;
    nodetype rear;
} QUEUE;


void display(QUEUE*);

void init(QUEUE*);

void enqueue(QUEUE*,char);
void dequeue(QUEUE*);

char front(QUEUE);

bool isFull(QUEUE);
bool isEmpty(QUEUE);


void display(QUEUE* Q) {
    QUEUE temp;
    init(&temp);

    while (!isEmpty(*Q)) {
        int frontElem = front(*Q);
        printf("%d ", frontElem);
        enqueue(&temp, frontElem);
        dequeue(Q);
    }

    while (!isEmpty(temp)) {
        enqueue(Q, front(temp));
        dequeue(&temp);
    }

    printf("\n");
}

void init(QUEUE* Q) {
    Q->front=NULL;
    Q->rear=NULL;
} // set both front and rear pointers to be NULL, empty

void enqueue(QUEUE* Q,char data) {
    nodetype newNode = malloc(sizeof(struct node));

    if (newNode != NULL) { // check if malloc was successful
        newNode->data = data;
        newNode->link = NULL;

        if (Q->front == NULL) { // queue is empty, point front to newNode
            Q->front = newNode;
        } else { // queue is not empty, update rear.link to link newNode
            Q->rear->link = newNode;
        }

        Q->rear = newNode; // point rear to newNode
    }
}

void dequeue(QUEUE* Q) {
    nodetype temp = Q->front;
    Q->front = Q->front->link;
    free(temp);

    if (Q->front == NULL) Q->rear = NULL; // queue is empty, also update rear
}

char front(QUEUE Q) {
    return Q.front->data;
}

bool isFull(QUEUE Q) {
    return false;
}

bool isEmpty(QUEUE Q) {
    return (Q.front == NULL) && (Q.rear == NULL);
}
