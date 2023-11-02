#include "2086-minimum-number-of-food-buckets-to-feed-the-hamsters.h"

int minimumBuckets (char * hamsters) {
    char ch;
    int i = -1;
    int houses = 0;
    int clearing = 0;
    int ret = 0;

    while ((ch = hamsters[++i])) {
        if (ch == 'H') {
            houses++;
            if (i > 0 && hamsters[i - 1] == 'B') {
                continue;
            }
            if (hamsters[i + 1] == 'H' || hamsters[i + 1] == '\0') {
                if (i > 0 && hamsters[i - 1] == '.') {
                    hamsters[i - 1] = 'B';
                    ret++;
                    continue;
                } else {
                    return -1;
                }
            }
            hamsters[i + 1] = 'B';
            ret++;
        } else {
            clearing++;
        }
    }

    if (houses == 0) {
        return 0;
    }

    if (clearing == 0) {
        return -1;
    }

    return ret;
}
