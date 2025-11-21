#include "header.h"

int main() {
    BST T;
    init(&T);

    insert(&T, 5);
    insert(&T, 2);
    insert(&T, 1);
    insert(&T, 7);
    insert(&T, 6);
    insert(&T, 10);
    insert(&T, 11);
    insert(&T, 12);

    visualize(T);

    delete(&T, 5);

    visualize(T);


    return 0;
}
