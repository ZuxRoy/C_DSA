#include <stdio.h>

void merge (int arr[], int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i ++) L[i] = arr[l + i];
    for (i = 0; i < n2; i ++) R[i] = arr[mid + 1 + i];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) arr[k ++] = L[i ++];
        else arr[k ++] = R[j ++];
    }

    while (i < n1) arr[k ++] = L[i ++];
    while (j < n2) arr[k ++] = R[j ++];
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements : ");
    for (int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    mergesort(arr, 0, n - 1);
    printf("\nSorted array : ");
    for (int i = 0; i < n; i ++) printf("%d  ", arr[i]);
    return 0;
}
