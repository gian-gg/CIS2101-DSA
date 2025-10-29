#include "header.h"

void mode() {
    printf("SETS - CURSOR-BASED IMPLEMENTATION (UNORDERED)\n\n");
}

void initVH(VirtualHeap* VH) {
    // Initializes the virtual heap by linking all nodes into an available list.
    // The avail list acts as a stack: MAX-1 -> MAX-2 -> ... -> 0 -> -1
    for(int i = 0; i < MAX; i++) {
        VH->nodes[i].link = i-1;
    }
    VH->avail = MAX-1; // The head of the avail "stack" is the last index.
}

int alloc(VirtualHeap* VH) {
    // Get the next available node (index) from the avail list stack (a "pop").
    int idx = VH->avail;

    if(idx != -1) { // Check if the heap is not full
        // Update avail to point to the next free node in the chain.
        VH->avail = VH->nodes[idx].link;
    }

    return idx;
}

void dealloc(VirtualHeap* VH, int idx) {
    if (idx != -1) {
        // Return a node (index) to the avail list stack (a "push").
        // Link the deallocated node to the *old* head of the avail list.
        VH->nodes[idx].link = VH->avail;
        // The deallocated node is now the new head.
        VH->avail = idx;
    }
}

void init(SET* S) {
    // Initializes a set to be empty. -1 represents NULL.
    *S = -1;
}

void insertElem(VirtualHeap* VH, SET* S, int elem) {
    // 'trav' will point to the link that needs to be modified (either the head or a node's link).
    SET* trav;
    // Traverse to find the element (duplicate) or the end of the list.
    for(trav = S; *trav != -1 && VH->nodes[*trav].data != elem; trav = &(VH->nodes[*trav].link)) {}

    // If element was not found (loop reached the end), insert it.
    if (*trav == -1) {
        SET newNode = alloc(VH);

        if (newNode != -1) {
            VH->nodes[newNode].data = elem;
            VH->nodes[newNode].link = -1;
            *trav = newNode;
        }
    }
    // If *trav != -1, a duplicate was found, so we do nothing.
}

void deleteElem(VirtualHeap* VH, SET* S, int elem) {
    // Traverse to find the element. 'trav' will point to the link *before* the node to be deleted.
    SET* trav;
    for(trav=S; (*trav) != -1 && VH->nodes[*trav].data != elem; trav = &(VH->nodes[*trav].link)) {}

    // If the element was found...
    if (*trav != -1) {
        SET temp = *trav;
        *trav = VH->nodes[temp].link;
        dealloc(VH, temp);
    }
}

void read(VirtualHeap VH, SET S) {
    printf("{ ");
    for(SET trav = S; trav != -1; trav = VH.nodes[trav].link) {
        printf("%d, ", VH.nodes[trav].data);
    }
    printf("}\n");
}

bool isFull(VirtualHeap VH) {
    // The heap is full if the available list is empty.
    return VH.avail == -1;
}

bool isEmpty(SET S) {
    // A set is empty if its head pointer is -1.
    return S == -1;
}

bool member(VirtualHeap VH, SET S, int elem) {
    // Traverses the set to find the element.
    SET trav;
    for(trav = S; trav != -1 && VH.nodes[trav].data != elem; trav = VH.nodes[trav].link) {}

    // Returns true if the loop finished *without* hitting the end (-1).
    return (trav != -1);
}
