#include <string.h>

int countWords(char ** words1, int words1Size, char ** words2, int words2Size){
    int ret = 0;
    int b;
    int notfound;
    for (int i = 0; i < words1Size; i++) {
        b = 0;
        for (int j = 0; j < words1Size; j++)
            if (i != j && !strcmp(words1[i], words1[j])) {
                b++;
                break;
            }
        if (b)
            continue;
        notfound = -1;
        for (int j = 0; j < words2Size; j++)
            if (!strcmp(words2[j], words1[i]))
                notfound++;
        if (!notfound)
            ret++;
    }
    return ret;
}
