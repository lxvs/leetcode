#include <stdlib.h>
#include "1637-widest-vertical-area-between-two-points-containing-no-points.h"

static inline void swap (int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void quick_sort (int * array, int start_index, int end_index) {
    int pivot_index = start_index;
    int pivot;
    char luck = 0;

    if (start_index >= end_index) {
        return;
    }

    pivot = array[pivot_index];

    for (int i = start_index + 1; i <= end_index; i++) {
        if (array[i] < pivot || (array[i] == pivot && (luck = !luck))) {
            swap (&array[i], &array[++pivot_index]);
        }
    }
    swap (&array[start_index], &array[pivot_index]);

    quick_sort (array, start_index, pivot_index - 1);
    quick_sort (array, pivot_index + 1, end_index);
}

int maxWidthOfVerticalArea (int ** points, int pointsSize, int * pointsColSize) {
    int * x = malloc (sizeof *x * pointsSize);
    int max_width = 0;

    for (int i = 0; i < pointsSize; i++) {
        x[i] = points[i][0];
    }

    quick_sort (x, 0, pointsSize - 1);

    for (int i = 1; i < pointsSize; i++) {
        if (x[i] - x[i - 1] > max_width) {
            max_width = x[i] - x[i - 1];
        }
    }

    free (x);
    return max_width;
}
