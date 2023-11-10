#include <stdlib.h>
#include "1743-restore-the-array-from-adjacent-pairs.h"

#define ELEMENT_VALUE_MAX   100000
#define ELEMENT_VALUE_MIN   (-100000)

int * restoreArray (int ** adjacentPairs, int adjacentPairsSize, int * adjacentPairsColSize, int * returnSize) {
    int * returnArray = malloc (sizeof *returnArray * (adjacentPairsSize + 1));
    int * hashTable = calloc (ELEMENT_VALUE_MAX - ELEMENT_VALUE_MIN + 1, sizeof *hashTable);
    *returnSize = 0;

    for (int i = 0; i < adjacentPairsSize * 2; i++) {
        hashTable[adjacentPairs[i / 2][i % 2] - ELEMENT_VALUE_MIN]++;
    }

    while (*returnSize < adjacentPairsSize + 1) {
        for (int i = 0; i < adjacentPairsSize * 2; i++) {
            if ((hashTable[adjacentPairs[i / 2][i % 2] - ELEMENT_VALUE_MIN] == 1)
                && (hashTable[adjacentPairs[i / 2][(i % 2) ^ 1] - ELEMENT_VALUE_MIN] >= 1)) {
                if (*returnSize == 0) {
                    hashTable[(returnArray[(*returnSize)++] = adjacentPairs[i / 2][i % 2]) - ELEMENT_VALUE_MIN]--;
                    hashTable[(returnArray[(*returnSize)++] = adjacentPairs[i / 2][(i % 2) ^ 1]) - ELEMENT_VALUE_MIN]--;
                } else if (adjacentPairs[i / 2][(i % 2) ^ 1] == returnArray[*returnSize - 1]) {
                    hashTable[returnArray[*returnSize - 1] - ELEMENT_VALUE_MIN]--;
                    hashTable[(returnArray[(*returnSize)++] = adjacentPairs[i / 2][i % 2]) - ELEMENT_VALUE_MIN]--;
                    break;
                } else if (adjacentPairs[i / 2][i % 2] == returnArray[*returnSize - 1]) {
                    hashTable[returnArray[*returnSize - 1] - ELEMENT_VALUE_MIN]--;
                    hashTable[(returnArray[(*returnSize)++] = adjacentPairs[i / 2][(i % 2) ^ 1]) - ELEMENT_VALUE_MIN]--;
                    break;
                }
                continue;
            }
        }
    }

    free (hashTable);
    return returnArray;
}
