#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lib/array.h>

int * parseArgsToIntegerArray (int argc, char ** argv, int startingIndex, int arraySize) {
    int * input;

    input = malloc (sizeof *input * arraySize);

    for (int i = 0; i < arraySize; i++) {
        input[i] = atoi (argv[startingIndex + i]);
    }

    return input;
}

char ** parseArgsToStringArray (int argc, char ** argv, int startingIndex, int arraySize) {
    char ** returnedArray;
    int maxElementLength = 0;

    for (int i = 0, stringLength; i < arraySize; i++) {
        if (maxElementLength < (stringLength = strlen (argv[startingIndex + i]))) {
            maxElementLength = stringLength;
        }
    }

    returnedArray = malloc (sizeof *returnedArray * arraySize);

    for (int i = 0; i < arraySize; i++) {
        returnedArray[i] = malloc (sizeof *returnedArray[i] * (maxElementLength + 1));
        strncpy (returnedArray[i], argv[startingIndex + i], strlen (argv[startingIndex + i]) + 1);
    }

    return returnedArray;
}

/// @brief Parse arguments as a integer matrix of specific columns.  If there are
/// empty slots left in the matrix, fill them with 0s.
/// @param argc the original argument count
/// @param argv the original arguments
/// @param startingIndex the index of the first matrix element in arguments
/// @param elementCount the number of elements of the matrix
/// @param column column number of the matrix
/// @return the integer matrix
int ** parseArgsToIntegerMatrix (int argc, char ** argv, int startingIndex, int elementCount, int column) {
    int row = matrixGetRow (elementCount, column);
    int ** returnedMatrix;

    returnedMatrix = malloc (sizeof *returnedMatrix * row);
    for (int i = 0; i < row; i++) {
        returnedMatrix[i] = malloc (sizeof **returnedMatrix * column);
        for (int j = 0, currentIndex; j < column; j++) {
            returnedMatrix[i][j] = ((currentIndex = column * i + j) < elementCount) ? atoi (argv[startingIndex + currentIndex]) : 0;
        }
    }

    return returnedMatrix;
}

void printIntegerArray (int * array, int size) {
    printf ("[");
    for (int i = 0; i < size - 1; i++) {
        printf ("%d, ", array[i]);
    }
    if (size > 0) {
        printf ("%d", array[size - 1]);
    }
    printf ("]\n");
}

void printStringArray (char ** array, int size) {
    printf ("[");
    for (int i = 0; i < size - 1; i++) {
        printf ("`%s', ", array[i]);
    }
    if (size > 0) {
        printf ("`%s'", array[size - 1]);
    }
    printf ("]\n");
}

void printIntegerArrays (int ** arrays, int size, int * arraysSize) {
    for (int i = 0; i < size; i++) {
        printIntegerArray (arrays[i], arraysSize[i]);
    }
}

void printIntegerMatrix (int ** matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf ("%3d ", matrix[i][j]);
        }
        printf ("\n");
    }
}

void freeStringArray (char ** array, int size) {
    while (size > 0) {
        free (array[--size]);
    }
    free (array);
}

void freeIntegerMatrix (int ** matrix, int row) {
    for (int i = 0; i < row; i++) {
        free (matrix[i]);
    }
    free (matrix);
}
