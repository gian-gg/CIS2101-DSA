#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node* link;
} *STACK;



void mode() {
    printf("=================\n");
    printf("MODE: LINKED LIST\n");
    printf("=================\n");
}

void init(STACK *L) {
    *L = NULL;
} // set pointer to STACK to null, empty

void push(STACK *L, char data) {
    STACK temp = malloc(sizeof(struct node));

    temp->elem = data;
    temp->link = *L; // link new node is next node
    *L = temp; // update link header to point at newNode
}

void pop(STACK* L) {
    STACK temp = *L; // point to the target node
    *L = temp->link; // update link to next node, skipping target node
    free(temp); // delete target node
}

char top(STACK L) {
    return L->elem;
}

bool empty(STACK L) {
    return L == NULL ? true : false;
}

bool full(STACK L) {
    return false; // only time stack is full when there is
} // no more space on the heap, might check using malloc
