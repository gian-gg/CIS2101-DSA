#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int count;
} *ARRAY, ArrayList;

void init(ARRAY*);
void display(ARRAY);

void insertStart(ARRAY*,char);
void insertEnd(ARRAY*,char);
void insertAtPos(ARRAY*,char,int);

void deleteAtPos(ARRAY*,int);
void deleteAll(ARRAY*);

int main() {
    ARRAY list;
    init(&list);

    insertStart(&list, 'A');
    insertStart(&list, 'B');
    insertStart(&list, 'C');

    insertEnd(&list, 'G');

    display(list);

    deleteAtPos(&list, 2);

    display(list);

    return 0;
}

void init(ARRAY *list) {
    *list = malloc(sizeof(ArrayList));
    if (*list != NULL) {
        (*list)->count = 0;
    } else {
        printf("\nMALLOC FAILED\n");
    }
}

void display(ARRAY list) {
    for(int i = 0; i < list->count; i++) {
        printf("%c ", list->data[i]);
    }
    printf("\n");
}


void insertStart(ARRAY* list,char elem) {
    for(int i = (*list)->count; i > 0; i--) {
        (*list)->data[i] = (*list)->data[i-1];
    }
    (*list)->data[0] = elem;
    (*list)->count++;
}

void insertEnd(ARRAY*list, char elem) {
    (*list)->data[(*list)->count] = elem;
    (*list)->count++;
}


void insertAtPos(ARRAY* list,char elem, int pos) {
    for(int i = (*list)->count; i > pos; i--) {
        (*list)->data[i] = (*list)->data[i-1];
    }
    (*list)->data[pos] = elem;
    (*list)->count++;
}


void deleteAtPos(ARRAY* list, int pos) {
    for(int i = pos; i < (*list)->count; i++) {
        (*list)->data[i] = (*list)->data[i+1];
    }
    (*list)->count--;
}

void deleteAll(ARRAY *list) {
    free(*list);
}
