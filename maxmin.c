#include <stdio.h>

int max, min;

void maxmin(int arr[], int i, int j) {
    int min1, max1, mid;
    if (i == j) max = min = arr[i];
    else {
        if (i == j - 1) {
            if (arr[i] < arr[j]) {
                min = arr[i];
                max = arr[j];
            } else {
                min = arr[j];
                max = arr[i];
            }
        } else {
            mid = (i + j) / 2;
            maxmin(arr, i, mid);
            max1 = max; 
            min1 = min;
            maxmin(arr, mid + 1, j);
            if (max < max1) max = max1;
            if (min > min1) min = min1;
        }
    }
}

int main () {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements : ");
    for (int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    max = min = arr[0];
    maxmin(arr, 0, n - 1);
    printf("\nMax = %d\nMin = %d", max, min);
    return 0;
}
