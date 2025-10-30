#include "header.h"

void insertElemSortedUnique(SET* S, int elem) {
    SET* trav;
    for(trav = S; *trav != NULL && (*trav)->data != elem && (*trav)->data < elem; trav = &((*trav)->link)) {}

    if ((*trav) != NULL && (*trav)->data == elem) return;

    SET newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = elem;
        newNode->link = *trav;
        *trav = newNode;
    }
}

void mode() {
    printf("SETS - LINKED LIST IMPLEMENTATION (ORDERED)\n\n");
}

bool equal(SET A, SET B) {
    SET travA, travB;
    for(travA = A, travB = B;
        travA != NULL && travB != NULL &&
        travA->data == travB->data;
        travA = travA->link, travB = travB->link
        ) {}

    return (travA == NULL && travB == NULL);
}

SET Union(SET A, SET B) {
    SET C;
    init(&C);

    SET *travC, travA, travB;
    for (travA = A, travB = B, travC = &C;
         travA != NULL && travB != NULL;
        ) {
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode) {
            if (travA->data > travB->data) {
                newNode->data = travB->data;
                travB = travB->link;
            } else if (travA->data < travB->data) {
                newNode->data = travA->data;
                travA = travA->link;
            } else {
                newNode->data = travA->data;
                travA = travA->link;
                travB = travB->link;
            }

            newNode->link = NULL;
            *travC = newNode;
            travC = &((*travC)->link);
        }
    }

    for (SET travD = (travA == NULL) ? travB : travA;
         travD != NULL;
         travD = travD->link) {
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode) {
            newNode->data = travD->data;
            newNode->link = NULL;
            *travC = newNode;
            travC = &((*travC)->link);
        }
    }

    return C;
}



SET Intersection(SET A, SET B) {
    SET C;
    init(&C);

    for(SET travA = A; travA != NULL; travA = travA->link) {
        for(SET travB = B; travB != NULL; travB = travB->link) {
            if (travA->data == travB->data) {
                insertElemSortedUnique(&C, travA->data);
            }
        }
    }

    return C;
}

SET Difference(SET A, SET B) {
    SET C;
    init(&C);
    SET* travC = &C;

    for(SET travA = A; travA != NULL; travA = travA->link) {
        for(SET travB = A; travB != NULL; travB = travB->link) {
            if (travA->data != travB->data) {
                insertElemSortedUnique(&C, travA->data);
            }
        }
    }

    return C;
}
