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

// inserts data at the end
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

// inserts data at the start
void insert_start(LIST *HEAD, int data) {
    LIST temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("\nMALLOC FAILED!\n");
        return;
    }
    
    temp->data = data;
    temp->link = *HEAD;
    
    *HEAD = temp;
}

// inserts data at the given index
void insert(LIST *HEAD, int index, int data) {
    LIST *curr;
    int i = 0;
    for(curr = HEAD; (*curr) != NULL; curr = &(*curr)->link) {
        if (i++ > index-1) break;
    }
    
    LIST temp = malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("\nMALLOC FAILED!\n");
        return;
    }
    
    temp->data = data;
    temp->link = *curr;
    
    *curr = temp;
}

int main() {
    LIST HEAD;
    init(&HEAD);
    
    insert_start(&HEAD, 10);
    insert_start(&HEAD, 20);
    insert_start(&HEAD, 30);
    insert_start(&HEAD, 40);
    
    display("LIST: ", HEAD);
    
    insert(&HEAD, 3, 99);
    
    display("LIST: ", HEAD);
    
    return 0;
}