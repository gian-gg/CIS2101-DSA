#include "./implementations/array.c"
// #include "./implementations/linked_list.c"
// #include "./implementations/cursor.c"

void display(STACK);
void insertBottom(STACK*,char);

int main() {
    mode();

    STACK L;
    init(&L);

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


    insertBottom(&L, 'X');

    printf("\n");

    display(L);

    printf("\n");
    return 0;
}


void display(STACK L) {
    STACK temp;
    init(&temp);

    while(!empty(L)) {
        char elem = top(L);
        printf("%c ", elem);
        push(&temp, elem);
        pop(&L);
    }

    while(!empty(temp)) {
        push(&L, top(temp));
        pop(&temp);
    }

    printf("\n");
}


void insertBottom(STACK *L, char elem) {
    STACK temp;
    init(&temp);

    while(!empty(*L)) {
        push(&temp, top(*L));
        pop(L);
    }

    push(L, elem);

    while(!empty(temp)) {
        push(L, top(temp));
        pop(&temp);
    }
}
