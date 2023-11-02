#include <string.h>
#include "2085-count-common-words-with-one-occurrence.h"

int countWords (char ** words1, int words1Size, char ** words2, int words2Size) {
    int ret = 0;
    int notFount;

    for (int i = 0; i < words1Size; i++) {
        int count = 0;
        for (int j = 0; j < words1Size; j++)
            if (i != j && strcmp (words1[i], words1[j]) == 0) {
                count++;
                break;
            }
        if (count != 0) {
            continue;
        }
        notFount = -1;
        for (int j = 0; j < words2Size; j++) {
            if (strcmp(words2[j], words1[i]) == 0) {
                notFount++;
            }
        }
        if (notFount == 0) {
            ret++;
        }
    }

    return ret;
}
