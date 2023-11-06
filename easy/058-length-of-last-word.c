#include "058-length-of-last-word.h"

int lengthOfLastWord (char * s) {
    int length = 0;
    int lastLength = 0;
    char c;

    while ((c = *s++) != '\0') {
        if (c == ' ') {
            if (length == 0) {
                continue;
            }
            lastLength = length;
            length = 0;
            continue;
        }
        if (length++ == 0) {
            lastLength = 0;
        }
    }

    return (lastLength == 0) ? length : lastLength;
}
