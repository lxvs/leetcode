#ifndef __DEBUG_H__
#define __DEBUG_H__

#if DEBUG
#include <stdio.h>

#define dbgline                 fprintf(stderr, "debug: %s:%d:%s()\n", __FILE__, __LINE__, __func__)
#define dbg(fmt, args...)       fprintf(stderr, "debug: %s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##args)
#else
#define dbgline
#define dbg(...)
#endif
#endif /* __DEBUG_H__ */
