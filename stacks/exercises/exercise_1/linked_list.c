#include "header.h"

struct DataStructure {
    char elem;
    struct DataStructure* link;
};

void mode() {
    printf("=================\n");
    printf("MODE: LINKED LIST\n");
    printf("=================\n");
}

LIST init() {
    LIST L = NULL;

    return L;
}

void display(LIST L) {
    for(LIST trav = L; trav != NULL; trav = trav->link) {
        printf("%c ", trav->elem);
    }

    printf("\n");
}

void push(LIST *L, char data) {
    LIST temp = malloc(sizeof(struct DataStructure));

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
