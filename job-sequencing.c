#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortlist (int p[], int d[], int n) {
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1 - i; j ++) {
            if (p[j] < p[j + 1]) {
                swap(&p[j], &p[j + 1]);
                swap(&d[j], &d[j + 1]);
            }
        }
    }
}

int main () {
    int n;
    printf("Enter number of jobs : ");
    scanf("%d", &n);
    int p[n], d[n];
    int size = 0;
    printf("Enter details of jobs : \n");
    for (int i = 0; i < n; i ++) {
        printf("Profit of job %d = ", i + 1);
        scanf("%d", &p[i]);
        printf("Deadline of job %d = ", i + 1);
        scanf("%d", &d[i]);
        if (size < d[i]) size = d[i];
    }

    sortlist(p, d, n);
    printf("\nSorted jobs : ");
    printf("\nP[n]  ");
    for (int i = 0; i < n; i ++) printf("%d  ", p[i]);
    printf("\nD[n]  ");
    for (int i = 0; i < n; i ++) printf("%d  ", d[i]);

    int jobs[size + 1];
    for (int i = 0; i <= size; i ++) jobs[i] = -1;
    for (int i = 0; i < n; i ++) {
        for (int j = d[i]; j >= 1; j --) {
            if (jobs[j] == -1) {
                jobs[j] = i;
                break;
            }
        }
    }

    printf("\nAccepted list of jobs :\n");
    for (int i = 1; i <= size; i ++) printf("Job %d  ", jobs[i] + 1);

    return 0;
}
