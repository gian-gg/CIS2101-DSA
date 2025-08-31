#include <stdio.h>
#include <stdlib.h>

#define START_MAX 2

typedef struct {
    char *data;
    int count; // current number of elements
    int size; // current max
} ARRAY;

void init(ARRAY*);
void resize(ARRAY*);
void display(ARRAY);

void insertStart(ARRAY*, char);
void insertEnd(ARRAY*, char);
void insertAtPos(ARRAY*, char, int);

void deleteAtPos(ARRAY*, int);
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

    deleteAll(&list);

    display(list);


    return 0;
}


void init(ARRAY*list) {
    list->size = START_MAX;
    list->data = malloc(sizeof(char)*list->size);
    if (list->data != NULL) {
        list->count = 0;
    } else {
        printf("\nMALLOC FAILED\n");
    }
}

void resize(ARRAY *list) {
    // only realloc if necessary
    if (list->count >= list->size) {
        list->size *= 2;
        list->data = realloc(list->data, sizeof(char) * list->size);
        printf("\nNEW SIZE: %d\n", list->size);
        if (list->data == NULL) {
            printf("REALLOC FAILED\n");
            list->size /= 2;
            exit(1);
        }
    }
}

void display(ARRAY list) {
    if (list.count == 0) {
        printf("\nLIST EMPTY\n");
    } else {
        for(int i = 0; i < list.size;i++) {
            printf("%c ", list.data[i]);
        }
        printf("\n");
    }
}

void insertStart(ARRAY*list, char elem) {
    resize(list);

    for(int i = list->count; i > 0; i--) {
        list->data[i] = list->data[i-1];
    }
    list->data[0] = elem;
    list->count++;
}

void insertEnd(ARRAY*list, char elem) {
    resize(list);

    list->data[list->count] = elem;
    list->count++;
}


void insertAtPos(ARRAY*list, char elem, int pos) {
    resize(list);

    for(int i = list->count; i > pos; i--) {
        list->data[i] = list->data[i-1];
    }
    list->data[pos] = elem;
    list->count++;
}

void deleteAtPos(ARRAY*list, int pos) {
    for(int i = pos; i < list->count; i++) {
        list->data[i] = list->data[i+1];
    }
    list->count--;
}

void deleteAll(ARRAY*list) {
    free(list->data);
    list->count = 0;
    list->size = 0;
}
