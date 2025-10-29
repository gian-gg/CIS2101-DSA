#ifndef SETS_H
#define SETS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
    int data;
    int link;
} nodetype;

typedef struct {
    nodetype nodes[MAX];
    int avail;
} VirtualHeap;

typedef int SET;

void mode(); // for funsies

void initVH(VirtualHeap*);
int alloc(VirtualHeap*);
void dealloc(VirtualHeap*, int);

void init(SET*); // initializes the SET
void insertElem(VirtualHeap*, SET*, int); // inserts an element at the end
void deleteElem(VirtualHeap*, SET*, int); // deletes the given element
void read(VirtualHeap, SET); // displays all the elements

bool isFull(VirtualHeap); // returns true if given set is Full, otherwise false
bool isEmpty(SET); // returns true if given set is Empty, otherwise false
bool member(VirtualHeap, SET, int); // returns the index of the given elem, otherwise -1
bool equal(VirtualHeap, SET, SET); // returns true if two given sets are equal, otherwise false

SET Union(VirtualHeap*, SET, SET); // creates a new set that combines all elements from two given sets
SET Intersection(VirtualHeap*, SET, SET); // creates a new set that contains the common elements from two given sets
SET Difference(VirtualHeap*, SET, SET); // creates a new set that contains all elements that is in a set but not the other set, not commutative


#endif
