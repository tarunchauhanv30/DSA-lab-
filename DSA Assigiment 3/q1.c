#include <stdio.h>
int main() {
    int arr[] = {10, 5, 20, 20, 8, 15, 10};
    int size = 7;
    int n = 3;
    int largest[3];
    int count = 0;
    for (int i = 0; i < size; i++) {
    int x = arr[i];
    int duplicate = 0;
    for (int j = 0; j < count; j++) {
    if (largest[j] == x) {
    duplicate = 1;
     break;
            }
        } if (duplicate)
       continue; int pos = 0;
      while (pos < count && largest[pos] > x) {
            pos++;
        } if (count < n) {
            for (int j = count; j > pos; j--) {
                largest[j] = largest[j - 1];
            }largest[pos] = x;
            count++;
        }  else if (pos < n) {
            for (int j = n - 1; j > pos; j--) {
          largest[j] = largest[j - 1];
            }largest[pos] = x;
        }
     }if (count < n) { printf("Nth largest distinct element does not exist.\n"); } 
    else {
         printf("1st largest = %d\n", largest[0]);
         printf("2nd largest = %d\n", largest[1]);
         printf("3rd largest = %d\n", largest[2]);

     } return 0;
}