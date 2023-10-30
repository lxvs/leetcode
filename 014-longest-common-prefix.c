#include <stdlib.h>
#include <string.h>
#include "014-longest-common-prefix.h"

char * longestCommonPrefix (char ** strs, int strsSize) {
    char * ret;
    int indexOfMax = 0;
    int maxCommonLength = strlen (strs[0]);

    for (int i = 0, j; i < strsSize; i++) {
        for (j = 0; j < maxCommonLength; j++) {
            if (strs[i][j] != strs[indexOfMax][j]) {
                break;
            }
        }
        if (j < maxCommonLength) {
            maxCommonLength = j;
            indexOfMax = i;
        }
    }

    ret = malloc ((maxCommonLength + 1) * sizeof *ret);
    strncpy (ret, strs[indexOfMax], maxCommonLength);
    ret[maxCommonLength] = '\0';

    return ret;
}
