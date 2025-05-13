#include <stdio.h>

void swap(int *a, int *b) { *a ^= *b ^= *a ^= *b; }  // XOR swap

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1, j;  // Declare 'j' outside the loop
    for (j = low; j < high; j++)  // 'j' is declared outside the loop now
        if (arr[j] <= pivot) swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    int i;  // Declare 'i' outside the loop
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}, n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: "); printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: "); printArray(arr, n);
    return 0;
}
