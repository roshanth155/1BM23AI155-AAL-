#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;  // Declare i, j, minIndex, and temp outside the loop

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;  // Declare i outside the loops for compatibility with C90

    printf("Original array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
