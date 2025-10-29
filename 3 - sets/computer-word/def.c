#include "header.h"

void mode() {
    printf("SETS - COMPUTER WORD IMPLEMENTATION\n\n");
}

void init(SET* A) {
    *A = 0;
}

/*
    prints out the n of 2^n
*/
void read(SET A) {
    printf("{ ");
    for(int idx = 0; idx < MAX_BITS; idx++) {
        if ((A & BIT_MASK(idx)) != 0) printf("%d, ", idx);
    }
    printf("}\n");
}

/*
       data = 0
          A = 0110 0010
    mask(0) = 0000 0001
A | mask(0) = 0110 0011
*/
void insertElem(SET* A, int data) {
    if (data < MAX_BITS) *A |= (BIT_MASK(data));
}

/*
     data = 4
        A = 0110 0011
  mask(4) = 0001 0000
 A & mask = 0000 0000 (not in set)
*/
bool member(SET A, int data)  {
    if (data < MAX_BITS) {
        return ((A & BIT_MASK(data)) != 0) ? true : false;
    }
    return false;
}

/*
    data = 2
 mask(2) = 0000 0010
       A = 0110 0011
~mask(2) = 1111 1101
       A = 0110 0001
*/
void deleteElem(SET* A, int data) {
    if (data < MAX_BITS) *A &= ~(BIT_MASK(data));
}

bool equal(SET A, SET B) {
    return (A == B);
}

/*
    A = 0010 0101
    B = 1101 0001
A | B = 1111 0101
*/
SET Union(SET A, SET B)  {
    return A | B;
}

/*
    A = 0010 0101
    B = 1101 0001
A & B = 0000 0001
*/
SET Intersection(SET A, SET B)  {
    return A & B;
}

/*
    B = 1101 0001
    A = 0010 0101
   ~B = 0010 1110
A & B = 0010 0100
*/
SET Difference(SET A, SET B)  {
    return A & ~B;
}
