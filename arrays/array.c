#include <stdio.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int count;
} ARRAY;

void init(ARRAY*);
void display(ARRAY);

void insertStart(ARRAY*,char);
void insertEnd(ARRAY*,char);
void insertAtPos(ARRAY*,char);

void deleteAtPos(ARRAY*,int);
void deleteAll(ARRAY*);

int main() {
    ARRAY list;
    init(&list);

    insertStart(&list, 'a');
    insertStart(&list, 'b');
    insertStart(&list, 'c');

    display(list);

    return 0;
}

void init(ARRAY *list) {
    list->count = 0;
}

void display(ARRAY list) {
    // treat as a reusable function, not just for strings.
    for(int i = 0; i < list.count; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

void insertStart(ARRAY *list, char elem) {
    int i;
    for(i = 0; i < list->count; i++) {
        list->data[i] = list->data[i+1];
    }
    list->data[0] = elem;
    list->count++;
}
