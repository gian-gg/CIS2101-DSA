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
    if (temp == NULL) {
        printf("\nMALLOC FAILED!\n");
        return;
    }

    temp->data = data;
    temp->link = NULL;

    (*curr) = temp;
}

void delete(LIST *HEAD, int index) {
    LIST *curr;
    int i = 0;
    for(curr=HEAD; (*curr)!=NULL && (i > index-1); curr=&(*curr)->link,i++);

    LIST temp = *curr;
    (*curr) = (*curr)->link;

    free(temp);
}

void delete_all(LIST *HEAD) {
    LIST *curr = HEAD;
    while((*curr)!=NULL) {
        LIST temp = *curr;
        curr=&(*curr)->link;

        free(temp);
    }

    init(HEAD);
}

void deleteElem(LIST *HEAD, int elem) {
    LIST *curr;
    for(curr = HEAD; (*curr) != NULL && (*curr)->data != elem; curr = &(*curr)->link);

    if ((*curr) != NULL) {
        LIST temp = *curr;
        (*curr) = (*curr)->link;

        free(temp);
    }
}

void deleteAllOccur(LIST *HEAD, int elem) {
    LIST *curr = HEAD;
    while((*curr) != NULL) {
        if ((*curr)->data == elem) {
            LIST temp = *curr;
            (*curr) = (*curr)->link;
            free(temp);
        } else {
            curr = &(*curr)->link;
        }
    }
}

int main() {
    LIST HEAD;
    init(&HEAD);

    insert_end(&HEAD, 10);
    insert_end(&HEAD, 50);
    insert_end(&HEAD, 50);
    insert_end(&HEAD, 30);
    insert_end(&HEAD, 40);
    insert_end(&HEAD, 50);
    insert_end(&HEAD, 50);
    insert_end(&HEAD, 50);


    display("LIST:\t", HEAD);

    deleteAllOccur(&HEAD, 50);

    display("LIST:\t", HEAD);

    return 0;
}
