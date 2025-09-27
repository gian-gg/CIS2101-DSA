#include "./implementations/array.c"
#include "./implementations/linked_list.c"
#include "./implementations/cursor.c"

int main() {
    QUEUE Q;
    init(&Q);

    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    enqueue(&Q, 'D');
    enqueue(&Q, 'E');

    dequeue(&Q);

    enqueue(&Q, 'F');
    enqueue(&Q, 'G');

    dequeue(&Q);

    enqueue(&Q, 'H');
    enqueue(&Q, 'I');
    enqueue(&Q, 'J');
    enqueue(&Q, 'K');
    enqueue(&Q, 'K');
    enqueue(&Q, 'K');
    enqueue(&Q, 'K');

    dequeue(&Q);
    enqueue(&Q, 'L');

    // visualize(Q);
    display(&Q);


    return 0;
}