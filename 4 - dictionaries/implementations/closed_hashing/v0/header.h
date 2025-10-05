// ================================
// DICTIONARIES - CLOSED HASHING v0
// ================================
// Using Linear Probing for Collision Resolution
// --------------------------------
// In this implementation, the dictionary is represented
// as a fixed-size array. Each index can hold one integer.
// When a collision occurs (two data values map to the same
// hash index), linear probing is used to find the next
// available slot in the array.
// ================================


#ifndef DICTS_H
#define DICTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int DICTIONARY[MAX];

#define EMPTY   -1  // Slot is unused
#define DELETED -2  // Slot was used before but the value was deleted

void mode();                    // for funsies
int hash(int);                  // Returns hash value for a given key
void init(DICTIONARY);          // Initializes dictionary to all EMPTY
void insert(DICTIONARY, int);   // Inserts data using linear probing
void delete(DICTIONARY, int);   // Deletes data (marks slot as DELETED)
bool member(DICTIONARY, int);   // Checks if a data value exists

void visualize(DICTIONARY);     // Displays table contents line by line
void display(DICTIONARY);       // Displays valid entries side-by-side

#endif
