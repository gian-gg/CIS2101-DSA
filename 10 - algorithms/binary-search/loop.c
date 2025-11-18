#include "header.h"

int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    int mid = (left+right)/2;

    while (left <= right && arr[mid] != target) {
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        mid = (left+right)/2;
    }

    return (mid < size && mid >= 0 && arr[mid] == target) ? mid : -1;
}
