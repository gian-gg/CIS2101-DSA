#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef int MATRIX[MAX][MAX];

void init(MATRIX);
void insertEdge(MATRIX, int*);
void display(MATRIX);

int main() {
    MATRIX m;
    init(m);

    int edges[5][2] = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {3, 1}};
    int numOfEdges = sizeof(edges) / sizeof(edges[0]);

    for(int i = 0; i < numOfEdges; i++) {
        insertEdge(m, edges[i]);
    }

    display(m);


    return 0;
}

void init(MATRIX M) {
    for(int row = 0; row < MAX; row++) {
        for(int col = 0; col < MAX; col++) {
            M[row][col] = 0;
        }
    }
}

void display(MATRIX M) {
    printf("[ ] | ");
    for(int i = 0; i < MAX; i ++) {
        printf("[%d] ", i);
    }
    printf("\n");
    for(int i = 0; i < MAX; i ++) {
        printf("-----");
    }
    printf("\n");
    for(int row = 0; row < MAX; row++) {
        printf("[%d] | ",  row);
        for(int col = 0; col < MAX; col++) {
            printf("[%d] ", M[row][col]);
        }
        printf("\n");
    }
}

void insertEdge(MATRIX M, int* edge) {
    M[edge[0]][edge[1]] = 1;
    M[edge[1]][edge[0]] = 1;
}
