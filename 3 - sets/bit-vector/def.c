#include "header.h"

void mode() {
    printf("SETS - BIT VECTOR IMPLEMENTATION\n\n");
}

void init(SET S) {
    // Initializes the set to empty by setting all bits to 0.
    for(int i = 0; i < MAX; i++) {
        S[i] = 0;
    }
}

void insertElem(SET S, int elem) {
    // Inserts an element by "flipping" its corresponding bit to 1 (true).
    // Assumes 'elem' is a valid index (0 <= elem < MAX).

    S[elem] = 1;
}

void deleteElem(SET S, int elem) {
    // Deletes an element by "flipping" its corresponding bit to 0 (false).
    S[elem] = 0;
}

void read(SET S) {
    printf("{ ");
    // Iterates through the entire vector...
    for(int i = 0; i < MAX; i++) {
        // ...and prints the *index* 'i' if its bit is set to 1.
        if (S[i]) printf("%d, ", i);
    }
    printf("}\n");
}


bool isFull(SET S) {
    int i;
    // Search for the first '0' (empty slot).
    for(i = 0; i < MAX && S[i] != 0; i++) {}

    // If the loop finished (i == MAX), it means no '0' was found.
    // Therefore, the set is full.
    return (i == MAX);
}

bool isEmpty(SET S) {
    int i;
    // Search for the first '1' (an element).
    for(i = 0; i < MAX && S[i] == 0; i++) {}

    // If the loop finished (i == MAX), it means no '1' was found.
    // Therefore, the set is empty.
    return (i == MAX);
}

bool member(SET S, int elem) {
    // O(1) membership check: directly returns the boolean value (1 or 0)
    // at the element's index.
    return (S[elem]);
}

bool equal(SET A, SET B) {
    int i;
    // Find the first index where the bits do not match.
    for(i = 0; i < MAX && A[i] == B[i]; i++) {}

    // If the loop finished (i == MAX), it means all bits matched.
    return (i == MAX);
}

SET* Union(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));

    if (C != NULL) {
        init(*C);

        // Perform a bitwise OR. The result has a '1' if the bit is
        // in A, in B, or in both.

        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] || B[i];
        }
    }

    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));

    if (C != NULL) {
        init(*C);

        // Perform a bitwise AND. The result has a '1' *only if* the bit
        // is in *both* A and B.

        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && B[i];
        }
    }

    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = (SET*)malloc(sizeof(SET));

    if (C != NULL) {
        init(*C);

        // Perform bitwise A AND (NOT B). The result has a '1' *only if*
        // the bit is in A and *not* in B.

        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && !(B[i]);
        }
    }

    return C;
}
