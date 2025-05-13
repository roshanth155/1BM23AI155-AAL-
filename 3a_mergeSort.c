#include <stdio.h>

#define MAX 10

int a[MAX + 1] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[MAX + 1];

void merge(int low, int mid, int high) {
    int i = low, l1 = low, l2 = mid + 1;

    while (l1 <= mid && l2 <= high)
        b[i++] = (a[l1] <= a[l2]) ? a[l1++] : a[l2++];

    while (l1 <= mid) b[i++] = a[l1++];
    while (l2 <= high) b[i++] = a[l2++];

    for (i = low; i <= high; i++) a[i] = b[i];
}

void mergeSort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int i;  // Declare 'i' here to avoid redefinition in loops

    printf("List before sorting:\n");
    for (i = 0; i <= MAX; i++) printf("%d ", a[i]);

    mergeSort(0, MAX);

    printf("\nList after sorting:\n");
    for (i = 0; i <= MAX; i++) printf("%d ", a[i]);

    return 0;
}
