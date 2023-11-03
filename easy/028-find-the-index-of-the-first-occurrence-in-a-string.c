#include <string.h>
#include "028-find-the-index-of-the-first-occurrence-in-a-string.h"

int strStr (char * haystack, char * needle) {
    int needleLength;
    int haystackLength;

    if ((needleLength = strlen (needle)) > (haystackLength = strlen (haystack))) {
        return -1;
    }

    for (int i = 0; i < haystackLength - needleLength + 1; i++) {
        if (strncmp (needle, haystack + i, needleLength) == 0) {
            return i;
        }
    }

    return -1;
}
