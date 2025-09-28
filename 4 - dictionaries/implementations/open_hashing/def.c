#include "header.h"

void mode() {
    printf("DICTIONARIES - OPEN HASHING\n");
    printf("===========================\n\n");
}

int hash(int data) {
    return data % 10;
}

void init(DICTIONARY D) {
    for(int idx = 0; idx < MAX; idx++) {
        D[idx] = NULL;
    }
}

void insert(DICTIONARY D, int data) {
    nodetype newNode = malloc(sizeof(struct node));

    if (newNode != NULL) {
        int hashValue = hash(data);

        newNode->data = data;
        newNode->link = D[hashValue];
        D[hashValue] = newNode;
    }
}

void delete(DICTIONARY D, int data) {
    nodetype *trav;
    for(trav = &(D[hash(data)]); *trav != NULL && (*trav)->data != data; trav = &((*trav)->link)) {}

    if (*trav != NULL) {
        nodetype temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

bool member(DICTIONARY D, int data) {
    nodetype trav;
    for(trav = D[hash(data)]; trav != NULL && trav->data != data; trav = trav->link) {}

    return (trav != NULL);
}

void visualize(DICTIONARY D) {
    for(int idx = 0; idx < MAX; idx++) {
        printf("[ %d ]", idx);
        
        for(nodetype trav = D[idx]; trav != NULL; trav = trav->link) {
            printf(" -> %d", trav->data);
        }

        printf("\n");
    }
    printf("\n");
}

void display(DICTIONARY D) {
    for(int idx = 0; idx < MAX; idx++) {
        for(nodetype trav = D[idx]; trav != NULL; trav = trav->link) {
            printf("%d, ", trav->data);
        }
    }
    printf("\n");
}