#include "header.h"

// Initialize the heap
void init(MINHEAP* T) {
    T->count = EMPTY;
}

// Display the heap elems
void display(MINHEAP T) {
    for (int index = 0; index <= T.count; index++) {
        printf("%d ", T.elems[index]);
    }
    printf("\n");
}

// Insert a value into the heap (maintaining min-heap property)
void insert(MINHEAP* T, int value) {
    if (T->count + 1 < SIZE) {  // Check if heap is full
        int child = ++(T->count);
        int parent = (child - 1) / 2;

        // Heapify up
        while (child > 0 && value < T->elems[parent]) {
            T->elems[child] = T->elems[parent];
            child = parent;
            parent = (child - 1) / 2;
        }

        T->elems[child] = value;
    }
}

// Delete and return the minimum element (root of the heap)
int deleteMin(MINHEAP* T) {
    int min = EMPTY;
    if (T->count > EMPTY) {
        min = T->elems[0];
        int last = T->elems[T->count--]; // Get last elem and shrink heap

        int parent = 0;
        int smallest;

        // Heapify down
        while ((smallest = 2 * parent + 1) <= T->count) {
            int left = smallest;
            int right = left + 1;

            // Find the smaller child
            if (right <= T->count && T->elems[right] < T->elems[left]) {
                smallest = right;
            }

            // Stop if the last value is already smaller than its children
            if (last <= T->elems[smallest]) break;

            // Move the smaller child up
            T->elems[parent] = T->elems[smallest];
            parent = smallest;
        }

        T->elems[parent] = last; // Place last elem in correct spot
    }

    return min;
}

// Builds a new min-heap by inserting all elements from an unsorted structure.
MINHEAP* insertAll(MINHEAP UnsortedTree) {
    // Allocate memory for the new heap
    MINHEAP* result = (MINHEAP*)malloc(sizeof(MINHEAP));
    if (result != NULL) {
        init(result); // Initialize the new heap

        // Loop through all elements in the input and insert them
        for (int idx = 0; idx <= UnsortedTree.count; idx++) {
            // The insert() function automatically handles heapification
            insert(result, UnsortedTree.elems[idx]);
        }

        return result;
    }

    free(result); // free(NULL) is safe
    return NULL;  // Return NULL if malloc failed
}

// Sorts elements in descending order using the heap.
MINHEAP* heapSort(MINHEAP UnsortedTree) {
    // Allocate memory for the final sorted array (in a heap struct)
    MINHEAP* result = (MINHEAP*)malloc(sizeof(MINHEAP));
    if (result != NULL) {
        init(result);

        // 1. Build a valid min-heap from the unsorted data
        MINHEAP* SortedTree = insertAll(UnsortedTree);

        int temp;
        int index = SortedTree->count; // Start placing elements from the end

        // 2. Repeatedly extract the minimum element from the heap
        while ((temp = deleteMin(SortedTree)) != -1) {
            // Place the smallest element at the end of the result array
            result->elems[index--] = temp;
            result->count++;
        }

        free(SortedTree); // Free the temporary heap
        return result;    // Return the struct containing the sorted array
    }

    free(result);
    return NULL;
}
