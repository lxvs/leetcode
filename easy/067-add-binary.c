#include <stdlib.h>
#include <string.h>
#include "067-add-binary.h"

#define max(a, b)       (((a) > (b)) ? (a) : (b))
#define min(a, b)       (((a) > (b)) ? (b) : (a))

char * addBinary (char * a, char * b) {
    char carry = '0';
    int lengthA = strlen (a);
    int lengthB = strlen (b);
    int lengthLonger = max (lengthA, lengthB);
    int lengthShorter = min (lengthA, lengthB);
    char * longer = (lengthLonger == lengthA) ? a : b;
    char * shorter = (lengthLonger == lengthA) ? b : a;
    char * sum = malloc (sizeof *sum * (lengthLonger + 2));

    sum[lengthLonger + 1] = '\0';
    for (int i = lengthLonger - 1; i > lengthLonger - lengthShorter - 1; i--) {
        sum[i + 1] = (longer[i] - '0') + (shorter[i - (lengthLonger - lengthShorter)] - '0') + carry;
        carry = '0';
        while (sum[i + 1] >= '2') {
            sum[i + 1] -= 2;
            carry++;
        }
    }
    for (int i = lengthLonger - lengthShorter - 1; i >= 0; i--) {
        sum[i + 1] = (longer[i] - '0') + carry;
        carry = '0';
        while (sum[i + 1] >= '2') {
            sum[i + 1] -= 2;
            carry++;
        }
    }

    sum[0] = carry;
    if (sum[0] == '0') {
        char * sumToBeFreed = sum;
        char * p = malloc (sizeof *p * (lengthLonger + 1));
        memcpy (p, sum + 1, sizeof *p * (lengthLonger + 1));
        sum = p;
        free (sumToBeFreed);
    }

    return sum;
}
