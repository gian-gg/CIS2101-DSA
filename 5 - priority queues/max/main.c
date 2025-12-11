#include <stdio.h>

#define MAX 10

typedef struct {
    int heap[MAX];
    int count;
} MAXHEAP;

void init(MAXHEAP*);
void insert(MAXHEAP*,int);
int deleteMax(MAXHEAP*);
void display(MAXHEAP);

void heapify(MAXHEAP*,int);
void heapsort(MAXHEAP*);

int main() {
    MAXHEAP M;
    init(&M);

    insert(&M, 10);
    insert(&M, 20);
    insert(&M, 5);
    insert(&M, 30);
    insert(&M, 15);

    display(M);

    printf("deleteMax: %d\n", deleteMax(&M));
    display(M);

    heapsort(&M);
    display(M);


    return 0;
}

void init(MAXHEAP* M) {
    M->count = -1;
}

void insert(MAXHEAP* M, int key) {
    if ((M->count + 1) >= MAX) return;

    int child = ++(M->count);
    int parent = (child-1)/2;

    while(child > 0 && key > M->heap[parent]) {
        M->heap[child] = M->heap[parent];

        child = parent;
        parent = (child-1)/2;
    }

    M->heap[child] = key;
}

void heapify(MAXHEAP* M, int root) {
    while (1) {
        int largest = root;
        int LC = 2 * root + 1;
        int RC = 2 * root + 2;

        if (LC <= M->count && M->heap[LC] > M->heap[largest]) {
            largest = LC;
        }

        if (RC <= M->count && M->heap[RC] > M->heap[largest]) {
            largest = RC;
        }

        if (largest != root) {
            int temp = M->heap[root];
            M->heap[root] = M->heap[largest];
            M->heap[largest] = temp;

            root = largest;
        } else {
            break;
        }
    }
}

int deleteMax(MAXHEAP* M) {
    int max = -1;
    if (M->count > max) {
        int root = 0;
        max = M->heap[root];
        M->heap[root] = M->heap[(M->count)--];

        heapify(M, root);
    }

    return max;
}

void heapsort(MAXHEAP* M) {
    for(int i = (M->count-1)/2; i >= 0; i--) {
        heapify(M, i);
    }

    int ogCount = M->count;
    while(M->count >= 0) {
        int temp = M->heap[0];
        M->heap[0] = M->heap[M->count];
        M->heap[M->count] = temp;

        M->count--;

        heapify(M, 0);
    }
    M->count = ogCount;
}

void display(MAXHEAP M) {
    for(int i = 0; i <= M.count; i++) {
        printf("%d ", M.heap[i]);
    }
    printf("\n");
}
