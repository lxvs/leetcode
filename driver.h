#ifndef INCLUDED_DRIVER_H_
#define INCLUDED_DRIVER_H_

#include <stdio.h>
#include "build/version.h"

#define EXEC            "lcd"
#define USAGE_PREFIX    "usage: " EXEC " "

#ifndef EXEC_VERSION
#define EXEC_VERSION "(version undefined)"
#endif

#define errorInputSizeMismatch(size1, size2, expectedTotal) \
    do { \
        fprintf (stderr, \
            "error: invalid number of arguments\n" \
            "Provided size are %d and %d (total %d), but the real total size is %d.\n", \
            size1, \
            size2, \
            (size1) + (size2), \
            expectedTotal); \
    } while (0)

#endif  /* INCLUDED_DRIVER_H_ */
