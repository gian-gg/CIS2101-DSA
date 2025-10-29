#include "header.h"

void mode() {
    printf("SETS - LINKED LIST IMPLEMENTATION (UNORDERED)\n\n");
}

bool equal(SET A, SET B) {
    // 1. Check if every element in A is also in B (A subset B).
    for (SET trav = A; trav != NULL; trav = trav->link) {
        if (!member(B, trav->data)) {
            return false;
        }
    }

    // 2. Check if every element in B is also in A (B subset A).
    for (SET trav = B; trav != NULL; trav = trav->link) {
        if (!member(A, trav->data)) {
            return false;
        }
    }

    // If both checks pass, the sets are equal.
    return true;
}

SET Union(SET A, SET B) {
    SET C;
    init(&C);
    SET* travC = &C;

    // --- 1. Copy all elements from A to C ---
    for(SET travA = A; travA != NULL; travA = travA->link) {
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode) {
            newNode->data = travA->data;
            newNode->link = NULL;

            *travC = newNode; // Link the new node to the end of the list.
            travC = &((*travC)->link); // Advance travC to the new node's link.
        }
    }

    // --- 2. Copy elements from B that are NOT in A ---
    for(SET travB = B; travB != NULL; travB = travB->link) {
        // Check if element is already in A (which is now in C).
        if (!member(A, travB->data)) {
            SET newNode = (SET)malloc(sizeof(struct node));
            if (newNode) {
                newNode->data = travB->data;
                newNode->link = NULL;

                *travC = newNode; // Link and advance.
                travC = &((*travC)->link);
            }
        }
    }

    return C;
}

SET Intersection(SET A, SET B) {
    SET C;
    init(&C);
    SET* travC = &C;

    // For every element in A...
    for(SET travA = A; travA != NULL; travA = travA->link) {
        // ...check if it's also a member of B.
        if (member(B, travA->data)) {
            // If it is, add it to C.
            SET newNode = (SET)malloc(sizeof(struct node));
            if (newNode) {
                newNode->data = travA->data;
                newNode->link = NULL;

                *travC = newNode; // Link and advance.
                travC = &((*travC)->link);
            }
        }
    }

    return C;
}

SET Difference(SET A, SET B) {
    SET C;
    init(&C);
    SET* travC = &C;

    // For every element in A...
    for(SET travA = A; travA != NULL; travA = travA->link) {
        // ...check if it is NOT a member of B.
        if (!member(B, travA->data)) {
            // If it's not in B, add it to C.
            SET newNode = (SET)malloc(sizeof(struct node));
            if (newNode) {
                newNode->data = travA->data;
                newNode->link = NULL;

                *travC = newNode; // Link and advance.
                travC = &((*travC)->link);
            }
        }
    }

    return C;
}
