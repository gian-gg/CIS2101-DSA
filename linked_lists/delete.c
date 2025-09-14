#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

void init(LIST*);
void display(char[], LIST);
void insertEnd(LIST*,int);

void delete(LIST*, int);
void deleteElem(LIST*, int);
void deleteAllOccur(LIST*, int);
void deleteAll(LIST*);

int main() {
    LIST HEAD;
    init(&HEAD);

    insertEnd(&HEAD, 50);
    insertEnd(&HEAD, 10);
    insertEnd(&HEAD, 50);
    insertEnd(&HEAD, 20);
    insertEnd(&HEAD, 30);
    insertEnd(&HEAD, 40);
    insertEnd(&HEAD, 50);
    insertEnd(&HEAD, 50);

    display("Before:\t", HEAD);

    deleteAllOccur(&HEAD, 50);

    display("After:\t", HEAD);

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
    for(LIST curr = HEAD; curr!=NULL; curr=curr->link) printf("%d ", curr->data);
    printf("\n");
}

void insertEnd(LIST* HEAD,int data) {
    LIST *curr;
    for(curr = HEAD; (*curr)!=NULL; curr = &(*curr)->link);

    LIST newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = NULL;
        *curr = newNode;
    } else {
        printf("MALLOC FAILED!");
    }
}

void delete(LIST* HEAD, int index) {
    LIST *curr;
    int i = 0;
    for(curr = HEAD; (*curr)!=NULL && i < index; curr = &(*curr)->link, i++);

    if (*curr!=NULL) {
        LIST temp = *curr;
        *curr = temp->link;
        free(temp);
    }
}

void deleteAll(LIST* HEAD) {
    LIST curr = *HEAD;
    while(curr!=NULL) {
        LIST temp = curr;
        curr = curr->link;
        free(temp);
    }

    init(HEAD);
}

void deleteElem(LIST* HEAD, int elem) {
    LIST *curr;
    for(curr = HEAD; *curr!=NULL && elem != (*curr)->data; curr=&(*curr)->link);

    if (*curr!=NULL) {
        LIST temp = *curr;
        *curr = temp->link;
        free(temp);
    }
}

void deleteAllOccur(LIST* HEAD, int elem) {
    LIST *curr = HEAD;
    while(*curr!=NULL) {
        if (elem == (*curr)->data) {
            LIST temp = *curr;
            *curr = temp->link;
            free(temp);
        } else {
            curr = &(*curr)->link;
        }
    }
}
