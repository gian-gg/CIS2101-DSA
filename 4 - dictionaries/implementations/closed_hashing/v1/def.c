#include "header.h"

void mode() {
    printf("DICTIONARIES - CLOSED HASHING v1\n");
    printf("================================\n\n");
}

int hash(int data) {
    return data % MAX;
}

void init(DICTIONARY D) {
    for(int idx = 0; idx < MAX; idx++) {
        D[idx] = EMPTY;
    }
}

void insert(DICTIONARY D, int data) {
    int hashValue = hash(data);

    int idx, trav;
    for (idx = 0, trav = hashValue; idx < MAX && D[trav] != EMPTY && D[trav] != DELETED; idx++, trav = (hashValue + idx) % MAX) {}

    if (idx < MAX) {
        D[trav] = data;
    } else {
        printf("Hash table full! Cannot insert %d\n", data);
    }
}

void delete(DICTIONARY D, int data) {
    int hashValue = hash(data);

    int idx, trav;
    for (idx = 0, trav = hashValue; idx < MAX && D[trav] != EMPTY && D[trav] != data; idx++, trav = (hashValue + idx) % MAX) {}

    if (idx < MAX && D[trav] == data) {
        D[trav] = DELETED;
    } else {
        printf("%d not found in dictionary\n", data);
    }
}

bool member(DICTIONARY D, int data) {
    int hashValue = hash(data);

    int idx, trav;
    for (idx = 0, trav = hashValue; idx < MAX && D[trav] != EMPTY && D[trav] != data; idx++, trav = (hashValue + idx) % MAX) {}

    return (idx < MAX && D[trav] == data) ? true : false;
}

void visualize(DICTIONARY D) {
    for (int idx = 0; idx < MAX; idx++) {
        int currElem = D[idx];
        
        if (currElem == EMPTY) {
            printf("[ %3s ]\n", "EMP");
        } else if (currElem == DELETED) {
            printf("[ %3s ]\n", "DEL");
        } else {
            printf("[ %3d ]\n", currElem);
        }
    }
    printf("\n");
}

void display(DICTIONARY D) {
    for (int idx = 0; idx < MAX; idx++) {
        int currElem = D[idx];

        if (currElem != EMPTY && currElem != DELETED) {
            printf("%d ", currElem);
        }
    }
    printf("\n");
}