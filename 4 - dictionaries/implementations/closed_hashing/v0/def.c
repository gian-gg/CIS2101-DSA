#include "header.h"

void mode() {
    printf("DICTIONARIES - CLOSED HASHING v0\n");
    printf("================================\n\n");
}

int hash(int data) {
    return data % MAX;
}

// Initializes the DICTIONARY by marking all slots as EMPTY (-1)
void init(DICTIONARY D) {
    for(int idx = 0; idx < MAX; idx++) {
        D[idx] = EMPTY;  // EMPTY means unused slot
    }
}

void insert(DICTIONARY D, int data) {
    // Step 1: Check if the data already exists — avoid duplicates
    if (member(D, data) != true) { 
        int idx = hash(data);              // Compute starting index using hash function
        int firstAvail = -1;               // To store index of the first DELETED slot (if any)
        int stop = (idx + MAX - 1) % MAX;  // Define stopping point (one step before starting index)

        // Step 2: Linear probing with DELETED-slot reuse
        while (D[idx] != EMPTY && D[idx] != data && idx != stop) {
            // Remember the first DELETED slot encountered (to reuse later)
            if (firstAvail == -1 && D[idx] == DELETED) {
                firstAvail = idx;
            }

            // Move to the next slot (wrap around using modulo)
            idx = (idx + 1) % MAX;
        }

        // Step 3: Decide where to insert the new data
        // - If we stopped at an EMPTY slot, insert there.
        // - If we found a DELETED slot earlier, insert there instead.
        if (D[idx] == EMPTY || (D[idx] != data && firstAvail != -1)) {
            D[(firstAvail == -1) ? idx : firstAvail] = data;
        }
    }
}


void delete(DICTIONARY D, int data) {
    int idx, stop;

    // Step 1: Initialize starting and stopping indices
    // - Start at the hash index for the given data
    // - Stop one slot before the starting index (to avoid infinite loop)
    for(idx = hash(data), stop = (idx + MAX - 1) % MAX;
        idx != stop && D[idx] != EMPTY && D[idx] != data;
        idx = (idx + 1) % MAX) {}

    // Step 2: If the data is found, mark the slot as DELETED
    // - This allows reuse of the slot during future insertions
    if (D[idx] == data) {
        D[idx] = DELETED;
    }
}

bool member(DICTIONARY D, int data) {
    int idx, stop;
    for(idx = hash(data), stop = (idx + MAX - 1) % MAX;
        idx != stop && D[idx] != EMPTY && D[idx] != data;
        idx = (idx + 1) % MAX) {}

    return (D[idx] == data) ? true : false;
}


void visualize(DICTIONARY D) {
    for (int idx = 0; idx < MAX; idx++) {
        int currElem = D[idx];
        
        if (currElem == EMPTY) {
            printf("[ %3s ]\n", "EMP");
        } else if (currElem == DELETED) {
            printf("[ %3s ]\n", "DEL");
        } else {
            printf("[ %3d ]\n", currElem);
        }
    }
    printf("\n");
}

void display(DICTIONARY D) {
    for (int idx = 0; idx < MAX; idx++) {
        int currElem = D[idx];

        if (currElem != EMPTY && currElem != DELETED) {
            printf("%d ", currElem);
        }
    }
    printf("\n");
}
