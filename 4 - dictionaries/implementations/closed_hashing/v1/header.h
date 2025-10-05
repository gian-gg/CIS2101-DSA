// ================================
// CLOSED HASHING with OVERFLOW AREA
// --------------------------------
// This version uses a primary hash table (DICT_SIZE)
// and a separate overflow area (OVERFLOW_SIZE).
// When a collision occurs, the new element is stored
// in the overflow area rather than probing linearly.
// ================================


#ifndef DICTS_H
#define DICTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DICT_SIZE 10        // Main hash area size
#define OVERFLOW_SIZE 5     // Overflow area size
#define MAX DICT_SIZE + OVERFLOW_SIZE 

typedef struct {
    int array[DICT_SIZE + OVERFLOW_SIZE]; // Combined array for hash + overflow
    int last;                             // Index of the last element in overflow
} DICTIONARY;

#define EMPTY -1  // Marks an empty slot

void mode();                   // for funsies
int hash(int);                 // Hash function (mod DICT_SIZE)
void init(DICTIONARY*);        // Initializes dictionary (sets EMPTY)
void insert(DICTIONARY*, int); // Inserts element into hash or overflow area
void delete(DICTIONARY*, int); // Deletes element
bool member(DICTIONARY, int);  // Checks membership
void visualize(DICTIONARY);    // Prints the full structure
void display(DICTIONARY);      // Displays all stored elements

#endif
