#include <string.h>

int firstUniqChar(char * s){
    int alpha[26] = {0};
    int min = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int * p = alpha + s[i] - 'a';
        if (*p < 0)
            continue;
        if (*p == 0) {
            *p = i + 1;
            continue;
        }
        *p = -1;
    }

    for (int i = 0; i < 26; i++)
        if (alpha[i] > 0)
            min = (min == -1 || alpha[i] - 1 < min) ? alpha[i] - 1 : min;

    return min;
}
