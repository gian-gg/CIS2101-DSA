#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct ARRAY {
    char data[MAX];
    int top; // index of the last element
} *STACK;

void mode() {
    printf("=================\n");
    printf("MODE: ARRAY\n");
    printf("=================\n");
}

void init(STACK *L) {
    *L = malloc(sizeof(struct ARRAY));
    (*L)->top = -1;
}

void push(STACK* L, char elem) {
    (*L)->data[++((*L)->top)] = elem;
}

void pop(STACK* L) {
    (*L)->top--;
}

char top(STACK L) {
    return L->data[L->top];
}

bool empty(STACK L) {
    return L->top == -1 ? true : false;
}

bool full(STACK L) {
    return L->top == MAX-1 ? true : false;
}
