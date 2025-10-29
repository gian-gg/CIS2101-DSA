#include "header.h"

void mode() {
    printf("DICT - CLOSED HASHING (LINEAR PROBING)\n\n");
}

int hash(int key) {
    return abs(key) % MAX;
}

void init(DICT D) {
    for (int i = 0; i < MAX; i++) {
        D[i].key = EMPTY;
        strcpy(D[i].value, "");
    }
}

void insertElem(DICT D, int key, char* value) {
    int hv = hash(key);
    int i = hv;
    int count = 0;

    for (i = hv, count = 0;
         count < MAX &&
         D[i].key != EMPTY &&
         D[i].key != DELETED &&
         D[i].key != key;
         i = (i + 1) % MAX, count++) {}

    if (count == MAX) return;
    if (D[i].key == key) return;

    D[i].key = key;
    strcpy(D[i].value, value);
}

void deleteElem(DICT D, int key) {
    int hv = hash(key);
    int i;
    for (i = hv;
         D[i].key != EMPTY && D[i].key != key;
         i = (i + 1) % MAX) {}

    if (D[i].key == key) {
        D[i].key = DELETED;
        strcpy(D[i].value, "");
    }
}

bool member(DICT D, int key) {
    int hv = hash(key);
    int i;
    for (i = hv;
         D[i].key != EMPTY && D[i].key != key;
         i = (i + 1) % MAX) {}

    return (D[i].key == key);
}

char* getValue(DICT D, int key) {
    int hv = hash(key);
    int i;
    for (i = hv;
         D[i].key != EMPTY && D[i].key != key;
         i = (i + 1) % MAX) {}

    return (D[i].key == key) ? D[i].value : '\0';
}

void visualize(DICT D) {
    for (int i = 0; i < MAX; i++) {
        printf("[ %d ] ", i);
        if (D[i].key == EMPTY) {
            printf("[EMP]\n");
        } else if (D[i].key == DELETED) {
            printf("[DEL]\n");
        } else {
            printf("{ %d: \"%s\" }\n", D[i].key, D[i].value);
        }
    }
    printf("\n");
}

void display(DICT D) {
    printf("[");
    for (int i = 0; i < MAX; i++) {
        if (D[i].key != EMPTY && D[i].key != DELETED) {
            printf("\n   { %d: \"%s\"},", D[i].key, D[i].value);
        }
    }
    printf("\n]\n");
}
