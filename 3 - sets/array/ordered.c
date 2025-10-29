#include "header.h"

void mode() {
    printf("SETS - ARRAY IMPLEMENTATION (ORDERED)\n\n");
}

bool equal(SET A, SET B) {
    if (A.count == B.count) {
        int i;
        for(i = 0; i < A.count && A.array[i] == B.array[i]; i++) {}

        return !(i < A.count);
    }

    return false;
}

SET Union(SET A, SET B) {
    SET C;
    init(&C);

    int travA = 0;
    int travB = 0;

    while (travA < A.count && travB < B.count) {

        if (A.array[travA] < B.array[travB]) {
            C.array[C.count++] = A.array[travA++];

        } else if (A.array[travA] > B.array[travB]) {
            C.array[C.count++] = B.array[travB++];

        } else {
            C.array[C.count++] = A.array[travA];
            travA++;
            travB++;
        }
    }

    while (travA < A.count) {
        C.array[C.count++] = A.array[travA++];
    }

    while (travB < B.count) {
        C.array[C.count++] = B.array[travB++];
    }

    return C;
}

SET Intersection(SET A, SET B) {
    SET C;
    init(&C);

    // do something

    return C;
}

SET Difference(SET A, SET B) {
    SET C;
    init(&C);

    // do something

    return C;
}
