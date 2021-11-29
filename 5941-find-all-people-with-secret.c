#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * findAllPeople (int n, int ** meetings, int meetingsSize, int * meetingsColSize, int firstPerson, int * returnSize) {
    int * ret = malloc(sizeof *ret * n);
    int * time = malloc(sizeof *time * n);

    *returnSize = 2;
    ret[0] = 0;
    ret[1] = firstPerson;

    for (int i = 1; i < n; i++)
        time[i] = -1;
    time[0] = 0;
    time[firstPerson] = 0;

    for (int i = 0; i < meetingsSize; i++) {
        int t = meetings[i][2];
        int * t0 = time + meetings[i][0];
        int * t1 = time + meetings[i][1];
        if (*t0 + *t1 == -2 || ((*t0 + 1) && (*t1 + 1)))
            continue;
        if (*t0 == -1) {
            if (t < *t1)
                continue;
            *t0 = t;
            ret[(*returnSize)++] = meetings[i][0];
        } else {
            if (t < *t0)
                continue;
            *t1 = t;
            ret[(*returnSize)++] = meetings[i][1];
        }
    }

    free(time);
    return ret;
}
