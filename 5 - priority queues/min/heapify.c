#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int lastNdx;   // index of last element
} MinHeap;

void heapifySubtree(MinHeap *H, int parent) {
    int smallest = parent;
    int LC = 2 * parent + 1;
    int RC = 2 * parent + 2;

    if (LC <= H->lastNdx && H->elem[LC] < H->elem[smallest]) {
        smallest = LC;
    }

    if (RC <= H->lastNdx && H->elem[RC] < H->elem[smallest]) {
        smallest = RC;
    }

    if (smallest != parent) {
        int temp = H->elem[parent];
        H->elem[parent] = H->elem[smallest];
        H->elem[smallest] = temp;

        heapifySubtree(H, smallest);
    }

}

// Utility function to print the heap
void printHeap(MinHeap H) {
    for (int  i = 0; i <= H.lastNdx; i++) {
        printf("%d ", H.elem[i]);
    }
    
    printf("\n");
}

int main() {
    MinHeap H = {{10, 15, 20, 17, 25, 30, 40, 5}, 7};

    printf("Original array (not a min-heap):\n");
    printHeap(H);

    heapifySubtree(&H, 0);

    printf("After heapifying subtree at root (index 0):\n");
    printHeap(H);

    return 0;
}
