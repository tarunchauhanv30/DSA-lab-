#include <stdio.h>
int main() {
    int n;
  printf("Enter number of days: ");
    scanf("%d", &n);

    int price[n];
   printf("Enter stock prices:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    int minPrice = price[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {

    int profit = price[i] - minPrice;
        if (profit > maxProfit) {
            maxProfit = profit;
        }
        if (price[i] < minPrice) {
            minPrice = price[i];
        }
    }
  printf("Maximum Profit = %d\n", maxProfit);
    return 0;
}