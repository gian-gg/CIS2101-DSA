#include "header.h"

void runTest(int*, int, int, int);

int main() {
    // Test Case 1: Standard Sorted Array
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);

    printf("--- Standard Array Tests ---\n");
    runTest(array, size, 1, 0);   // Start
    runTest(array, size, 5, 4);   // Middle
    runTest(array, size, 9, 8);   // End
    runTest(array, size, 10, -1); // Not Found (Greater)
    runTest(array, size, -5, -1); // Not Found (Smaller)

    // Test Case 2: Single Element Array
    int singleArr[] = {42};
    printf("\n--- Single Element Tests ---\n");
    runTest(singleArr, 1, 42, 0); // Found
    runTest(singleArr, 1, 10, -1); // Not Found

    // Test Case 3: Empty Array (Size 0)
    printf("\n--- Empty Array Tests ---\n");
    runTest(array, 0, 1, -1); // Should handle size 0 safely

    return 0;
}

void runTest(int* arr, int size, int target, int expected) {
    int result = binarySearch(arr, size, target);

    if(result == expected) {
        printf("Target: %2d | Expected: %2d | Got: %2d | ✅ PASSED\n", target, expected, result);
    } else {
        printf("Target: %2d | Expected: %2d | Got: %2d | ❌ FAILED\n", target, expected, result);
    }
}
