#include "header.h"

/**
 * @brief Main function to run automated, visualized tests for the MINHEAP.
 * @return 0 on success, 1 on failure.
 */
int main() {
    printf("--- Running MINHEAP Tests (with Visualization) ---\n\n");

    // --- Test 1: Basic Insert and deleteMin Order ---
    printf("Test 1: Insert and deleteMin functionality...\n");
    MINHEAP heap;
    init(&heap);

    int values[] = {40, 10, 30, 1, 100, 20};
    int totalValues = sizeof(values) / sizeof(values[0]);

    // Visualize each insert
    for (int index = 0; index < totalValues; index++) {
        printf("  Inserting: %d\n", values[index]);
        insert(&heap, values[index]);
        printf("    Heap state: ");
        display(heap); // V_ISUALIZATION_
    }

    printf("\n  Final heap after all inserts:\n");
    printf("    Heap state: ");
    display(heap); // V_ISUALIZATION_

    // Check root element
    if (heap.elems[0] != 1) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: Root element after inserts was %d, expected 1.\n", heap.elems[0]);
        return 1;
    }

    // Visualize each deleteMin
    printf("\n  Deleting all elements:\n");
    int expected_delete_order[] = {1, 10, 20, 30, 40, 100};
    for (int i = 0; i < totalValues; i++) {
        int min = deleteMin(&heap);
        printf("  Deleted: %d\n", min);

        if (min != expected_delete_order[i]) {
            printf("  [TEST FAILED]\n");
            printf("  ERROR: deleteMin() call %d: Got %d, expected %d.\n", i + 1, min, expected_delete_order[i]);
            return 1;
        }

        printf("    Heap state: ");
        display(heap); // V_ISUALIZATION_
    }
    printf("  [Test Passed]\n\n");

    // --- Test 2: Edge Case - deleteMin from Empty Heap ---
    printf("Test 2: deleteMin from an empty heap...\n");
    printf("  Current state (should be empty):\n");
    printf("    Heap state: ");
    display(heap); // V_ISUALIZATION_

    if (heap.count != EMPTY) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: Heap.count was %d after all deletes, expected %d.\n", heap.count, EMPTY);
        return 1;
    }

    int min = deleteMin(&heap);
    printf("  Attempted deleteMin, returned: %d\n", min);
    printf("    Heap state: ");
    display(heap); // V_ISUALIZATION_

    if (min != EMPTY) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: deleteMin() from empty heap: Got %d, expected %d.\n", min, EMPTY);
        return 1;
    }
    printf("  [Test Passed]\n\n");

    // --- Test 3: heapSort Functionality ---
    printf("Test 3: heapSort (descending order)...\n");
    MINHEAP unsorted;
    init(&unsorted);

    for (int i = 0; i < totalValues; i++) {
        unsorted.elems[i] = values[i];
        unsorted.count++;
    }

    printf("  Unsorted input data:\n");
    printf("    Array state: ");
    display(unsorted); // V_ISUALIZATION_

    int expected_sort_order[] = {100, 40, 30, 20, 10, 1};
    MINHEAP* sortedResult = heapSort(unsorted);

    if (sortedResult == NULL) {
        printf("  [TEST FAILED]\n");
        printf("  ERROR: heapSort() returned NULL (malloc failed?).\n");
        return 1;
    }

    printf("  Sorted result (descending):\n");
    printf("    Array state: ");
    display(*sortedResult); // V_ISUALIZATION_

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
    MINHEAP fullHeap;
    init(&fullHeap);

    for(int i = 0; i < SIZE; i++) {
        insert(&fullHeap, i); // Fill the heap
    }

    printf("  Heap after filling to capacity (%d elements):\n", SIZE);
    printf("    Heap state: ");
    display(fullHeap); // V_ISUALIZATION_

    if (fullHeap.count != SIZE - 1) {
         printf("  [TEST FAILED]\n");
         printf("  ERROR: Count after filling heap is %d, expected %d.\n", fullHeap.count, SIZE - 1);
         return 1;
    }

    printf("  Attempting to insert '999' into full heap...\n");
    insert(&fullHeap, 999);

    printf("  Heap state after failed insert (should be unchanged):\n");
    printf("    Heap state: ");
    display(fullHeap); // V_ISUALIZATION_

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
