#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
} *LIST;

void init(LIST*);
void display(char[], LIST);
void insertLast(LIST*, char);

bool findElem(LIST*, char);
void deleteElem(LIST*, char);
void deleteAllOccur(LIST*, char);

int main() {
    LIST HEAD;
    init(&HEAD);


    insertLast(&HEAD, 'I');
    insertLast(&HEAD, 'T');
    insertLast(&HEAD, 'I');
    insertLast(&HEAD, 'R');
    insertLast(&HEAD, 'A');
    insertLast(&HEAD, 'I');


    display("BEFORE: ", HEAD);

    deleteAllOccur(&HEAD, 'I');

    display("AFTER: ", HEAD);

    printf("\n");
    return 0;
}

void init(LIST* HEAD) {
    *HEAD = NULL;
}
void display(char string[], LIST HEAD) {
    if (HEAD == NULL) {
        printf("\nList is Empty!\n");
        return;
    }

    printf("%s", string);

    for(LIST curr = HEAD; curr!=NULL; curr=curr->link) {
        printf("%c", curr->elem);
    }

    printf("\n");
}
void insertLast(LIST *HEAD, char elem) {
    LIST *curr;
    for(curr = HEAD; *curr!=NULL; curr=&(*curr)->link);

    LIST newNode = malloc(sizeof(struct node));
    newNode->elem = elem;
    newNode->link = NULL;
    *curr = newNode;
}

bool findElem(LIST* HEAD, char elem) {
    LIST *curr;
    for(curr=HEAD; *curr!=NULL && elem != (*curr)->elem; curr=&(*curr)->link);
    return (*curr != NULL) ? true : false;
}

void deleteElem(LIST *HEAD, char elem) {
    LIST *curr;
    for(curr=HEAD; *curr!=NULL && elem != (*curr)->elem; curr = &(*curr)->link);

    if (*curr != NULL) {
        LIST temp = *curr;
        *curr = temp->link;
        free(temp);
    }
}

void deleteAllOccur(LIST *HEAD, char elem) {
    LIST *curr=HEAD;
    while(*curr!=NULL) {
        if (elem == (*curr)->elem) {
            LIST temp = *curr;
            *curr = temp->link;
            free(temp);
        } else {
            curr = &(*curr)->link;
        }
    }
}
