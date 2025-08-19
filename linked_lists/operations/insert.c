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
    for(curr = HEAD; (*curr) != NULL; curr = &(*curr)->link);
    LIST temp = newNode(data, NULL);
    *curr = temp;
}
// inserts data at the start
void insert_start(LIST *HEAD, int data) {
    LIST temp = newNode(data, *HEAD);
    *HEAD = temp;
}
// inserts data at the given index
void insert(LIST *HEAD, int index, int data) {
    LIST *curr;
    int i = 0;
    for(curr = HEAD; (*curr) != NULL; curr = &(*curr)->link) {
        if (i++ > index-1) break;
    }

    LIST temp = newNode(data, *curr);
    *curr = temp;
}
// intelligently insert new data
void insert_sorted(LIST *HEAD, int data) {
    LIST *curr;
    for(curr = HEAD; (*curr)!=NULL && data > (*curr)->data;curr=&(*curr)->link);

    LIST temp = newNode(data, *curr);
    *curr = temp;
}

int main() {
    LIST HEAD;
    init(&HEAD);

    insert_sorted(&HEAD, 200);
    insert_sorted(&HEAD, 30);
    insert_sorted(&HEAD, 10);
    insert_sorted(&HEAD, 1000);
    insert_sorted(&HEAD, 40);
    insert_sorted(&HEAD, 20);
    insert_sorted(&HEAD, 100);

    display("LIST: ", HEAD);

    return 0;
}
