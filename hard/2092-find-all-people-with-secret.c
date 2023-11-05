#include <stdlib.h>
#include "2092-find-all-people-with-secret.h"

static void swap (int ** a, int ** b) {
    int * tmp = *a;
    *a = *b;
    *b = tmp;
}

static int ** sort (int ** meetings, int meetingsSize) {
    for (int i = 0, swapped = 0; i < meetingsSize - 1; i++, swapped = 0) {
        for (int j = 0; j < meetingsSize - 1 - i; j++) {
            if (meetings[j][2] > meetings[j + 1][2]) {
                swap (meetings + j, meetings + j + 1);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    return meetings;
}

int * findAllPeople (int n, int ** meetings, int meetingsSize, int * meetingsColSize, int firstPerson, int * returnSize) {
    int * returnArray = malloc (sizeof *returnArray * n);
    char * secret = malloc (sizeof *secret * n);

    *returnSize = 2;
    returnArray[0] = 0;
    returnArray[1] = firstPerson;

    for (int i = 1; i < n; i++) {
        secret[i] = 0;
    }
    secret[0] = 1;
    secret[firstPerson] = 1;

    meetings = sort (meetings, meetingsSize);
    for (int i = 0; i < meetingsSize; i++) {
        if ((secret[meetings[i][0]] | secret[meetings[i][1]]) == 0 || (secret[meetings[i][0]] & secret[meetings[i][1]]) != 0) {
            continue;
        }
        if (secret[meetings[i][0]]) {
            secret[meetings[i][1]] = 1;
            returnArray[(*returnSize)++] = meetings[i][1];
        } else {
            secret[meetings[i][0]] = 1;
            returnArray[(*returnSize)++] = meetings[i][0];
        }
    }

    free (secret);
    return returnArray;
}
