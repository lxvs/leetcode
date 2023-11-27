#include "935-knight-dialer.h"

#define RETURN_VALUE_MODULO     1000000007

int knightDialer (int n) {
    unsigned int answer[5001][10];
    unsigned int returnValue = 0;

    for (int j = 0; j < 10; j++) {
        answer[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        answer[i][0] = (answer[i - 1][4] + answer[i - 1][6]) % RETURN_VALUE_MODULO;
        answer[i][1] = (answer[i - 1][6] + answer[i - 1][8]) % RETURN_VALUE_MODULO;
        answer[i][2] = (answer[i - 1][7] + answer[i - 1][9]) % RETURN_VALUE_MODULO;
        answer[i][3] = (answer[i - 1][4] + answer[i - 1][8]) % RETURN_VALUE_MODULO;
        answer[i][4] = (answer[i - 1][0] + answer[i - 1][3] + answer[i - 1][9]) % RETURN_VALUE_MODULO;
        answer[i][5] = 0;
        answer[i][6] = (answer[i - 1][0] + answer[i - 1][1] + answer[i - 1][7]) % RETURN_VALUE_MODULO;
        answer[i][7] = (answer[i - 1][2] + answer[i - 1][6]) % RETURN_VALUE_MODULO;
        answer[i][8] = (answer[i - 1][1] + answer[i - 1][3]) % RETURN_VALUE_MODULO;
        answer[i][9] = (answer[i - 1][2] + answer[i - 1][4]) % RETURN_VALUE_MODULO;
    }
    for (int k = 0; k < 10; k++) {
        returnValue = (returnValue + answer[n - 1][k]) % RETURN_VALUE_MODULO;
    }
    return returnValue;
}
