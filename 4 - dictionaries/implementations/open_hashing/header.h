// ================================
// OPEN HASHING (SEPARATE CHAINING)
// --------------------------------
// This implementation uses an array of linked lists
// to store data. Each array index represents a "bucket."
// When multiple elements map to the same hash index,
// they form a linked list (chain) at that position.
// ================================


#ifndef DICTS_H
#define DICTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node {
    int data;              // Value being stored
    struct node* link;     // Pointer to next node in chain
} *nodetype;

typedef nodetype DICTIONARY[MAX];

void mode();                     // for funsies
int hash(int);                   // Hash function (returns index)
void init(DICTIONARY);           // Initializes dictionary
void insert(DICTIONARY, int);    // Inserts an element
void delete(DICTIONARY, int);    // Deletes a specific element
bool member(DICTIONARY, int);    // Checks if element exists
void visualize(DICTIONARY);      // Prints the dictionary structure
void display(DICTIONARY);        // Displays all stored elements

#endif
