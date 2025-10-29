#ifndef CLOSED_HASHING_H
#define CLOSED_HASHING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10          // Maximum table size
#define EMPTY -999999   // Marker for empty slot
#define DELETED -1000000 // Marker for deleted slot

// Node structure for dictionary entries
typedef struct {
    int key;
    char value[50];
} nodetype;

typedef nodetype DICT[MAX]; // Dictionary type definition

// Function declarations
void mode();                             // Displays program mode
void init(DICT D);                       // Initializes dictionary
int hash(int key);                       // Hash function
void insertElem(DICT D, int key, char*); // Inserts key-value pair
void deleteElem(DICT D, int key);        // Deletes an element by key
char* getValue(DICT, int);               // Retrieves value by key
bool member(DICT D, int key);            // Checks if key exists
void visualize(DICT D);                  // Displays internal structure
void display(DICT D);                    // Displays all key-value pairs

#endif
