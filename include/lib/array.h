#ifndef INCLUDED_ARRAY_H_
#define INCLUDED_ARRAY_H_

//
// Get the minimum row count of a matrix to place all elements.
//
#define matrixGetRow(elementCount, column) \
    (((elementCount) % (column) == 0) ? ((elementCount) / (column)) : ((elementCount) / (column) + 1))

int * parseArgsToIntArray (int argc, char ** argv, int startingIndex, int arraySize);

char ** parseArgsToStringArray (int argc, char ** argv, int startingIndex, int arraySize);

/// @brief Parse arguments as a integer matrix of specific columns.  If there are
/// empty slots left in the matrix, fill them with 0s.
/// @param argc the original argument count
/// @param argv the original arguments
/// @param startingIndex the index of the first matrix element in arguments
/// @param elementCount the number of elements of the matrix
/// @param column column number of the matrix
/// @return the integer matrix
int ** parseArgsToIntMatrix (int argc, char ** argv, int startingIndex, int elementCount, int column);

void printIntArray (int * nums, int size);

void printStringArray (char ** str, int size);

void printIntMatrix (int ** matrix, int row, int column);

void freeStringArray (char ** str, int arraySize);

void freeIntMatrix (int ** matrix, int row);

#endif
