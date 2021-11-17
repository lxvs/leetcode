#include "003-longest-substring-without-repeating-characters.h"
#include <stdio.h>

#define DEBUG 0

int lengthOfLongestSubstring (const char * s) {
	const char * ps = s;
	int end = 0;
	int p = 0;
	int max = 0;
	int count = 0;
	char failed = 0;

	while(*(ps + end++) != '\0') {
		count++;
		p = 0;
		while(p < end) {
			if(*(ps + p++) == *(ps + end)) {
				failed = 1;
				break;
			}
		}
#if DEBUG
		fprintf (stdout,
				"%5s %5s %5s %5s %5s %6s %3s\n"
				"%5ld %5d %5d %5d %5d %6d %3c\n",
				"start", "end", "p", "max", "count", "failed", "cur",
				ps - s, end, p, max, count, failed, *(ps + end - 1));
#endif
		if(!failed)
			continue;
		if (count > max)
			max = count;
		ps += end;
		count = failed = end = 0;
	}
	if (count > max)
		max = count;
	return max;
}
