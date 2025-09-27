#include "./header.h"

void mode() {
    printf("SETS - BIT VECTOR\n");
    printf("==================\n\n");
}

void init(SET* S) {
    for(int idx = 0; idx < MAX; idx++) {
        (*S)[idx] = 0;
    }
}

bool isFull(SET S) {
    for(int idx = 0; idx < MAX; idx++) {
        if (S[idx] == 0) return false;
    }
    
    return true;
}

bool isEmpty(SET S) {
    for(int idx = 0; idx < MAX; idx++) {
        if (S[idx] != 0) return false;
    }
    
    return true;
}

bool member(SET S, int data) {
    return (S[data] != 0) ? true : false;
}

void insert(SET* S, int data) {
    (*S)[data] = 1;
}

void delete(SET* S, int data) {
    (*S)[data] = 0;
}

void read(SET S) {
    printf("{ ");

    int idx;
    for(idx = 0; idx < MAX; idx++) {
        if (S[idx] == 1) printf("%d, ", idx);
    }

    printf("}\n");
}

bool equal(SET A, SET B) {
    for(int idx = 0; idx < MAX; idx++) {
        if (A[idx] != B[idx]) return false;
    }


    return true;
}


SET* Union(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    if (C != NULL) {
        init(C);
        
        for(int idx = 0; idx < MAX; idx++) {
            (*C)[idx] = A[idx] || B[idx];
        }

    }

    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    if (C != NULL) {
        init(C);
        
        for(int idx = 0; idx < MAX; idx++) {
            (*C)[idx] = A[idx] && B[idx];
        }

    }

    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = malloc(sizeof(SET));

    if (C != NULL) {
        init(C);
        
        for(int idx = 0; idx < MAX; idx++) {
            (*C)[idx] = A[idx] == 1 && B[idx] == 0;
        }

    }

    return C;
}
