#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node {
    int data;
    struct node* next;
} *NODETYPE;

typedef NODETYPE LIST[MAX];

void init(LIST);
void insertEdge(LIST, int*);
void display(LIST);

int main() {
    LIST l;
    init(l);

    int edges[5][2] = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {3, 1}};
    int numOfEdges = sizeof(edges) / sizeof(edges[0]);

    for(int i = 0; i < numOfEdges; i++) {
        insertEdge(l, edges[i]);
    }

    display(l);


    return 0;
}

void init(LIST L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insertEdge(LIST L, int* edge) {
    NODETYPE newNode = (NODETYPE)malloc(sizeof(struct node));
    if(newNode) {
      newNode->data = edge[1];
      newNode->next = L[edge[0]];
      L[edge[0]] = newNode;
    } else {
        printf("MALLOC FAILED!\n");
        free(newNode);
    }
}

void display(LIST L) {
    for(int i = 0; i < MAX; i++) {
        printf("[ %d ] ", i);
        NODETYPE trav;
        for(trav = L[i]; trav != NULL; trav = trav->next) {
            printf("-> [%d] ", trav->data);
        }
        printf("\n");
    }
    printf("\n");
}
