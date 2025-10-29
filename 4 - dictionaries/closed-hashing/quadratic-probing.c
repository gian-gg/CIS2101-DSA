#include "header.h"

void mode() {
    printf("DICT - CLOSED HASHING (QUADRATIC PROBING)\n\n");
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

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == key) return;

        if (D[pos].key == EMPTY || D[pos].key == DELETED) {
            D[pos].key = key;
            strcpy(D[pos].value, value);
            return;
        }
    }

    printf("Insertion failed: Table is full.\n");
}

void deleteElem(DICT D, int key) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == EMPTY) return;
        if (D[pos].key == key) {
            D[pos].key = DELETED;
            strcpy(D[pos].value, "");
            return;
        }
    }
}

bool member(DICT D, int key) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == EMPTY) return false;
        if (D[pos].key == key) return true;
    }

    return false;
}

char* getValue(DICT D, int key) {
    int hv = hash(key);

    for (int i = 0; i < MAX; i++) {
        int pos = (hv + i * i) % MAX;

        if (D[pos].key == EMPTY) break;
        if (D[pos].key == key) return D[pos].value;
    }

    return "\0";
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
