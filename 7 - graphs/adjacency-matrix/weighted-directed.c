#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MAX

#define MAX 5

typedef int MATRIX[MAX][MAX];

void init(MATRIX);
void insertEdge(MATRIX, int*);
void display(MATRIX);

int main() {
    MATRIX m;
    init(m);

    // edges[][0] -> edges[][1], edges[][3] is the weight
    int edges[][3] = {{0, 1, 10}, {0, 3, 30}, {0, 4, 100}, {1, 2, 50}, {2, 0, 20}, {2, 4, 10}, {3, 2, 20}, {3, 4, 60}};
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
            M[row][col] = INT_MAX;
        }
    }
}

void display(MATRIX M) {
    printf("[ ] | ");
    for(int i = 0; i < MAX; i ++) {
        printf("[%3d] ", i);
    }
    printf("\n");
    for(int i = 0; i < MAX; i ++) {
        printf("-------");
    }
    printf("\n");
    for(int row = 0; row < MAX; row++) {
        printf("[%d] | ",  row);
        for(int col = 0; col < MAX; col++) {
            if (M[row][col] == INT_MAX)
                printf("[  i] ");
            else
                printf("[%3d] ", M[row][col]);
        }
        printf("\n");
    }
}

void insertEdge(MATRIX M, int* edge) {
    M[edge[0]][edge[1]] = edge[2];
}
