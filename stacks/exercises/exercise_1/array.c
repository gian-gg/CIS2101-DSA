#include "header.h"


struct DataStructure {
    char data[MAX];
    int top; // index of the last element
};

void mode() {
    printf("=================\n");
    printf("MODE: ARRAY\n");
    printf("=================\n");
}


LIST init() {
    LIST L = malloc(sizeof(struct DataStructure));
    L->top = -1;

    return L;
}

void display(LIST L) {
    for(int i = L->top; i >= 0; i--) {
        printf("%c ", L->data[i]);
    }
    printf("\n");
}

void push(LIST* L, char elem) {
    (*L)->data[++((*L)->top)] = elem;
}

void pop(LIST* L) {
    (*L)->top--;
}

char top(LIST L) {
    return L->data[L->top];
}

bool empty(LIST L) {
    return L->top == -1 ? true : false;
}

bool full(LIST L) {
    return L->top == MAX-1 ? true : false;
}
