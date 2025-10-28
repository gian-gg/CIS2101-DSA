#include <stdio.h>

#define EMPTY -1
#define SIZE 10


typedef struct {
    int elems[SIZE];
    int count;
} MINHEAP;

void init(MINHEAP*);
void display(MINHEAP);

void insert(MINHEAP*,int);
int deleteMin(MINHEAP*);

int main() {
    MINHEAP minTree;
    init(&minTree);

    insert(&minTree, 40);
    insert(&minTree, 10);
    insert(&minTree, 30);
    insert(&minTree, 1);
    insert(&minTree, 100);
    insert(&minTree, 20);

    display(minTree);

    deleteMin(&minTree);
    display(minTree);

    return 0;
}

void init(MINHEAP* T) {
    T->count = EMPTY;
}

void display(MINHEAP T) {
    int size = T.count;
    for(int idx = 0; idx <= size; idx++) {
        printf("%d ", T.elems[idx]);
    }
    printf("\n");
}

void insert(MINHEAP* T, int data) {
    if (T->count + 1 < SIZE) {
        int child = ++(T->count);
        int parent = (child-1)/2;
        
        while(child > 0 && T->elems[parent] > data) {
            T->elems[child] = T->elems[parent];
            
            child = parent;
            parent = (child-1)/2;
        }
        
        T->elems[child] = data;
    }
}


int deleteMin(MINHEAP* T) {
    int min = -100;
    
    if (T->count > EMPTY) {
        min = T->elems[0];
        int data = T->elems[(T->count)--];
        
        int parent = 0;
        int LC = parent*2 +1;
        int RC = LC+1;
        int SC = (T->elems[LC] < T->elems[RC]) ? LC : RC;
        
        while(SC <= T->count && T->elems[SC] < data) {
            T->elems[parent] = T->elems[SC];
            
            parent = SC;
            LC = parent*2 +1;
            RC = LC+1;
            SC = (T->elems[LC] < T->elems[RC]) ? LC : RC;
        }
        
        T->elems[parent] = data;
    }
    
    return min;
}