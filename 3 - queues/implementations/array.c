// Circular Array Implementation
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int front;
    int rear;
} QUEUE;

void init(QUEUE*);
void display(QUEUE*);
void visualize(QUEUE);

void enqueue(QUEUE*,char);
void dequeue(QUEUE*);

char front(QUEUE);

bool isFull(QUEUE);
bool isEmpty(QUEUE);

void init(QUEUE* Q) {
    Q->front = 0;
    Q->rear = MAX - 1;
} // initilize queue to be empty

void display(QUEUE* Q) {
    QUEUE temp;
    init(&temp);

    while(!isEmpty(*Q)) {
        int frontElem = front(*Q);

        printf("%d ", frontElem);

        enqueue(&temp, frontElem);
        dequeue(Q);
    }

    while(!isEmpty(temp)) {
        enqueue(Q, front(temp));
        dequeue(&temp);
    }

    printf("\n");
}

void visualize(QUEUE Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("+-------+------+\n");
    printf("| FRONT | REAR |\n");
    printf("+-------+------+\n");
    printf("|   %-3d |  %-3d |\n", Q.front, Q.rear);
    printf("+-------+------+\n");

    printf("+------+------+\n");
    printf("| INDX | DATA |\n");
    printf("+------+------+\n");


    for (int i = Q.front; i != Q.rear; i = (i + 1) % MAX) {
        printf("|  %3d |  %c   |\n", i, Q.data[i]);
        printf("+------+------+\n");

    }
}


void enqueue(QUEUE* Q,char data) {
    if (isFull(*Q) != true) {
        Q->rear = (Q->rear + 1) % MAX; // circular increment
        Q->data[Q->rear] = data;
    } else {
        printf("QUEUE IS FULL!\n");
    }
}

void dequeue(QUEUE* Q) {
    Q->front = (Q->front + 1) % MAX; // circular increment
}

char front(QUEUE Q) {
    return Q.data[Q.front];
}

bool isFull(QUEUE Q) {
    return ((Q.front == (Q.rear + 2) % MAX)) ? true : false;
} // queue is full if front is ahead of rear by 2

bool isEmpty(QUEUE Q) {
    return ((Q.front == (Q.rear + 1) % MAX)) ? true : false;
} // queue is empty if front is ahead of rear by 1
