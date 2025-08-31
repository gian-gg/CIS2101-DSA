#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char elem[MAX];
    int count;
} charList;

bool findElem(charList L, char element) {
    int i;
    for(i = 0; i < L.count && L.elem[i] != element; i++) {}
    return i != L.count;
}

void delElem(charList *L, char element) {
    int i;
    for(i = 0; i < L->count && L->elem[i] != element; i++) {}

    if (L->elem[i] == element) {
        for(int x = i; x < (L->count-1); x++) {
            L->elem[x] = L->elem[x + 1];
        }

        L->elem[L->count--] = '\0';
    }
}

void delAllOccur(charList *L, char element) {
    int x = 0;
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] != element) {
            L->elem[x++] = L->elem[i];
        }
    }
    L->count = x;
}

int main() {
    charList L = {{}, 0};

    printf("findElem: %s", findElem(L, 'C') ? "true" : "false");

    printf("\n");
    return 0;
}
