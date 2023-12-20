#include "2706-buy-two-chocolates.h"

#define MAX_PRICE   100

int buyChoco (int * prices, int pricesSize, int money) {
    int min = MAX_PRICE;
    int min2 = MAX_PRICE;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) {
            min2 = min;
            min = prices[i];
        } else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }
    return min + min2 > money ? money : money - min - min2;
}
