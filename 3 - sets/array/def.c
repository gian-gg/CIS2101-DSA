#include "header.h"

void init(SET* S) {
    // Sets the element count to 0, making the set empty.
    S->count = 0;
}

void insertElem(SET* S, int elem) {
    // Inserts only if the set isn't full and the element isn't already a member.
    if (!isFull(*S) && member(*S, elem) == -1) {
        // Adds the element to the end and increments the count.
        S->array[(S->count)++] = elem;
    }
}

void deleteElem(SET* S, int elem) {
    // Find the index of the element to delete.
    int index = member(*S, elem);

    // If the element was found (index != -1) and the set isn't empty...
    if (!isEmpty(*S) && index != -1) {
        //
        // Efficiently delete by overwriting the element with the *last* element.
        S->array[index] = S->array[(S->count) - 1];
        // Then, decrease the count, effectively removing the (now duplicated) last element.
        (S->count)--;
    }
}

void read(SET S) {
    printf("{ ");
    // Iterates through the array and prints all valid elements up to 'count'.
    for(int i = 0 ; i < S.count; i++) {
        printf("%d, ", S.array[i]);
    }
    printf("}\n");
}

bool isFull(SET S) {
    // Returns true if the count has reached the array's maximum capacity.
    return (S.count == (MAX));
}

bool isEmpty(SET S) {
    // Returns true if the set has 0 elements.
    return (S.count == 0);
}

int member(SET S, int elem) {
    // Linearly searches for an element.
    int trav;
    for(trav = 0; trav < S.count && S.array[trav] != elem; trav++) {}

    // Returns its index if found, otherwise returns -1.
    return (trav < S.count) ? trav : -1;
}
