#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void bubbleSort(int *a, int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int binarySearch(int *a, int n, int target, int *cmp) {
    int l = 0, h = n - 1, m;
    *cmp = 0;
    while (l <= h) {
        (*cmp)++;
        m = l + (h - l) / 2;
        if (a[m] == target) return m;
        if (a[m] < target) l = m + 1;
        else h = m - 1;
    }
    return -1;
}

int main() {
    int n = 100, min = 1, max = 5000, cmp = 0, i;
    int *a = malloc(n * sizeof(int));
    if (!a) return perror("Malloc failed"), 1;

    srand(time(0));
    for (i = 0; i < n; i++) a[i] = rand() % (max - min + 1) + min;

    struct timeval s, e;
    gettimeofday(&s, NULL);
    bubbleSort(a, n);
    gettimeofday(&e, NULL);
    double sortTime = (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec) / 1e6;

    int target = rand() % (max - min + 1) + min;
    gettimeofday(&s, NULL);
    int idx = binarySearch(a, n, target, &cmp);
    gettimeofday(&e, NULL);
    double searchTime = (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec) / 1e6;

    printf("Target: %d %s\n", target, idx != -1 ? "found" : "not found");
    printf("Sort time: %.6f s, Search time: %.6f s, Comparisons: %d\n", sortTime, searchTime, cmp);

    free(a);
    return 0;
}

