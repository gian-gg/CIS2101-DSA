#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *BST;


void init(BST*);
void insert(BST*,int);
void delete(BST*,int);

void visualize(BST);

#endif
