#include "003-longest-substring-without-repeating-characters.h"
#include "026-remove-duplicates-from-sorted-array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * usage_string = "./driver <id> [<argument> ...]";

int lc003_LongestSubstring (int argc, char ** argv) {
	if (argc < 1)
		return -1;
	return lengthOfLongestSubstring(argv[0]);
}

int lc026_RmDup(int argc, char ** argv) {

	int nums[NUMS_SIZE];

	for (int i=0; i<NUMS_SIZE; i++) {
		nums[i] = i/2;
	}

	printArray(nums, NUMS_SIZE);
	removeDuplicates(nums, NUMS_SIZE);
	printf("after removal:\n");
	printArray(nums, NUMS_SIZE);

	return 0;
}

void Usage (void) {
	printf("Usage:");
}

int main (int argc, char **argv) {
	int ret;
	int num;

	if (argc < 2) {
		fprintf(stderr, "error: Too few arguments.\n");
		fprintf(stderr, "Usage: %s\n", usage_string);
		exit(1);
	}

	num = atoi(argv[1]);

	if (num <= 0) {
		fprintf(stderr, "error: Number must be greater than 0.\n");
		return 1;
	}

	switch(num) {
		case 3:
			ret = lc003_LongestSubstring (argc - 2, argv + 2);
			break;
		case 26:
			ret = lc026_RmDup (argc - 2, argv + 2);
			break;
		default:
			fprintf(stderr, "error: There is no driver for %d yet!\n", num);
			ret = 1;
			break;
	}

	if (ret)
		fprintf(stderr, "warning: Return value is %d\n", ret);
	return ret;
}
