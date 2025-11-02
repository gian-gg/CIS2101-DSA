#include "header.h"

int main() {
    printf("--- Running MAXHEAP Tests (with Visualization) ---\n\n");

    // --- Test 1: Basic Insert and deleteMax Order ---
    printf("Test 1: Insert and deleteMax functionality...\n");
    MAXHEAP heap;
    init(&heap);

    int values[] = {40, 10, 30, 1, 100, 20};
    int totalValues = sizeof(values) / sizeof(values[0]);

    // Visualize each insert
    for (int index = 0; index < totalValues; index++) {
        printf("  Inserting: %d\n", values[index]);
        insert(&heap, values[index]);
        printf("    Heap state: ");
        display(heap); // VISUALIZATION
    }

    printf("\n  Final heap after all inserts:\n");
    printf("    Heap state: ");
    display(heap); // VISUALIZATION

    // Check root element (should be the max)
    if (heap.elems[0] != 100) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: Root element after inserts was %d, expected 100.\n", heap.elems[0]);
        return 1;
    }

    // Visualize each deleteMax (should be in descending order)
    printf("\n  Deleting all elements:\n");
    int expected_delete_order[] = {100, 40, 30, 20, 10, 1}; // Max to min
    for (int i = 0; i < totalValues; i++) {
        int max = deleteMax(&heap);
        printf("  Deleted: %d\n", max);

        if (max != expected_delete_order[i]) {
            printf("  [TEST FAILED]\n");
            printf("  ERROR: deleteMax() call %d: Got %d, expected %d.\n", i + 1, max, expected_delete_order[i]);
            return 1;
        }

        printf("    Heap state: ");
        display(heap); // VISUALIZATION
    }
    printf("  [Test Passed]\n\n");

    // --- Test 2: Edge Case - deleteMax from Empty Heap ---
    printf("Test 2: deleteMax from an empty heap...\n");
    printf("  Current state (should be empty):\n");
    printf("    Heap state: ");
    display(heap); // VISUALIZATION

    if (heap.count != EMPTY) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: Heap.count was %d after all deletes, expected %d.\n", heap.count, EMPTY);
        return 1;
    }

    int max = deleteMax(&heap);
    printf("  Attempted deleteMax, returned: %d\n", max);
    printf("    Heap state: ");
    display(heap); // VISUALIZATION

    if (max != EMPTY) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: deleteMax() from empty heap: Got %d, expected %d.\n", max, EMPTY);
        return 1;
    }
    printf("  [Test Passed]\n\n");

    // --- Test 3: heapSort Functionality ---
    printf("Test 3: heapSort (ascending order)...\n");
    MAXHEAP unsorted;
    init(&unsorted);

    for (int i = 0; i < totalValues; i++) {
        unsorted.elems[i] = values[i];
        unsorted.count++;
    }

    printf("  Unsorted input data:\n");
    printf("    Array state: ");
    display(unsorted); // VISUALIZATION

    // heapSort with a MAX-heap produces an ASCENDING array
    int expected_sort_order[] = {1, 10, 20, 30, 40, 100};
    MAXHEAP* sortedResult = heapSort(unsorted);

    if (sortedResult == NULL) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: heapSort() returned NULL (malloc failed?).\n");
        return 1;
    }

    printf("  Sorted result (ascending):\n");
    printf("    Array state: ");
    display(*sortedResult); // VISUALIZATION

    // Compare the sorted array
    for (int i = 0; i < totalValues; i++) {
        if (sortedResult->elems[i] != expected_sort_order[i]) {
            printf("  [TEST FAILED]\n");
            printf("  ERROR: heapSort() at index %d: Got %d, expected %d.\n", i, sortedResult->elems[i], expected_sort_order[i]);
            free(sortedResult);
            return 1;
        }
    }
    free(sortedResult);
    printf("  [Test Passed]\n\n");

    // --- Test 4: Edge Case - Insert into Full Heap ---
    printf("Test 4: Insert into a full heap...\n");
    MAXHEAP fullHeap;
    init(&fullHeap);

    for (int i = 0; i < SIZE; i++) {
        insert(&fullHeap, i); // Fill the heap
    }

    printf("  Heap after filling to capacity (%d elements):\n", SIZE);
    printf("    Heap state: ");
    display(fullHeap); // VISUALIZATION

    if (fullHeap.count != SIZE - 1) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: Count after filling heap is %d, expected %d.\n", fullHeap.count, SIZE - 1);
        return 1;
    }

    printf("  Attempting to insert '999' into full heap...\n");
    insert(&fullHeap, 999);

    printf("  Heap state after failed insert (should be unchanged):\n");
    printf("    Heap state: ");
    display(fullHeap); // VISUALIZATION

    if (fullHeap.count != SIZE - 1) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: Count changed to %d after insert attempt, expected %d.\n", fullHeap.count, SIZE - 1);
        return 1;
    }
    printf("  [Test Passed]\n\n");


    // --- All Tests Passed ---
    printf("--------------------------------\n");
    printf("All tests successful!\n");
    printf("--------------------------------\n");

    return 0; // Return 0 to indicate success
}
