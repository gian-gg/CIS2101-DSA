#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

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

    insertFirst(&L, 10);
    insertFirst(&L, 20);
    insertFirst(&L, 30);
    insertFirst(&L, 40);

    display(L);

    insertLast(&L, 50);
    insertLast(&L, 100);

    display(L);

    insertSorted(&L, 90);

    display(L);

    deleteElem(&L, 50);

    display(L);

    insertAtPos(&L, 500, 0);

    display(L);


    deleteAll(&L);

    display(L);

    return 0;
}

void init(LIST* L) {
    *L = NULL;
}


void insertFirst(LIST* L, int elem) {
    LIST newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = elem;
        newNode->link = *L;
        *L = newNode;
    }
}

void display(LIST L) {
    if (L != NULL)  {
        for(LIST trav = L; trav != NULL; trav = trav->link) {
            printf("%d ", trav->data);
        }
        printf("\n");
    } else {
        printf("\nLIST IS EMPTY!!\n");
    }

}

void insertLast(LIST* L, int elem) {
    LIST newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        LIST *trav;
        for(trav = L; *trav != NULL; trav=&((*trav)->link)) {}


        newNode->data = elem;
        newNode->link = NULL;
        *trav = newNode;
    }
}

void insertSorted(LIST* L, int elem) {
    LIST newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        LIST *trav;
        for(trav = L; *trav != NULL && elem > (*trav)->data; trav=&((*trav)->link)) {}


        newNode->data = elem;
        newNode->link = *trav;
        *trav = newNode;
    }
}

void insertAtPos(LIST* L, int elem, int pos) {
    LIST newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        LIST *trav;
        int idx;
        for(idx = 0, trav = L; *trav != NULL && idx < pos; trav=&((*trav)->link), idx++) {}


        newNode->data = elem;
        newNode->link = *trav;
        *trav = newNode;
    }
}

void deleteElem(LIST* L, int elem) {
    LIST *trav;
    for(trav = L; *trav != NULL && elem != (*trav)->data; trav=&((*trav)->link)) {}

    if (*trav != NULL) {
        LIST temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void deleteAll(LIST* L) {
    LIST *trav = L;
    while(*trav != NULL) {
        LIST temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

bool isFull(LIST L) {
    return false;
}

bool isEmpty(LIST L) {
    return (L == NULL);
}
