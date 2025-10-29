#include "header.h"

void mode() {
    printf("SETS - ARRAY IMPLEMENTATION (UNORDERED)\n\n");
}

bool equal(SET A, SET B) {
    // For sets to be equal, they must first have the same number of elements.
    if (A.count != B.count) {
        return false;
    }

    // If counts match, check if every element in A is also in B.
    // (No need to check B against A, since the counts are identical).
    for (int i = 0; i < A.count; i++) {
        if (member(B, A.array[i]) == -1) {
            return false;
        }
    }

    return true;
}

SET Union(SET A, SET B) {
    SET C;
    init(&C);

    // 1. Copy all elements from set A into C.
    for (int i = 0; i < A.count; i++) {
        C.array[C.count++] = A.array[i];
    }

    // 2. Add elements from set B *only if* they are not already in set A.
    for (int i = 0; i < B.count; i++) {
        if (member(A, B.array[i]) == -1) {
            C.array[C.count++] = B.array[i];
        }
    }

    return C;
}

SET Intersection(SET A, SET B) {
    SET C;
    init(&C);

    // Iterate through A, and add any element that is *also* a member of B.
    for (int i = 0; i < A.count; i++) {
        // `!= -1` means the element was found in B.
        if (member(B, A.array[i]) != -1) {
            C.array[C.count++] = A.array[i];
        }
    }

    return C;
}

SET Difference(SET A, SET B) {
    SET C;
    init(&C);

    // Iterate through A, and add any element that is *NOT* a member of B.
    for (int i = 0; i < A.count; i++) {
        // `== -1` means the element was NOT found in B.
        if (member(B, A.array[i]) == -1) {
            C.array[C.count++] = A.array[i];
        }
    }

    return C;
}
