#include <stdlib.h>

int minCost(int* startPos, int startPosSize, int* homePos, int homePosSize, int* rowCosts, int rowCostsSize, int* colCosts, int colCostsSize){
    int ** costs = malloc(sizeof *costs * rowCostsSize);
    int hx = homePos[0];
    int hy = homePos[1];
    int c1, c2;

    for (int i = 0; i < rowCostsSize; i++)
        costs[i] = malloc(sizeof **costs * colCostsSize);

    costs[hx][hy] = 0;

    for (int i = hx - 1; i >= 0; i--)
        costs[i][hy] = costs[i + 1][hy] + rowCosts[i];
    for (int i = hx + 1; i < rowCostsSize; i++)
        costs[i][hy] = costs[i - 1][hy] + rowCosts[i];
    for (int j = hy - 1; j >= 0; j--)
        costs[hx][j] = costs[hx][j + 1] + colCosts[j];
    for (int j = hy + 1; j < colCostsSize; j++)
        costs[hx][j] = costs[hx][j - 1] + colCosts[j];

    for (int i = hx - 1; i >= 0; i--) {
        for (int j = hy - 1; j >= 0; j--) {
            c1 = costs[i + 1][j] + rowCosts[i];
            c2 = costs[i][j + 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
        for (int j = hy + 1; j < colCostsSize; j++) {
            c1 = costs[i + 1][j] + rowCosts[i];
            c2 = costs[i][j - 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
    }
    for (int i = hx + 1; i < rowCostsSize; i++) {
        for (int j = hy - 1; j >= 0; j--) {
            c1 = costs[i - 1][j] + rowCosts[i];
            c2 = costs[i][j + 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
        for (int j = hy + 1; j < colCostsSize; j++) {
            c1 = costs[i - 1][j] + rowCosts[i];
            c2 = costs[i][j - 1] + colCosts[j];
            costs[i][j] = c1 > c2 ? c2 : c1;
        }
    }

    return costs[startPos[0]][startPos[1]];
}
