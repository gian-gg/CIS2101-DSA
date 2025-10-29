#include "./header.h"

int main() {
    printf("\033[H\033[J"); // clear screen
    mode();

    DICT D;
    init(D);

    printf("\n===== TEST 1: INSERTION =====\n");
    insertElem(D, 15, "Apple");
    insertElem(D, 22, "Banana");
    insertElem(D, 33, "Cherry");
    insertElem(D, 0,  "Orange");
    insertElem(D, 10, "Grapes");
    insertElem(D, 22, "Blueberry"); // duplicate key test (should not insert again)
    visualize(D);

    printf("\n===== TEST 2: MEMBERSHIP CHECK =====\n");
    printf("Is key 15 in Dictionary? %s\n", member(D, 15) ? "YES ✅" : "NO ❌");
    printf("Is key 100 in Dictionary? %s\n", member(D, 100) ? "YES ✅" : "NO ❌");

    printf("\n===== TEST 3: VALUE RETRIEVAL =====\n");
    char* val = getValue(D, 22);
    if (val != NULL)
        printf("Value for key 22: \"%s\"\n", val);
    else
        printf("Key 22 not found.\n");

    val = getValue(D, 100);
    if (val != NULL)
        printf("Value for key 100: \"%s\"\n", val);
    else
        printf("Key 100 not found.\n");

    printf("\n===== TEST 4: DELETION =====\n");
    printf("Deleting key 15...\n");
    deleteElem(D, 15);
    visualize(D);

    printf("\nTrying to delete key 15 again (should do nothing)...\n");
    deleteElem(D, 15);
    visualize(D);

    printf("\n===== TEST 5: FINAL DICTIONARY CONTENT =====\n");
    display(D);

    printf("\n===== TEST 6: FILL TABLE UNTIL COLLISIONS =====\n");
    for (int i = 1; i <= 12; i++) {
        int key = i * 3;
        char valStr[20];
        sprintf(valStr, "Val%d", key);
        insertElem(D, key, valStr);
    }
    visualize(D);

    printf("\n===== ALL TESTS COMPLETED SUCCESSFULLY =====\n");

    return 0;
}
