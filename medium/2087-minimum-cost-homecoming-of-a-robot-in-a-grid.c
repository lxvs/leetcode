#include <stdlib.h>

int minCost(int* startPos, int startPosSize, int* homePos, int homePosSize, int* rowCosts, int rowCostsSize, int* colCosts, int colCostsSize){
    int ret = 0;

    if (startPos[0] < homePos[0])
        for (int i = startPos[0] + 1; i <= homePos[0]; i++)
            ret += rowCosts[i];
    else if (startPos[0] > homePos[0])
        for (int i = startPos[0] - 1; i >= homePos[0]; i--)
            ret += rowCosts[i];

    if (startPos[1] < homePos[1])
        for (int i = startPos[1] + 1; i <= homePos[1]; i++)
            ret += colCosts[i];
    else if (startPos[1] > homePos[1])
        for (int i = startPos[1] - 1; i >= homePos[1]; i--)
            ret += colCosts[i];

    return ret;
}
