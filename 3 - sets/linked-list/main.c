#include <stdio.h>
#include "./header.h"

int main() {
    printf("\033[H\033[J");
    mode();

    SET A;
    init(&A);
    insertElem(&A, 100);
    insertElem(&A, 22);
    insertElem(&A, 300);
    insertElem(&A, 10);

    SET B;
    init(&B);
    insertElem(&B, 12);
    insertElem(&B, 22);
    insertElem(&B, 3);
    insertElem(&B, 0);
    insertElem(&B, 10);

    printf("A = ");
    read(A);

    printf("B = ");
    read(B);

    printf("\n");

    deleteElem(&A, 4);
    printf("A = ");
    read(A);

    deleteElem(&B, 3);
    printf("B = ");
    read(B);

    printf("A = B: %s\n", equal(A,B) ? "true" : "false");

    SET C = Union(A, B);
    printf("\nA u B = ");
    read(C);

    SET D = Intersection(A, B);
    printf("A n B = ");
    read(D);

    SET E = Difference(A, B);
    printf("\nA - B = ");
    read(E);

    SET F = Difference(B, A);
    printf("B - A = ");
    read(F);

    printf("\n");
    return 0;
}
