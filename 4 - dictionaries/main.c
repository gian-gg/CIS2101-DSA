#include "./implementations/open_hashing/header.h"

int main() {
    mode();

    DICTIONARY D;
    init(D);

    insert(D, 10);
    insert(D, 200);
    insert(D, 2);
    insert(D, 33);
    insert(D, 43);

    visualize(D);

    delete(D, 200);
    delete(D, 33);

    visualize(D);

    display(D);

    return 0;
}