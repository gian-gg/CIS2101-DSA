#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MAX

#define MAX 5

typedef int MATRIX[MAX][MAX];

void init(MATRIX);
void insertEdge(MATRIX, int*);
void display(MATRIX);

int* dijkstra(MATRIX, int);

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

    int vertex = 2;
    int* D = dijkstra(m, vertex);
    printf("\nD[%d] = ", vertex);
    for(int i = 0; i < MAX; i++) {
        if (D[i] == INT_MAX) {
            printf("[i] ");
        } else {
            printf("[%d] ", D[i]);
        }
    }
    printf("\n");

    return 0;
}

int* dijkstra(MATRIX M, int vertex) {
    int* D = (int*)malloc(sizeof(int)*MAX);

    if (D) {
        int S[MAX] = {0}; // Visited set
        S[vertex] = 1;    // Mark start node as visited

        for(int i = 0; i < MAX; i++) D[i] = M[vertex][i]; // Initialize distances
        D[vertex] = 0;                                   // Distance to itself is 0

        // Loop to find shortest path for all nodes
        for(int i = 0; i < MAX; i++) {

            // --- Step 1: Find unvisited node with smallest distance ---
            int min = INT_MAX;
            int w = -1;

            for (int x = 0; x < MAX; x++) {
                if (!S[x] && D[x] < min) {
                    min = D[x];
                    w = x;
                }
            }

            if (w == -1) break; // Stop if no reachable nodes are left

            S[w] = 1; // Mark node as processed

            // --- Step 2: Update distances ---
            for (int v = 0; v < MAX; v++) {
                // Only update unvisited nodes connected to w
                if (!S[v] && M[w][v] != INT_MAX && D[w] != INT_MAX) {
                    int newPath = D[w] + M[w][v];
                    if (newPath < D[v]) {
                        D[v] = newPath;
                    }
                }
            }
        }

        return D;
    } else {
        printf("MALLOC FAILED!\n");
        return NULL;
    }
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
