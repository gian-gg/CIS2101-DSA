#include "header.h"

int main() {
    DICTIONARY D;
    init(&D);

    mode();

    insert(&D, 1);
    insert(&D, 2);
    insert(&D, 3);
    insert(&D, 4);
    insert(&D, 5);

    insert(&D, 25);
    insert(&D, 33);

    visualize(D);

    printf("Is 25 in Dictionary? %s\n", member(D, 25) ? "YES" : "NO");
    printf("Is 100 in Dictionary? %s\n\n", member(D, 100) ? "YES" : "NO");

    // delete(&D, 25);

    visualize(D);

    printf("After deleting 25:\n");
    printf("Is 25 in Dictionary? %s\n", member(D, 25) ? "YES" : "NO");

    display(D);

    return 0;
}