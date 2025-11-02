#include "header.h"

void init(MAXHEAP* T) {
    T->count = EMPTY;
}

void display(MAXHEAP T) {
    for(int i = 0; i < T.count; i++) {
        printf("%d ", T.elems[i]);
    }
    printf("\n");
}

void insert(MAXHEAP* T, int value) {
    if (T->count + 1 < SIZE) {
        int child = ++(T->count);
        int parent = (child - 1) / 2;

        while(child > 0 && value > T->elems[parent]) {
            T->elems[child] = T->elems[parent];
            child = parent;
            parent = (child - 1) / 2;
        }

        T->elems[child] = value;
    }
}

int deleteMax(MAXHEAP* T) {
    int max = EMPTY;

    // Check if heap is not empty
    if (T->count > EMPTY) {
        max = T->elems[0];
        // Get last element AND decrease heap size
        int last = T->elems[T->count--];

        int parent = 0;
        int largest; // Will store index of largest child

        // Loop while the parent has at least one child (left child)
        // 'largest' is assigned the left child's index (2*p + 1)
        while ((largest = 2 * parent + 1) <= T->count) {
            int left = largest;
            int right = left + 1;

            // Check if right child exists AND is larger than left child
            if (right <= T->count && T->elems[right] > T->elems[left]) {
                largest = right; // Right child is the largest
            }

            // If last elem is already >= its largest child, it's in the right spot
            if (last >= T->elems[largest]) {
                break;
            }

            // Move the largest child up
            T->elems[parent] = T->elems[largest];
            // Move parent down to continue heapify-down
            parent = largest;
        }

        // Place the 'last' element in its correct final position
        T->elems[parent] = last;
    }

    return max;
}

// Builds a new min-heap by inserting all elements from an unsorted structure.
MAXHEAP* insertAll(MAXHEAP UnsortedTree) {
    // Allocate memory for the new heap
    MAXHEAP* result = (MAXHEAP*)malloc(sizeof(MAXHEAP));
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
MAXHEAP* heapSort(MAXHEAP UnsortedTree) {
    // Allocate memory for the final sorted array (in a heap struct)
    MAXHEAP* result = (MAXHEAP*)malloc(sizeof(MAXHEAP));
    if (result != NULL) {
        init(result);

        // 1. Build a valid min-heap from the unsorted data
        MAXHEAP* SortedTree = insertAll(UnsortedTree);

        int temp;
        int index = SortedTree->count; // Start placing elements from the end

        // 2. Repeatedly extract the minimum element from the heap
        while ((temp = deleteMax(SortedTree)) != -1) {
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
