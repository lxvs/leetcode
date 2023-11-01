#include <stdlib.h>
#include <string.h>
#include "014-longest-common-prefix.h"

char * longestCommonPrefix (char ** strs, int strsSize) {
    char * ret;
    int maxCommonLength = strlen (strs[0]);

    for (int i = 0, j = 0; i < strsSize; i++, j = 0) {
        while (j < maxCommonLength && strs[i][j] == strs[0][j]) {
            j++;
        }
        if (j < maxCommonLength) {
            maxCommonLength = j;
        }
    }

    ret = malloc ((maxCommonLength + 1) * sizeof *ret);
    strncpy (ret, strs[0], maxCommonLength);
    ret[maxCommonLength] = '\0';

    return ret;
}
