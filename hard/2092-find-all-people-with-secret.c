#include <stdlib.h>

static void swap (int ** a, int ** b) {
    int * tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

static int ** sort (int ** meetings, int meetingsSize) {
    for (int i = 0, swapped = 0; i < meetingsSize - 1; i++, swapped = 0) {
        for (int j = 0; j < meetingsSize - 1 - i; j++)
            if (meetings[j][2] > meetings[j + 1][2]) {
                swap(meetings + j, meetings + j + 1);
                swapped = 1;
            }
        if (!swapped)
            break;
    }
    return meetings;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * findAllPeople (int n, int ** meetings, int meetingsSize, int * meetingsColSize, int firstPerson, int * returnSize) {
    int * ret = malloc(sizeof *ret * n);
    char * sec = malloc(sizeof *sec * n);

    *returnSize = 2;
    ret[0] = 0;
    ret[1] = firstPerson;

    for (int i = 1; i < n; i++)
        sec[i] = 0;
    sec[0] = 1;
    sec[firstPerson] = 1;

    meetings = sort(meetings, meetingsSize);
    for (int i = 0; i < meetingsSize; i++) {
        if (!(sec[meetings[i][0]] | sec[meetings[i][1]]) || sec[meetings[i][0]] & sec[meetings[i][1]])
            continue;
        if (sec[meetings[i][0]]) {
            sec[meetings[i][1]] = 1;
            ret[(*returnSize)++] = meetings[i][1];
        } else {
            sec[meetings[i][0]] = 1;
            ret[(*returnSize)++] = meetings[i][0];
        }
    }

    free(sec);
    return ret;
}
