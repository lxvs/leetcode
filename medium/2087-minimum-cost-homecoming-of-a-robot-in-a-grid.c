#include "2087-minimum-cost-homecoming-of-a-robot-in-a-grid.h"

int minCost (int * startPos, int startPosSize, int * homePos, int homePosSize, int * rowCosts, int rowCostsSize, int * colCosts, int colCostsSize) {
    int returnValue = 0;

    if (startPos[0] < homePos[0]) {
        for (int i = startPos[0] + 1; i <= homePos[0]; i++) {
            returnValue += rowCosts[i];
        }
    } else if (startPos[0] > homePos[0]) {
        for (int i = startPos[0] - 1; i >= homePos[0]; i--) {
            returnValue += rowCosts[i];
        }
    }

    if (startPos[1] < homePos[1]) {
        for (int i = startPos[1] + 1; i <= homePos[1]; i++) {
            returnValue += colCosts[i];
        }
    } else if (startPos[1] > homePos[1]) {
        for (int i = startPos[1] - 1; i >= homePos[1]; i--) {
            returnValue += colCosts[i];
        }
    }

    return returnValue;
}
