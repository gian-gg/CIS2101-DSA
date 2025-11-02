#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

typedef struct {
    int elems[SIZE];
    int count;
} MAXHEAP;

void init(MAXHEAP*);
void display(MAXHEAP);
void insert(MAXHEAP*, int);
int deleteMax(MAXHEAP*);

MAXHEAP* insertAll(MAXHEAP);
MAXHEAP* heapSort(MAXHEAP T);

#endif
