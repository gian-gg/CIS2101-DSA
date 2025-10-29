#ifndef SETS_H
#define SETS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *link;
} *SET;

void mode(); // for funsies

void init(SET*); // initializes the SET
void insertElem(SET*, int); // inserts an element at the end
void deleteElem(SET*, int); // deletes the given element
void read(SET); // displays all the elements

bool isFull(SET); // returns true if given set is Full, otherwise false
bool isEmpty(SET); // returns true if given set is Empty, otherwise false
bool member(SET, int); // returns the index of the given elem, otherwise -1
bool equal(SET, SET); // returns true if two given sets are equal, otherwise false

SET Union(SET, SET); // creates a new set that combines all elements from two given sets
SET Intersection(SET, SET); // creates a new set that contains the common elements from two given sets
SET Difference(SET, SET); // creates a new set that contains all elements that is in a set but not the other set, not commutative


#endif
