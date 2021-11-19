#include "003-longest-substring-without-repeating-characters.h"
#include "009-palindrome-number.h"
#include "026-remove-duplicates-from-sorted-array.h"
#include "053-maximum-subarray.h"
#include "088-merge-sorted-array.h"
#include "217-contains-duplicate.h"
#include "234-palindrome-linked-list.h"

#include "driver.h"
#include "lib/llist.h"

#include <stdio.h>
#include <stdlib.h>

const char * usage_string = "./driver <id> [<argument> ...]";

int lc003_LongestSubstring (int argc, char ** argv) {
    if (argc < 1)
        return -1;
    return lengthOfLongestSubstring(argv[0]);
}

int lc009_Palindrome (int argc, char ** argv) {
    int num;

    while (*argv) {
        num = atoi(*argv++);
        fprintf(stdout, "%d %s a palindrome number.\n",
                num, isPalindrome(num) ? "is" : "isn't");
    }

    return 0;
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

int lc053_MaxSubarray (int argc, char ** argv) {
    int * input = pargia(argc, argv);

    if (!input)
        return -1;

    return maxSubArray(input, argc);
}

int lc088_MergeNums (int argc, char ** argv) {
    int nums1[1] = {0};
    int nums1Size = 1;
    int m = 0;
    int nums2[1] = {1};
    int nums2Size = 1;
    int n = 1;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    printia(nums1, m + n);

    return 0;
}

int lc217_ContainsDup (int argc, char ** argv) {
    int * input = pargia(argc, argv);

    if (!input)
        return -1;

    fprintf(stdout, "%s\n", containsDuplicate(input, argc) ? "True" : "False");

    free(input);
    return 0;
}

int lc234_Palindrome_ll (int argc, char ** argv) {
    Node * input = NULL;

    while (*argv)
        input = AddValue(input, atoi(*argv++));

    fprintf(stdout, "%s\n",
            isPalindrome_ll(input) ? "True" : "False");

    free(input);
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
        case 9:
            ret = lc009_Palindrome (argc -2, argv + 2);
            break;
        case 26:
            ret = lc026_RmDup (argc - 2, argv + 2);
            break;
        case 53:
            ret = lc053_MaxSubarray (argc - 2, argv + 2);
            break;
        case 88:
            ret = lc088_MergeNums (argc - 2, argv + 2);
            break;
        case 217:
            ret = lc217_ContainsDup (argc - 2, argv + 2);
            break;
        case 234:
            ret = lc234_Palindrome_ll (argc - 2, argv + 2);
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

/*
 * Parse arguments - int array
 */
static int * pargia (const int argc, char ** argv) {
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

static void printia (const int * nums, int size) {
    for (int i = 0; i < size; i++)
        fprintf(stderr, "nums[%2d] = %d\n", i, nums[i]);
    return;
}
