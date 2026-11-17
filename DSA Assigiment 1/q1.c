#include <stdio.h>
int main() {
    int arr[6];
    int pos[6], neg[6];
    int i, j = 0, k = 0, index = 0;

    printf("Enter 6 numbers:\n");
    for (i = 0; i < 6; i++) { 
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 6; i++) {
        if (arr[i] >= 0) {
            pos[j++] = arr[i];
        } else {
        
            neg[k++] = arr[i];
        }
    }
    for (i = 0; i < 3; i++) {
        arr[index++] = pos[i];
    }
    for (i = 0; i < 3; i++) {
        arr[index++] = neg[i];
    }
    printf("Rearranged array:\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}