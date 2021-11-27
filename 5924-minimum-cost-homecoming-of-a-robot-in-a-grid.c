#include <stdlib.h>

int minCost(int* startPos, int startPosSize, int* homePos, int homePosSize, int* rowCosts, int rowCostsSize, int* colCosts, int colCostsSize){
    int ** costs = malloc(sizeof *costs * rowCostsSize);
    int x = startPos[0];
    int y = startPos[1];
    int c1, c2;

    for (int i = 0; i < rowCostsSize; i++)
        costs[i] = malloc(sizeof **costs * colCostsSize);

    costs[x][y] = 0;

    for (int i = x - 1; i >= 0; i--)
        costs[i][y] = costs[i + 1][y] + rowCosts[i];
    for (int i = x + 1; i < rowCostsSize; i++)
        costs[i][y] = costs[i - 1][y] + rowCosts[i];
    for (int j = y - 1; j >= 0; j--)
        costs[x][j] = costs[x][j + 1] + colCosts[j];
    for (int j = y + 1; j < colCostsSize; j++)
        costs[x][j] = costs[x][j - 1] + colCosts[j];

    for (int i = x - 1; i >= 0; i--) {
        for (int j = y - 1; j >= 0; j--) {
            c1 = costs[i + 1][j] + rowCosts[i];
            c2 = costs[i][j + 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
        for (int j = y + 1; j < colCostsSize; j++) {
            c1 = costs[i + 1][j] + rowCosts[i];
            c2 = costs[i][j - 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
    }
    for (int i = x + 1; i < rowCostsSize; i++) {
        for (int j = y - 1; j >= 0; j--) {
            c1 = costs[i - 1][j] + rowCosts[i];
            c2 = costs[i][j + 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
        for (int j = y + 1; j < colCostsSize; j++) {
            c1 = costs[i - 1][j] + rowCosts[i];
            c2 = costs[i][j - 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
    }

    return costs[homePos[0]][homePos[1]];
}
