#include "header.h"

void mode() {
    printf("DICTIONARIES - CLOSED HASHING v3\n");
    printf("================================\n\n");
}

int hash(int data) {
    return data % DICT_SIZE;
}

void init(DICTIONARY *D) {
    for(int idx = 0; idx < DICT_SIZE; idx++) {
        D->array[idx] = EMPTY;
    }
    D->last = DICT_SIZE-1;
}

void insert(DICTIONARY *D, int data) {
    int hashValue = hash(data);

    if (D->array[hashValue] == EMPTY) {
        D->array[hashValue] = data;
    } else if (D->last < MAX) {
        D->array[++(D->last)] = data;
    } else {
        printf("Hash table full! Cannot insert %d\n", data);
    }
}

void delete(DICTIONARY *D, int data) {
    int hashValue = hash(data);

    if (D->array[hashValue] == data) {
        D->array[hashValue] = EMPTY;
    } else {
        int idx;
        for(idx = DICT_SIZE; idx < MAX && D->array[idx] != data; idx++) {}

        if (idx < MAX) {
            D->array[idx] = D->array[D->last--];
        } else {
            printf("%d not found in dictionary\n", data);
        }
    }
}

bool member(DICTIONARY D, int data) {
    int hashValue = hash(data);

    if (D.array[hashValue] == data) {
        return true;
    } else {
        int idx;
        for(idx = DICT_SIZE; idx < MAX && D.array[idx] != data; idx++) {}

        return (idx < MAX) ? true : false;
    }
}

void visualize(DICTIONARY D) {
    printf("LAST: %d\n", D.last);
    for(int idx = 0; idx <= D.last; idx++) {
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
    for(int idx = 0; idx <= D.last; idx++) {
        int currElem = D.array[idx];
        if (currElem != EMPTY) printf("%d ", currElem);
    }

    printf("\n");
}