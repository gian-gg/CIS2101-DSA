#include "header.h"

void mode() {
    printf("SETS - CURSOR-BASED IMPLEMENTATION (UNORDERED)\n\n");
}

bool equal(VirtualHeap VH, SET A, SET B) {
    // 1. Check if every element in A is also in B (A is a subset of B).
    for (SET trav = A; trav != -1; trav = VH.nodes[trav].link) {
        if (!member(VH, B, VH.nodes[trav].data)) {
            return false;
        }
    }

    // 2. Check if every element in B is also in A (B is a subset of A).
    for (SET trav = B; trav != -1; trav = VH.nodes[trav].link) {
        if (!member(VH, A, VH.nodes[trav].data)) {
            return false;
        }
    }

    // If both checks pass, the sets are equal.
    return true;
}

SET Union(VirtualHeap* VH, SET A, SET B) {
    SET C;
    init(&C);
    // 'travC' points to the last link in the new set C, allowing O(1) appends.
    SET* travC = &C;

    // --- 1. Copy all elements from A to C ---
    for (SET travA = A; travA != -1; travA = VH->nodes[travA].link) {
        int newNode = alloc(VH);
        if (newNode != -1) {
            VH->nodes[newNode].data = VH->nodes[travA].data;
            VH->nodes[newNode].link = -1;

            *travC = newNode; // Link previous node (or head) to this new node.
            travC = &(VH->nodes[newNode].link); // Advance travC to point to the new node's link.
        }
    }

    // --- 2. Copy elements from B that are NOT in A ---
    for (SET travB = B; travB != -1; travB = VH->nodes[travB].link) {
        int elemB = VH->nodes[travB].data;

        // Check if elemB is already in A.
        SET travA;
        for (travA = A; travA != -1 && VH->nodes[travA].data != elemB; travA = VH->nodes[travA].link) {}

        // If not found in A (travA == -1), add it to C.
        if (travA == -1) {
            int newNode = alloc(VH);
            if (newNode != -1) {
                VH->nodes[newNode].data = elemB;
                VH->nodes[newNode].link = -1;

                *travC = newNode; // Link and advance.
                travC = &(VH->nodes[newNode].link);
            }
        }
    }

    return C;
}

SET Intersection(VirtualHeap* VH, SET A, SET B) {
    SET C;
    init(&C);
    SET* travC = &C;

    // Loop through each element in A.
    for (SET travA = A; travA != -1; travA = VH->nodes[travA].link) {
        int elemA = VH->nodes[travA].data;

        // Check if that element is also in B.
        SET travB;
        for (travB = B; travB != -1 && VH->nodes[travB].data != elemA; travB = VH->nodes[travB].link) {}

        // If found in B (travB != -1), add it to the new set C.
        if (travB != -1) {
            int newNode = alloc(VH);
            if (newNode != -1) {
                VH->nodes[newNode].data = elemA;
                VH->nodes[newNode].link = -1;

                *travC = newNode; // Link and advance.
                travC = &(VH->nodes[newNode].link);
            }
        }
    }

    return C;
}

SET Difference(VirtualHeap* VH, SET A, SET B) {
    SET C;
    init(&C);
    // 'travC' points to the last link in the new set C.
    SET* travC = &C;

    // Loop through each element in A (the minuend).
    SET travA;
    for (SET travA = A; travA != -1; travA = VH->nodes[travA].link) {
        int elemA = VH->nodes[travA].data;

        // Check if that element is in B (the subtrahend).
        SET travB;
        for (travB = B; travB != -1 && VH->nodes[travB].data != elemA; travB = VH->nodes[travB].link) {}

        // If NOT found in B (travB == -1), add it to the new set C.
        if (travB == -1) {
            int newNode = alloc(VH);
            if (newNode != -1) {
                VH->nodes[newNode].data = elemA;
                VH->nodes[newNode].link = -1;

                *travC = newNode; // Link and advance.
                travC = &(VH->nodes[newNode].link);
            }
        }
    }

    return C;
}
