#include "./header.h"

void mode() {
    printf("DICT - OPEN HASHING\n\n");
}

// Hash function: returns index within table size
int hash(int key) {
    return abs(key) % MAX;
}

// Initialize dictionary (set all buckets to NULL)
void init(DICT D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

// Insert key-value pair into dictionary
void insertElem(DICT D, int key, char* value) {
    nodetype* trav;

    // Traverse to end of the chain at hashed index
    for (trav = &D[hash(key)]; *trav != NULL; trav = &((*trav)->link)) {}

    // Allocate new node and assign key-value
    nodetype newNode = (nodetype)malloc(sizeof(struct node));
    if (newNode) {
        newNode->key = key;
        strcpy(newNode->value, value);
        newNode->link = NULL;
        *trav = newNode; // attach node at the end
    }
}

// Delete node with specific key
void deleteElem(DICT D, int key) {
    nodetype* trav;

    // Traverse until key is found or chain ends
    for (trav = &D[hash(key)]; *trav != NULL && (*trav)->key != key; trav = &((*trav)->link)) {}

    // If found, remove and free the node
    if (*trav != NULL) {
        nodetype temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

// Check if a key exists in the dictionary
bool member(DICT D, int key) {
    nodetype trav;

    for (trav = D[hash(key)]; trav != NULL && trav->key != key; trav = trav->link) {}

    return (trav != NULL);
}

// Retrieve value for a given key
char* getValue(DICT D, int key) {
    nodetype trav;

    for (trav = D[hash(key)]; trav != NULL && trav->key != key; trav = trav->link) {}

    return (trav != NULL) ? trav->value : NULL;
}

// Display internal structure (per hash bucket)
void visualize(DICT D) {
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        printf("[] -> [ ");
        for (nodetype trav = D[i]; trav != NULL; trav = trav->link) {
            printf("{ %d: \"%s\" }, ", trav->key, trav->value);
        }
        printf("]\n");
    }
    printf("\n");
}

// Display all key-value pairs (flat view)
void display(DICT D) {
    printf("[\n");
    for (int i = 0; i < MAX; i++) {
        for (nodetype trav = D[i]; trav != NULL; trav = trav->link) {
            printf("    { %d: \"%s\" },\n", trav->key, trav->value);
        }
    }
    printf("]\n");
}
