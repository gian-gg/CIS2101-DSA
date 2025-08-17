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
void insert_end(LIST *HEAD, int data) {
    LIST *curr;
    for(curr = HEAD; (*curr) != NULL; curr = &(*curr)->link);

    LIST temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("\nMALLOC FAILED!\n");
        return;
    }

    temp->data = data;
    temp->link = NULL;

    *curr = temp;
}

void update(LIST *HEAD, int index, int data) {
    LIST *curr;
    int i = 0;
    for(curr = HEAD; (*curr)->link != NULL; curr = &(*curr)->link) {
        if (i++ > index-1) break;
    }

    (*curr)->data = data;
}

int main() {
    LIST HEAD;
    init(&HEAD);

    insert_end(&HEAD, 10);
    insert_end(&HEAD, 20);
    insert_end(&HEAD, 30);

    display("Before:\t", HEAD);

    update(&HEAD, 0, 11);
    update(&HEAD, 1, 22);
    update(&HEAD, 100, 44);

    display("After:\t", HEAD);

    return 0;
}
