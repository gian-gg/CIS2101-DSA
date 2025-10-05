#include "header.h"

void mode() {
    printf("DICTIONARIES - CLOSED HASHING v1\n");
    printf("================================\n\n");
}

int hash(int data) {
    return data % DICT_SIZE;
}

void init(DICTIONARY *D) {
    for (int idx = 0; idx < DICT_SIZE; idx++) {
        D->array[idx] = EMPTY;
    }

    D->last = DICT_SIZE - 1;  // last points to the end of main area
}

void insert(DICTIONARY *D, int data) {
    int hashValue = hash(data); 

    // CASE 1: Slot is empty → directly place the element
    if (D->array[hashValue] == EMPTY) {
        D->array[hashValue] = data;
    }
    // CASE 2: Collision → store in overflow area
    else if (D->last < MAX - 1) {
        D->array[++(D->last)] = data;
    }
    // CASE 3: Both full → cannot insert
    else {
        printf("Hash table full! Cannot insert %d\n", data);
    }
}

void delete(DICTIONARY *D, int data) {
    int hashValue = hash(data);

    // CASE 1: Found in main area → just mark as EMPTY
    if (D->array[hashValue] == data) {
        D->array[hashValue] = EMPTY;
    }
    // CASE 2: Search in overflow area
    else {
        int idx;
        for (idx = DICT_SIZE; idx <= D->last && D->array[idx] != data; idx++) {}

        if (idx <= D->last) {
            // Replace deleted element with last overflow element
            D->array[idx] = D->array[D->last--];
        } else {
            printf("%d not found in dictionary\n", data);
        }
    }
}

bool member(DICTIONARY D, int data) {
    int hashValue = hash(data);

    // CASE 1: Found directly in main table
    if (D.array[hashValue] == data) {
        return true;
    }
    // CASE 2: Search through overflow area
    else {
        int idx;
        for (idx = DICT_SIZE; idx <= D.last && D.array[idx] != data; idx++) {}

        return (idx <= D.last) ? true : false;
    }
}

void visualize(DICTIONARY D) {
    printf("LAST: %d\n", D.last);
    for (int idx = 0; idx <= D.last; idx++) {
        int currElem = D.array[idx];

        if (idx == DICT_SIZE) printf("=======\n");

        if (currElem != EMPTY) {
            printf("[ %3d ]", currElem);
        } else {
            printf("[ %3s ]", "EMP");
        }
        printf("\n");
    }
    printf("\n");
}

void display(DICTIONARY D) {
    for (int idx = 0; idx <= D.last; idx++) {
        int currElem = D.array[idx];
        if (currElem != EMPTY) {
            printf("%d ", currElem);
        }
    }
    printf("\n");
}
