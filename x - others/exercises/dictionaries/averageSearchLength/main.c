#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef char DICTIONARY[MAX];

#define EMPTY   -1
#define DELETED -2


int hash(char); // returns the hash value of the given value
void init(DICTIONARY); // initializes the DICTIONARY (makeNull)
int insert(DICTIONARY, char); // inserts an element
void visualize(DICTIONARY); // visualize the elements

int searchLength(int hashVal, int actualLoc) {
    return ((actualLoc - hashVal + MAX) % MAX) + 1;
}

int main() {
    DICTIONARY D;
    init(D);

    char elements[] = {'A','B','C','D','E','F','G','H'};
    int n = sizeof(elements) / sizeof(elements[0]);
    int totalSL = 0;

    printf("Insertion and Search Lengths:\n");
    for (int i = 0; i < n; i++) {
        char elem = elements[i];
        int hv = hash(elem);
        int loc = insert(D, elem);
        int SL = searchLength(hv, loc);
        printf("Element %c → Hash=%d, Location=%d, SL=%d\n", elem, hv, loc, SL);
        totalSL += SL;
    }

    double avgSL = (double) totalSL / n;
    printf("\nAverage Search Length = %.3f\n\n", avgSL);

    printf("Final Dictionary State:\n");
    visualize(D);

    return 0;
}

int hash(char data) {
    switch(data) {
        case 'A': return 1;
        case 'B': return 4;
        case 'C': return 9;
        case 'D': return 9;
        case 'E': return 0;
        case 'F': return 3;
        case 'G': return 4;
        case 'H': return 3;
        default: return -1;
    }
}

void init(DICTIONARY D) {
    for(int idx = 0; idx < MAX; idx++) {
        D[idx] = EMPTY;
    }
}

int insert(DICTIONARY D, char data) {
    int hashValue = hash(data);

    int idx, trav;
    for (idx = 0, trav = hashValue; idx < MAX && D[trav] != EMPTY && D[trav] != DELETED; idx++, trav = (hashValue + idx) % MAX) {}

    if (idx < MAX) {
        D[trav] = data;
        return trav;
    } else {
        printf("Hash table full! Cannot insert %c\n", data);
        return -1;
    }
}

void visualize(DICTIONARY D) {
    for (int idx = 0; idx < MAX; idx++) {
        char currElem = D[idx];
        
        if (currElem == EMPTY) {
            printf("[ %3s ]\n", "EMP");
        } else if (currElem == DELETED) {
            printf("[ %3s ]\n", "DEL");
        } else {
            printf("[ %3c ]\n", currElem);
        }
    }
    printf("\n");
}
