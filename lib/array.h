#ifndef INCLUDED_ARRAY_H_
#define INCLUDED_ARRAY_H_

int * parseArgsToIntArray (const int argc, char ** argv);
int ** parseArgsToIntMatrix (const int argc, char ** argv);
void printIntArray (const int * nums, int size);
void printIntMatrix (int ** matrix, int r, int c);

#endif
