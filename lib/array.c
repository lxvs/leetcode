#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int * parseArgsToIntArray (const int argc, char ** argv) {
    int * input;

    if (argc < 1)
        return NULL;

    input = malloc(sizeof *input * argc);

    if (!input) {
        fprintf(stderr, "error: Failed to allocate memory.\n");
        return NULL;
    }

    for (int i = 0; i < argc; i++)
        input[i] = atoi(argv[i]);

    return input;
}

int ** parseArgsToIntMatrix (const int argc, char ** argv) {
    int c = atoi(*argv);
    int r;
    int ** ret;

    if (argc < 2) {
        fprintf(stderr, "parseArgsToIntMatrix error: Too few arguments\n");
        return NULL;
    }

    if (!c) {
        fprintf(stderr, "parseArgsToIntMatrix error: Cannot create a matrix of 0 column.\n");
        return NULL;
    }

    if ((argc - 1) % c) {
        fprintf(stderr,
                "parseArgsToIntMatrix error: Cannot create a matrix of %d columns out of %d %s.\n",
                c, argc - 1, argc - 1 > 1 ? "numbers" : "number");
        return NULL;
    }

    r = (argc - 1) / c;

    ret = malloc(sizeof *ret * r);
    for (int i = 0; i < r; i++)
        ret[i] = malloc(sizeof **ret * c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ret[i][j] = atoi(argv[1 + i * c + j]);

    return ret;
}

void printIntArray (const int * nums, int size) {
    for (int i = 0; i < size; i++)
        fprintf(stdout, "nums[%2d] = %d\n", i, nums[i]);
    return;
}

void printIntMatrix (int ** matrix, int r, int c) {
    fprintf(stdout, " r\\c");
    for (int j = 0; j < c; j++)
        fprintf(stdout, "  %2d  ", j);
    putchar('\n');

    for (int i = 0; i < r; i++) {
        fprintf(stdout, "%2d  ", i);
        for (int j = 0; j < c; j++)
            fprintf(stdout, "  %4d", matrix[i][j]);
        putchar('\n');
    }

    return;
}

void freeIntMatrix (int ** matrix, int row) {
    for (int i = 0; i < row; i++) {
        free (matrix[i]);
    }
    free (matrix);
}
