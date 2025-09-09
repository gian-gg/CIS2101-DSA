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
}

void push(LIST *L, char data) {
    LIST temp = malloc(sizeof(struct node));

    temp->elem = data;
    temp->link = *L;
    *L = temp;
}

void pop(LIST* L) {
    LIST temp = *L;
    *L = temp->link;
    free(temp);
}

char top(LIST L) {
    return L->elem;
}

bool empty(LIST L) {
    return L == NULL ? true : false;
}

bool full(LIST L) {
    return false;
}
