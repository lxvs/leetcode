#include <stdio.h>
#include "003-longest-substring-without-repeating-characters.h"

int lengthOfLongestSubstring (const char * s) {
    const char * ps = s;
    int end = 0;
    int p = 0;
    int max = 0;
    int count = 0;
    char failed = 0;

    while(*(ps + end++) != '\0') {
        count++;
        p = 0;
        while(p < end) {
            if(*(ps + p++) == *(ps + end)) {
                failed = 1;
                break;
            }
        }
        if(!failed)
            continue;
        if (count > max)
            max = count;
        ps += p;
        count = failed = end = 0;
    }
    if (count > max)
        max = count;
    return max;
}
