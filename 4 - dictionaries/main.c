#include "./implementations/closed_hashing/v1/header.h"
// #include "./implementations/open_hashing/header.h"

int main() {
    DICTIONARY D;
    init(&D);

    mode();

    insert(&D, 15);
    insert(&D, 25);
    insert(&D, 35);
    insert(&D, 5);

    visualize(D);

    printf("Is 25 in Dictionary? %s\n", member(D, 25) ? "YES" : "NO");
    printf("Is 100 in Dictionary? %s\n", member(D, 100) ? "YES" : "NO");

    delete(&D, 25);

    visualize(D);

    printf("After deleting 25:\n");
    printf("Is 25 in Dictionary? %s\n", member(D, 25) ? "YES" : "NO");

    display(D);

    return 0;
}
