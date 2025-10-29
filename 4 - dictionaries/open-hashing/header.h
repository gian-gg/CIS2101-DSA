// ================================
// OPEN HASHING (SEPARATE CHAINING) WITH KEY-VALUE PAIRS
// --------------------------------
// Each bucket stores a linked list of key-value pairs.
// Useful for dictionary-style mappings.
// ================================

#ifndef DICTS_H
#define DICTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10
#define VALUE_SIZE 50

typedef struct node {
    int key;                     // Key
    char value[VALUE_SIZE];      // Value associated with the key
    struct node* link;           // Next node in the chain
} *nodetype;

typedef nodetype DICT[MAX];

// Function declarations
void mode();
int hash(int);
void init(DICT);
void insertElem(DICT, int, char*);             // Inserts or updates key-value pair
void deleteElem(DICT, int);                    // Deletes key-value pair
bool member(DICT, int);                        // Checks if key exists
char* getValue(DICT, int);                     // Gets value by key
void visualize(DICT);
void display(DICT);

#endif
