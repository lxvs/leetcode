#include "121-best-time-to-buy-and-sell-stock.h"

#if DEBUG
#include <stdio.h>
#endif

#define max(a, b)       (a < b ? b : a)

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int maxpro = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        profit = max(0, profit + prices[i + 1] - prices[i]);
        maxpro = max(maxpro, profit);
#if DEBUG
        fprintf(stderr, "profit = %2d, maxpro = %2d\n",
                profit, maxpro);
#endif
    }

    return maxpro;
}
