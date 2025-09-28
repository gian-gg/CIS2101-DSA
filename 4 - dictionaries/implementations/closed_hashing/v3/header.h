#ifndef DICTS_H
#define DICTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define DICT_SIZE 10
#define OVERFLOW_SIZE 5
#define MAX DICT_SIZE+OVERFLOW_SIZE

typedef struct {
    int array[DICT_SIZE + OVERFLOW_SIZE];
    int last;
} DICTIONARY;

#define EMPTY   -1


void mode(); // for funsies

int hash(int); // returns the hash value of the given value
void init(DICTIONARY*); // initializes the DICTIONARY (makeNull)
void insert(DICTIONARY*, int); // inserts an element
void delete(DICTIONARY*, int); // deletes the given element
bool member(DICTIONARY, int); // returns true if an element is a member of the given DICTIONARY, otherwise false

void visualize(DICTIONARY); // visualize the elements
void display(DICTIONARY); // displays the elements side-by-side



#endif