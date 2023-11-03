#include "121-best-time-to-buy-and-sell-stock.h"

#define max(a, b)       (a < b ? b : a)

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int returnValue = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        profit = max(0, profit + prices[i + 1] - prices[i]);
        returnValue = max(returnValue, profit);
    }

    return returnValue;
}
