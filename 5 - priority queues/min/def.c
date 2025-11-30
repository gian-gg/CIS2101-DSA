#include "header.h"

void init(MINHEAP* M) {
    M->count = -1;
}

void display(MINHEAP M) {
    if (M.count > -1) {
        for(int i = 0; i <= M.count; i++)  {
            printf("%d ", M.heap[i]);
        }
        printf("\n");
    } else {
        printf("HEAP IS EMPTY!\n");
    }
}

void heapify(MINHEAP* M, int root) {
    // initalize variables
    int smallest = root;
    int LC = 2*root+1;
    int RC = LC+1;

    // check if left child exists and compare it to smallest
    if (LC <= M->count && M->heap[LC] < M->heap[smallest]) {
        smallest = LC;
    }
    // check if right child exists and compare it to smallest
    if (RC <= M->count && M->heap[RC] < M->heap[smallest]) {
        smallest = RC;
    }

    // if the smallest is not the root then swap and continue heapify
    if (smallest != root) {
        int temp = M->heap[root];
        M->heap[root] = M->heap[smallest];
        M->heap[smallest] = temp;

        heapify(M, smallest);
    }
}

void insert(MINHEAP* M, int val) {
    if ((M->count+1) < MAX) { // check if heap is full
        // initialize variables
        int child = ++(M->count);
        int parent = (child-1)/2;

        // heapify up (put val in the correct location)
        while(child > 0 && val < M->heap[parent]) {
            M->heap[child] = M->heap[parent];

            child = parent;
            parent = (child-1)/2;
        }

        M->heap[child] = val;

        printf("Inserted %d\n", val);
    } else {
        printf("HEAP IS FULL!\n");
    }
}

int deleteMin(MINHEAP* M) {
    int min = -1;
    // check if heap is not empty
    if (M->count > min) {
        // get root(min) and replace with farthest descendant
        min = M->heap[0];
        M->heap[0] = M->heap[(M->count)--];

        // heapify down, place new root at the correct location
        heapify(M, 0);
    }

    return min;
}

void heapSort(MINHEAP* M) {
    int ogSize = M->count;
    for(int idx = ogSize; idx > -1; idx--) {
        M->heap[idx] = deleteMin(M);
    }
    M->count = ogSize;
}
