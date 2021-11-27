#ifndef __5924_MINIMUM_COST_HOMECOMING_OF_A_ROBOT_IN_A_GRID_H__
#define __5924_MINIMUM_COST_HOMECOMING_OF_A_ROBOT_IN_A_GRID_H__

#if DEBUG
int ** minCostDbg (int * startPos, int startPosSize, int * homePos, int homePosSize, int * rowCosts, int rowCostsSize, int * colCosts, int colCostsSize);
#else
int minCost (int * startPos, int startPosSize, int * homePos, int homePosSize, int * rowCosts, int rowCostsSize, int * colCosts, int colCostsSize);
#endif

#endif /* __5924_MINIMUM_COST_HOMECOMING_OF_A_ROBOT_IN_A_GRID_H__ */
