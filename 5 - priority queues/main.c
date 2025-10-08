#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX  10

typedef struct {
  int elem[MAX];
  int lastNdx;
} Tree;

void init(Tree *T);
void insert(Tree *T, int data);
int deleteMin(Tree *T);
void display(Tree T);


int main() {
    Tree T;
    init(&T);

    insert(&T, 40);
    insert(&T, 20);
    insert(&T, 50);
    insert(&T, 20);
    insert(&T, 10);

    display(T);

    return 0;
}

void init(Tree *T) {
    T->lastNdx = -1;
}

void insert(Tree *T, int data) {
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

int deleteMin(Tree *T) {
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

void display(Tree T) {
    printf("ARRAY: ");
    for(int i = 0; i <= T.lastNdx; i++) {
        printf("%d ", T.elem[i]);
    }

    printf("\nTREE: ");
    int temp;
    while((temp = deleteMin(&T)) != -1) {
        printf("%d ", temp);
    }
    printf("\n");
}