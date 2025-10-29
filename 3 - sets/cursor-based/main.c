#include <stdio.h>
#include "./header.h"

int main() {
    printf("\033[H\033[J");
    mode();

    VirtualHeap VH;
    initVH(&VH);

    SET A;
    init(&A);
    insertElem(&VH, &A, 1);
    insertElem(&VH, &A, 2);
    insertElem(&VH, &A, 3);

    SET B;
    init(&B);
    insertElem(&VH, &B, 1);
    insertElem(&VH, &B, 2);
    insertElem(&VH, &B, 3);

    printf("A = ");
    read(VH, A);

    printf("B = ");
    read(VH, B);

    printf("\n");

    deleteElem(&VH, &A, 4);
    printf("A = ");
    read(VH, A);

    deleteElem(&VH, &B, 3);
    printf("B = ");
    read(VH, B);

    printf("A = B: %s\n", equal(VH, A,B) ? "true" : "false");

    SET C = Union(&VH, A, B);
    printf("\nA u B = ");
    read(VH, C);

    SET D = Intersection(&VH, A, B);
    printf("A n B = ");
    read(VH, D);

    SET E = Difference(&VH, A, B);
    printf("\nA - B = ");
    read(VH, E);

    SET F = Difference(&VH, B, A);
    printf("B - A = ");
    read(VH, F);

    printf("\n");
    return 0;
}
