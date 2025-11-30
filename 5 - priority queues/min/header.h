#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int heap[MAX];
    int count;
} MINHEAP;

void init(MINHEAP*);
void insert(MINHEAP*, int);
int deleteMin(MINHEAP*);
void heapify(MINHEAP*, int);

void heapSort(MINHEAP*);

void display(MINHEAP);


#endif
