#include "./header.h"

#define BIT_MASK(x) (1U << (x))
#define MAX_BITS (sizeof(SET) * 8) 


void mode() {
    printf("SETS - COMPUTER WORD\n");
    printf("==================\n\n");
}

void init(SET* S) {
    *S = 0;
}

bool isFull(SET S) {
    return S == ~0U;
}

bool isEmpty(SET S) {
    return (S == 0);
}

bool member(SET S, int data) {
    if (data < 0 || data >= MAX_BITS) return false;

    return (S & BIT_MASK(data)) != 0;
}

void insert(SET* S, int data) {
    if (data >= 0 && data < MAX_BITS) *S |= BIT_MASK(data);
        
}

void delete(SET* S, int data) {
    if (data >= 0 && data < MAX_BITS) *S &= ~BIT_MASK(data);
}


void read(SET S) {
    printf("{ ");
    for (int idx = 0; idx < MAX_BITS; idx++) {
        if (S & BIT_MASK(idx)) printf("%d, ", idx);
    }

    printf("}\n");
}


bool equal(SET A, SET B) {
    return A == B;
}


SET* Union(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    if (C != NULL) {
        init(C);
        
        *C = A | B;
    }

    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    if (C != NULL) {
        init(C);
        
        *C = A & B;
    }

    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = malloc(sizeof(SET));

    if (C != NULL) {
        init(C);
        
        *C = A & ~B;
    }

    return C;
}
