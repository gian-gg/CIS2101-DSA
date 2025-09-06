#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct DataStructure *LIST;

void mode(); // displays mode

LIST init();
void display(LIST);

void push(LIST*, char);
char top(LIST);
void pop(LIST*);

bool empty(LIST);
bool full(LIST);
