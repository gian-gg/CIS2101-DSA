// #include "array.c"
#include "linked_list.c"
// #include "cursor.c"

int main() {
    mode();


    LIST L = init();

    push(&L, 'a');
    push(&L, 'b');
    push(&L, 'c');

    display(L);

    pop(&L);

    display(L);

    push(&L, 'c');
    push(&L, 'c');
    push(&L, 'c');

    display(L);

    printf("TOP ELEMENT: %c", top(L));

    printf("\nIS FULL? %s", full(L) ? "true" : "false");
    printf("\nIS EMPTY? %s", empty(L) ? "true" : "false");

    printf("\n");
    return 0;
}
