#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node* link;
} *LIST;

void mode();
void init(LIST*);


void mode() {
    printf("=================\n");
    printf("MODE: LINKED LIST\n");
    printf("=================\n");
}

void init(LIST *L) {
    *L = NULL;
} // set pointer to list to null, empty

void push(LIST *L, char data) {
    LIST temp = malloc(sizeof(struct node));

    temp->elem = data;
    temp->link = *L; // link new node is next node
    *L = temp; // update link header to point at newNode
}

void pop(LIST* L) {
    LIST temp = *L; // point to the target node
    *L = temp->link; // update link to next node, skipping target node
    free(temp); // delete target node
}

char top(LIST L) {
    return L->elem;
}

bool empty(LIST L) {
    return L == NULL ? true : false;
}

bool full(LIST L) {
    return false; // only time stack is full when there is
} // no more space on the heap, might check using malloc
