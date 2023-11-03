#ifndef INCLUDED_DEBUG_H_
#define INCLUDED_DEBUG_H_

#if DEBUG
#include <stdio.h>

#define debug(fmt, args...)     fprintf (stderr, "debug: %s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##args)
#else
#define debug(...)
#endif
#endif  /* INCLUDED_DEBUG_H_ */
