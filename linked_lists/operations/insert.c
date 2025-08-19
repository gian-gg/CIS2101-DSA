#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

void init(LIST *HEAD) {
    *HEAD = NULL;
}
void display(char string[], LIST HEAD) {
    printf("%s", string);
    for(LIST curr = HEAD; curr != NULL; curr = curr->link) {
        printf("%d ", curr->data);
    }
    printf("\n");
}
LIST newNode(int data, struct node *link) {
    LIST temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("\nMALLOC FAILED!\n");
        return NULL;
    }

    temp->data = data;
    temp->link = link;

    return temp;
}
// inserts data at the end
void insert_end(LIST *HEAD, int data) {
    LIST *curr;
    for(curr = HEAD; (*curr) != NULL; curr = &(*curr)->link) {}
    *curr = newNode(data, NULL);
}
// inserts data at the start
void insert_start(LIST *HEAD, int data) {
    *HEAD = newNode(data, *HEAD);
}
// inserts data at the given index (starts from 0)
void insert(LIST *HEAD, int index, int data) {
    LIST *curr;
    int i = 0;
    for(curr = HEAD; ((*curr) != NULL) && (i < index); curr = &(*curr)->link, i++) {}
    *curr = newNode(data, *curr);
}
// intelligently insert new data ascendingly
void insert_sorted(LIST *HEAD, int data) {
    LIST *curr;
    for(curr = HEAD; (*curr)!=NULL && data > (*curr)->data;curr=&(*curr)->link) {}
    *curr = newNode(data, *curr);
}

int main() {
    LIST HEAD;
    init(&HEAD);

    insert_end(&HEAD, 200);
    insert_end(&HEAD, 30);
    insert_end(&HEAD, 500);
    insert_end(&HEAD, 2000);
    insert_end(&HEAD, 2000);
    insert_end(&HEAD, 2000);
    insert_end(&HEAD, 2000);
    insert_end(&HEAD, 2000);

    display("LIST: ", HEAD);

    insert(&HEAD, 1, 99);
    insert(&HEAD, 8, 88);

    display("LIST: ", HEAD);


    return 0;
}
