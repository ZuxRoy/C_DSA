#include <stdio.h>

void swap (float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sortlist (float p[], float w[], float pw[], int n) {
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1 - i; j ++) {
            if (pw[j] < pw[j + 1]) {
                swap(&pw[j], &pw[j + 1]);
                swap(&p[j], &p[j + 1]);
                swap(&w[j], &w[j + 1]);
            }
        }
    }
}

int main () {
    int n;
    printf("Enter number of items in list : ");
    scanf("%d", &n);
    float p[n], w[n], pw[n];
    printf("Enter details of items : \n");
    for (int i = 0; i < n; i ++) {
        printf("Profit of item %d = ", i + 1);
        scanf("%f", &p[i]);
        printf("Weight of item %d = ", i + 1);
        scanf("%f", &w[i]);
        pw[i] = p[i] / w[i];
    }

    int m;
    printf("Enter max weight of knapsack = ");
    scanf("%d", &m);

    sortlist(p, w, pw, n);
    printf("\nSorted lists : ");
    printf("\nP[n]  ");
    for (int i = 0; i < n; i ++) printf("%.2f  ", p[i]);
    printf("\nW[n]  ");
    for (int i = 0; i < n; i ++) printf("%.2f  ", w[i]);
    printf("\nP/W   ");
    for (int i = 0; i < n; i ++) printf("%.2f  ", pw[i]);
    float x[n] , profit = 0;
    for (int i = 0; i < n; i ++) x[i] = 0;
    for (int i = 0; i < n; i ++) {
        if (w[i] <= m) {
            m -= w[i];
            profit += p[i];
            x[i] = 1;
        } else {
            float temp = m/w[i];
            x[i] = temp;
            profit += (p[i] * temp);
            break;
        }
    }
    printf("\n\nX     ");
    for (int i = 0; i < n; i ++) printf("%.2f  ", x[i]);
    printf("\nFinal profit = %.2f", profit);

    return 0;
}
