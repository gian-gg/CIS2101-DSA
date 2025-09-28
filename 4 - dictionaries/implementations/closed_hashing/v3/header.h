#ifndef DICTS_H
#define DICTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* link;
} *nodetype;

typedef nodetype DICTIONARY[MAX];


void mode(); // for funsies

int hash(int); // returns the hash value of the given value
void init(DICTIONARY); // initializes the DICTIONARY (makeNull)
void insert(DICTIONARY, int); // inserts an element
void delete(DICTIONARY, int); // deletes the given element
bool member(DICTIONARY, int); // returns true if an element is a member of the given DICTIONARY, otherwise false

void visualize(DICTIONARY); // visualize the elements
void display(DICTIONARY); // displays the elements side-by-side



#endif