#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

void init(LIST*);
void display(char[], LIST);
void insertEnd(LIST*, int);
void insertStart(LIST*, int);
void insertPos(LIST*, int, int);
void insertSort(LIST*, int);

int main () {
    LIST HEAD;
    init(&HEAD);

    insertEnd(&HEAD, 10);
    insertEnd(&HEAD, 20);
    insertEnd(&HEAD, 30);
    insertEnd(&HEAD, 40);
    insertEnd(&HEAD, 50);

    display("Before: ", HEAD);

    insertPos(&HEAD, 35, 1);

    display("After: ", HEAD);

    return 0;
}

void init(LIST *HEAD) {
    *HEAD = NULL;
}

void display(char string[], LIST HEAD) {
    printf("%s", string);
    for(LIST curr = HEAD; curr!= NULL; curr=curr->link) printf("%d ", curr->data);
    printf("\n");
}

void insertEnd(LIST *HEAD, int data) {
    LIST *curr;
    for(curr = HEAD; (*curr)!=NULL; curr = &(*curr)->link);

    LIST newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = NULL;
        *curr = newNode;
    } else {
        printf("Malloc Failed!");
    }
}

void insertStart(LIST *HEAD, int data) {
    LIST newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = *HEAD;
        *HEAD = newNode;
    } else {
        printf("Malloc Failed!");
    }
}

void insertPos(LIST *HEAD, int data, int index) {
    LIST *curr;
    int i = 0;
    for(curr = HEAD; (*curr)!=NULL && i < index; curr = &(*curr)->link, i++);

    LIST newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = *curr;
        *curr = newNode;
    } else {
        printf("Malloc Failed!");
    }
}

void insertSort(LIST *HEAD, int data) {
    LIST *curr;
    for(curr = HEAD; (*curr)!=NULL && data > (*curr)->data; curr = &(*curr)->link);

    LIST newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = *curr;
        *curr = newNode;
    } else {
        printf("Malloc Failed!");
    }
}
