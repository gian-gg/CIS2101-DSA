#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} *nodetype;

typedef struct {
    nodetype head;
    nodetype tail;
} LIST;

void init(LIST*);
void display(LIST);

void insertFirst(LIST*, int);
void insertLast(LIST*, int);
void insertSorted(LIST*, int);
void insertAtPos(LIST*, int, int);

void deleteElem(LIST*,int);
void deleteAll(LIST*);

bool isFull(LIST);
bool isEmpty(LIST);

int main() {
    LIST L;
    init(&L);

    insertLast(&L, 10);
    insertLast(&L, 20);
    insertLast(&L, 30);

    display(L);

    insertFirst(&L, 40);

    display(L);


    return 0;
}

void init(LIST* L) {
    L->head = NULL;
    L->tail = NULL;
}

void display(LIST L) {
    for(nodetype trav = L.head; trav != NULL; trav = trav->next) {
        printf("%d ", trav->data);
    }
    printf("\n");
}

void insertFirst(LIST* L, int elem) {
    nodetype newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = elem;
        newNode->next = L->head;
        newNode->prev = NULL;


        if (L->head == NULL) {
            L->tail = newNode;
        } else {
            L->head->prev = newNode;
        }

        L->head = newNode;
    }
}

void insertLast(LIST* L, int elem) {
    nodetype newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = elem;
        newNode->next = NULL;
        newNode->prev = L->tail;


        if (L->tail == NULL) {
            L->head = newNode;
        } else {
            L->tail->next = newNode;
        }

        L->tail = newNode;
    }
}
