#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList;

void insertStart(charList *L, char elem) {
    charList temp = malloc(sizeof(struct node));
    temp->elem = elem;

    temp->link = *L;
    *L = temp;
}

void display(charList L) {
    for(charList curr = L; curr != NULL; curr = curr->link) {
        printf("%c ", curr->elem);
    }
}

bool findElem(charList L, char X) {
    charList curr;
    for(curr = L; curr != NULL && curr->elem != X; curr = curr->link) {}

    return curr != NULL;
}

int main() {
    charList L = NULL;

    insertStart(&L, 'C');
    insertStart(&L, 'S');
    insertStart(&L, 'U');

    // printf("List: ");
    // display(L);

    printf("\nIs In List: %s\n", findElem(L, 'G') ? "true" : "false");
    return 0;
}
