#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct ARRAY {
    char data[MAX];
    int top; // index of the last element
} *LIST;

void mode() {
    printf("=================\n");
    printf("MODE: ARRAY\n");
    printf("=================\n");
}

void init(LIST *L) {
    *L = malloc(sizeof(struct ARRAY));
    (*L)->top = -1;
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
