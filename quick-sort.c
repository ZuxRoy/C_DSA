#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j) {
        while (arr[i] <= pivot && i < h) i ++;
        while (arr[j] > pivot && j > l) j --;
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort (int arr[], int l, int h) {
    if (l < h) {
        int part = partition(arr, l, h);
        quicksort(arr, l, part - 1);
        quicksort(arr, part + 1, h);
    }
}

int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements : ");
    for (int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    quicksort(arr, 0, n - 1);
    printf("\nSorted array : ");
    for (int i = 0; i < n; i ++) printf("%d  ", arr[i]);
    return 0;
}
