#include "header.h"

void init(SET* S) {
    // An empty set is represented by a NULL head pointer.
    *S = NULL;
}

void insertElem(SET* S, int elem) {
    // Traverse to find the element (duplicate) or the end of the list.
    SET* trav;
    for(trav = S; *trav != NULL && (*trav)->data != elem; trav = &((*trav)->link)) {}

    // If no duplicate was found (loop reached the end), *trav will be NULL.
    if (*trav == NULL) {
        SET newNode = malloc(sizeof(struct node));

        if (newNode != NULL) { // Check if malloc succeeded
            newNode->data = elem;
            newNode->link = NULL;
            *trav = newNode;
        }
    }
}

void deleteElem(SET* S, int elem) {
    SET* trav;
    for(trav=S; (*trav) != NULL && (*trav)->data != elem; trav = &((*trav)->link)) {}

    // If the element was found...
    if ((*trav) != NULL) {
        SET temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void read(SET S) {
    printf("{ ");
    for(SET trav = S; trav != NULL; trav = trav->link) {
        printf("%d, ", trav->data);
    }
    printf("}\n");
}

bool isFull(SET S) {
    // Tries to "peek" if the heap has memory.
    SET temp = (SET)malloc(sizeof(struct node));

    if (temp == NULL) {
        // Malloc failed, so we consider the heap "full".
        return true;
    }

    // Malloc succeeded, so free the test node and return false.
    free(temp);
    return false;
}

bool isEmpty(SET S) {
    // An empty set's head pointer is NULL.
    return (S == NULL);
}

bool member(SET S, int elem) {
    SET trav;
    for(trav = S; trav != NULL && trav->data != elem; trav = trav->link) {}

    // If trav is not NULL, the element was found.
    return (trav != NULL);
}
