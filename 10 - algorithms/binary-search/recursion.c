#include "header.h"

int recursion(int* arr, int left, int right, int target) {
    int mid = (left+right)/2;

    if (left > right) {
        return -1;
    } else if (target < arr[mid]) {
        return recursion(arr, left, mid-1, target);
    } else if (target > arr[mid]) {
        return recursion(arr, mid+1, right, target);
    } else {
        return mid;
    }
}

int binarySearch(int* arr, int size, int target) {
    return recursion(arr, 0, size-1, target);
}
