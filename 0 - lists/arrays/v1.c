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
void insertAtPos(ARRAY*,char,int);

void deleteAtPos(ARRAY*,int);
void deleteAll(ARRAY*);

int main() {
    ARRAY list;
    init(&list);

    insertEnd(&list, 'a');
    insertEnd(&list, 'b');
    insertEnd(&list, 'c');
    insertEnd(&list, 'd');
    insertEnd(&list, 'e');

    display(list);

    deleteAll(&list);

    display(list);

    return 0;
}

void init(ARRAY *list) {
    list->count = 0;
}

void display(ARRAY list) {
    if (list.count == 0) {
        printf("\nEmpty List\n");
    } else {
        // treat as a reusable function, not just for strings, hence not using printf %s.
        for(int i = 0; i < list.count; i++) {
            printf("%c ", list.data[i]);
        }
        printf("\n");
    }
}

void insertStart(ARRAY *list, char elem) {
    for(int i = list->count; i > 0; i--) {
        list->data[i] = list->data[i-1];
    }

    list->data[0] = elem;
    list->count++;
}

void insertEnd(ARRAY *list, char elem) {
    list->data[list->count] = elem;
    list->count++;
}

void insertAtPos(ARRAY*list,char elem,int pos) {
    for(int i = list->count; i > pos; i--) {
        list->data[i] = list->data[i-1];
    }
    list->data[pos] = elem;
    list->count++;
}

void deleteAtPos(ARRAY*list,int pos) {
    list->count--;
    for(int i = pos; i < list->count; i++) {
        list->data[i] = list->data[i+1];
    }
}

void deleteAll(ARRAY* list) {
    init(list);
}
