#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

typedef struct {
    int elems[SIZE];
    int count;
} MINHEAP;

void init(MINHEAP*);
void display(MINHEAP);
void insert(MINHEAP*, int);
int deleteMin(MINHEAP*);

MINHEAP* insertAll(MINHEAP);
MINHEAP* heapSort(MINHEAP T);

#endif
