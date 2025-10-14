#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX  10

typedef struct {
  int elem[MAX];
  int lastNdx;
} MinHeap;

void init(MinHeap *T);
void insertMin(MinHeap *T, int data);
int deleteMin(MinHeap *T);
void display(MinHeap T);

MinHeap* insertAllMinHeap(MinHeap T);
MinHeap* heapSort(MinHeap T);


int main() {
    MinHeap T;
    init(&T);

    MinHeap UnsortedTree = {{10, 15, 20, 17, 25, 30, 40, 5}, 7};

    // MinHeap* SortedTree = insertAllMinHeap(UnsortedTree);
    MinHeap* SortedTree = heapSort(UnsortedTree);

    display(*SortedTree);


    return 0;
}

void init(MinHeap *T) {
    T->lastNdx = -1;
}

void insertMin(MinHeap *T, int data) {
    if(T->lastNdx + 1 < MAX) {
        int child = ++(T->lastNdx);
        int parent = (child - 1) / 2;

        while(child > 0 && T->elem[parent] > data) {
            T->elem[child] = T->elem[parent];

            child = parent;
            parent = (parent - 1) / 2;
        }

        T->elem[child] = data;
    }
}

int deleteMin(MinHeap *T) {
    int temp = -1;
    if(T->lastNdx >= 0) {
        temp = T->elem[0];
        int data = T->elem[T->lastNdx--];

        int parent = 0;
        int LC = parent * 2 + 1;
        int RC = LC + 1;

        int child = T->elem[LC] < T->elem[RC] ? LC : RC;

        while(child <= T->lastNdx && T->elem[child] < data) {
            T->elem[parent] = T->elem[child];

            parent = child;
            LC = parent * 2 + 1;
            RC = LC + 1;
            child = T->elem[LC] < T->elem[RC] ? LC : RC;
        }

        T->elem[parent] = data;
    }

    return temp;
}

void display(MinHeap T) {
    printf("TREE: ");
    for(int i = 0; i <= T.lastNdx; i++) {
        printf("%d ", T.elem[i]);
    }

    printf("\n");
}

MinHeap* insertAllMinHeap(MinHeap UnsortedTree) {
    MinHeap* result = (MinHeap*)malloc(sizeof(MinHeap));
    if (result != NULL) {
        init(result);

        for(int idx = 0; idx <= UnsortedTree.lastNdx; idx++) {
            insertMin(result, UnsortedTree.elem[idx]);
        }

        return result;
    }

    free(result);
    return NULL;
}

MinHeap* heapSort(MinHeap UnsortedTree) {
    MinHeap* result = (MinHeap*)malloc(sizeof(MinHeap));
    if (result != NULL) {
        init(result);

        MinHeap* SortedTree = insertAllMinHeap(UnsortedTree);

        int temp;
        int index = SortedTree->lastNdx;
        while ((temp = deleteMin(SortedTree)) != -1) {
            result->elem[index--] = temp;
            result->lastNdx++;
        }

        free(SortedTree);
        return result;
    }

    free(result);
    return NULL;
}