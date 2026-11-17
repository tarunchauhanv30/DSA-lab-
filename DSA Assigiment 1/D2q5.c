#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int a[], int n) {
    int i, j, key;

    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {

            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[10000], b[10000];
    int n, i;
    clock_t start, end;
    double time1, time2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    for(i = 0; i < n; i++) {
        a[i] = rand() % 1000;
        b[i] = a[i];
    }

    start = clock();
    insertionSort(a, n);
    end = clock();

    time1 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSort(b, n);
    end = clock();

    time2 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nInsertion Sort Time = %f seconds\n", time1);
    printf("Bubble Sort Time    = %f seconds\n", time2);

    return 0;
}