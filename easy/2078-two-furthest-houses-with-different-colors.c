#include "2078-two-furthest-houses-with-different-colors.h"

int maxDistance (int * colors, int colorsSize) {
    int dist;
    int max = 0;

    for (int i = 0; i < colorsSize - 1; i++) {
        dist = 0;
        for (int j = colorsSize - 1; j > i; j--) {
            if (colors[i] == colors[j])
                continue;
            dist = j - i;
            if (dist > max)
                max = dist;
            break;
        }
    }

    return max;
}
