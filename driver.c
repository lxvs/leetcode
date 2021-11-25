#include "003-longest-substring-without-repeating-characters.h"
#include "009-palindrome-number.h"
#include "021-merge-two-sorted-lists.h"
#include "026-remove-duplicates-from-sorted-array.h"
#include "036-valid-sudoku.h"
#include "053-maximum-subarray.h"
#include "074-search-a-2d-matrix.h"
#include "083-remove-duplicates-from-sorted-list.h"
#include "088-merge-sorted-array.h"
#include "118-pascals-triangle.h"
#include "121-best-time-to-buy-and-sell-stock.h"
#include "206-reverse-linked-list.h"
#include "217-contains-duplicate.h"
#include "234-palindrome-linked-list.h"
#include "242-valid-anagram.h"
#include "350-intersection-of-two-arrays-ii.h"
#include "383-ransom-note.h"
#include "387-first-unique-character-in-a-string.h"
#include "566-reshape-the-matrix.h"
#include "5930-two-furthest-houses-with-different-colors.h"

#include "lib/llist.h"
#include "lib/debug.h"

#include <stdio.h>
#include <stdlib.h>

#define EXEC    "lcdriver"
static int * pargia (const int argc, char ** argv);
static int ** pargim (const int argc, char ** argv);
static void printia (const int * nums, int size);
static void printim (int ** matrix, int r, int c);

const char * usage_string = EXEC " <id> [<argument> ...]";

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

int lc021_Merge2LinkedLists (int argc, char ** argv) {
    Node * l1 = NULL;
    Node * l2 = NULL;
    Node * ret;
    int len1, len2;
    const char * usage =
        "Usage:\n"
        "\n"
        "    " EXEC " 21 <l1.len> <l2.len> [<l1.val> ...] [<l2.val> ...]\n"
        "\n"
        "Merge linked list l1 and l2.\n";

    if (argc < 2) {
        fprintf(stdout, "%s", usage);
        return 0;
    }

    len1 = atoi(argv[0]);
    len2 = atoi(argv[1]);

    if (len1 + len2 != argc - 2)
        return -1;

    for (int i = 0; i < len1 + len2; i++) {
        if (i < len1)
            l1 = AddValue(l1, atoi(argv[2 + i]));
        else
            l2 = AddValue(l2, atoi(argv[2 + i]));
    }

#if DEBUG
    fprintf(stdout, "Input lists:\n");
    PrintList(l1);
    putchar('\n');
    PrintList(l2);
    putchar('\n');
#endif

    ret = mergeTwoLists(l1, l2);

    fprintf(stdout, "Merged lists:\n");
    PrintList(ret);

    free(ret);
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

int lc036_ValidSudoku (int argc, char ** argv) {
    char ** input = malloc(sizeof *input * 9);
    char valid[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    for (int i = 0; i < 9; i++) {
        input[i] = malloc(sizeof **input * 9);
        for (int j = 0; j < 9; j++)
            input[i][j] = valid[i][j];
    }

    fprintf(stdout, "Expected: true. Got: %s\n",
            isValidSudoku(input, 9, NULL) ? "true" : "false");

    input[0][0] = '8';

    fprintf(stdout, "Expected: false. Got: %s\n",
            isValidSudoku(input, 9, NULL) ? "true" : "false");

    return 0;
}

int lc053_MaxSubarray (int argc, char ** argv) {
    int * input = pargia(argc, argv);
    int ret;

    if (!input)
        return -1;

    ret = maxSubArray(input, argc);
    free(input);
    return ret;
}

int lc074_Search2dMatrix (int argc, char ** argv) {
    int ** input;
    int t;
    int r;
    int c;
    int * csz;

    if (argc < 3) {
        fprintf(stdout,
                "Usage:\n"
                "\n"
                "    " EXEC " 74 <target> <col> <numbers> ...\n");
        return 0;
    }

    input = pargim(argc - 1, argv + 1);

    if (!input)
        return -1;

    t = atoi(argv[0]);
    c = atoi(argv[1]);
    r = (argc - 2) / c;
    fprintf(stdout, "input matrix:\n");
    printim(input, r, c);
    putchar('\n');

    csz = malloc(sizeof *csz * r);
    for (int i = 0; i < r; i++)
        csz[i] = c;

    fprintf(stdout, "%s target %d\n.",
            searchMatrix(input, r, csz, t) ? "Found" : "Couldn't find",
            t);

    return 0;
}

int lc083_RemoveDupFromSortedList (int argc, char ** argv) {
    Node * input = NULL;
    Node * ret;

    while (*argv)
        input = AddValue(input, atoi(*argv++));

    ret = deleteDuplicates(input);
    PrintList(ret);

    free(ret);
    return 0;
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

int lc118_PascalsTriangle (int argc, char ** argv) {
    int row;
    int retrow[1];
    int *retcols[1];
    int ** ret;

    if (argc != 1) {
        fprintf(stdout,
                "Usage:\n"
                "\n"
                "    " EXEC " 118 <row>\n"
                "\n"
                "Generate a Pascal's triangle of <row> row(s)\n");
        return 0;
    }

    row = atoi(*argv);

    if (row < 1 || row > 20)
        return -1;

    ret = generate(row, retrow, retcols);

    for (int i = 0; i < *retrow; i++)
        for (int j = 0; j < (*retcols)[i]; j++)
            fprintf(stdout, "ret[%d][%d] = %d\n", i, j, ret[i][j]);

    return 0;
}

int lc121_MaxProfit(int argc, char ** argv) {
    int * input = pargia(argc, argv);
    int ret;

    if (!input)
        return -1;

    ret = maxProfit(input, argc);
    free(input);
    return ret;
}

int lc206_ReverseLinkedList (int argc, char ** argv) {
    Node * input = NULL;
    Node * ret;

    while (*argv)
        input = AddValue(input, atoi(*argv++));

    ret = reverseList(input);

    PrintList(ret);

    free(ret);
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

int lc242_ValidAnagram (int argc, char ** argv) {
    if (argc < 2)
        return -1;

    fprintf(stdout, "%s\n",
            isAnagram(argv[0], argv[1]) ? "True" : "False");

    return 0;
}

int lc350_Intersection (int argc, char ** argv) {
    int * input = pargia(argc, argv);
    int * nums2 = NULL;
    int nums2Size[1];
    int * ret = NULL;
    int retsz[1];

    if (!input)
        return -1;

    fprintf(stdout, "How many numbers in nums2? ");
    scanf("%d", nums2Size);
    nums2 = malloc(sizeof *nums2 * *nums2Size);
    fprintf(stdout, "Input nums2, separated with spaces: ");
    for (int i = 0; i < *nums2Size; i++)
        if (scanf("%d", nums2 + i) != 1) {
            fprintf(stderr, "Error in parsing input.\n");
            return -1;
        }

    fprintf(stdout, "nums1:\n");
    printia(input, argc);
    fprintf(stdout, "nums2:\n");
    printia(nums2, *nums2Size);
    putchar('\n');

    ret = intersect(input, argc, nums2, *nums2Size, retsz);

    fprintf(stdout, "return:\n");
    printia(ret, *retsz);

    free(input);
    free(ret);

    return 0;
}

int lc383_RansomNote (int argc, char ** argv) {
    const char * usage =
        "Usage:\n"
        "\n"
        "    " EXEC " 383 <note> <magazine>\n";

    if (argc < 2) {
        fprintf(stdout, "%s", usage);
        return 0;
    }

    fprintf(stdout, "%s\n",
            canConstruct(argv[0], argv[1]) ? "True" : "False");

    return 0;
}

int lc387_FirstUniqueChar (int argc, char ** argv) {
    if (argc - 1) {
        fprintf(stdout,
                "Usage:\n"
                "\n"
                "    " EXEC " 387 <string>\n");
        return 0;
    }

    return firstUniqChar(*argv);
}

int lc566_MatrixReshape (int argc, char ** argv) {
    int ** input;
    int r, c, m, n;
    int ** reshaped;
    int retr[1];
    int * retc[1];

    if (argc < 4) {
        fprintf(stdout,
                "Usage:\n"
                "\n"
                "    " EXEC " 566 <r> <c> <col> <numbers> ...\n"
                "\n"
                "    <r> <c>     the number of rows/columns of reshaped matrix\n"
                "    <col>       the number of columns of input matrix\n"
                "    <numbers>   matrix elements in row-traversing order\n");
        return 0;
    }

    input = pargim(argc - 2, argv + 2);

    if (!input)
        return -1;

    r = atoi(argv[0]);
    c = atoi(argv[1]);
    n = atoi(argv[2]);
    m = (argc - 3) / n;

    fprintf(stdout, "Input matrix:\n");
    printim(input, m, n);

    reshaped = matrixReshape(input, m, &n, r, c, retr, retc);

    fprintf(stdout, "Reshaped:\n");
    printim(reshaped, *retr, **retc);

    if (reshaped != input)
        free(reshaped);
    if (*retc != &n)
        free(*retc);
    free(input);
    return 0;
}

int lc5930_maxDistance (int argc, char ** argv) {
    int * input = pargia(argc, argv);
    int ret;

    ret = maxDistance(input, argc);
    free(input);

    return ret;
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
        case 21:
            ret = lc021_Merge2LinkedLists (argc - 2, argv + 2);
            break;
        case 26:
            ret = lc026_RmDup (argc - 2, argv + 2);
            break;
        case 36:
            ret = lc036_ValidSudoku (argc - 2, argv + 2);
            break;
        case 53:
            ret = lc053_MaxSubarray (argc - 2, argv + 2);
            break;
        case 74:
            ret = lc074_Search2dMatrix (argc - 2, argv + 2);
            break;
        case 83:
            ret = lc083_RemoveDupFromSortedList (argc - 2, argv + 2);
            break;
        case 88:
            ret = lc088_MergeNums (argc - 2, argv + 2);
            break;
        case 118:
            ret = lc118_PascalsTriangle (argc - 2, argv + 2);
            break;
        case 121:
            ret = lc121_MaxProfit (argc - 2, argv + 2);
            break;
        case 206:
            ret = lc206_ReverseLinkedList (argc - 2, argv + 2);
            break;
        case 217:
            ret = lc217_ContainsDup (argc - 2, argv + 2);
            break;
        case 234:
            ret = lc234_Palindrome_ll (argc - 2, argv + 2);
            break;
        case 242:
            ret = lc242_ValidAnagram (argc - 2, argv + 2);
            break;
        case 350:
            ret = lc350_Intersection (argc - 2, argv + 2);
            break;
        case 383:
            ret = lc383_RansomNote (argc - 2, argv + 2);
            break;
        case 387:
            ret = lc387_FirstUniqueChar (argc - 2, argv + 2);
            break;
        case 566:
            ret = lc566_MatrixReshape (argc - 2, argv + 2);
            break;
        case 5930:
            ret = lc5930_maxDistance (argc - 2, argv + 2);
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

/*
 * Parse arguments - int matrix
 *
 * argv[0] is the number of columns.
 */
static int ** pargim (const int argc, char ** argv) {
    int c = atoi(*argv);
    int r;
    int ** ret;

    if (argc < 2) {
        fprintf(stderr, "pargim error: Too few arguments\n");
        return NULL;
    }

    if (!c) {
        fprintf(stderr, "pargim error: Cannot create a matrix of 0 column.\n");
        return NULL;
    }

    if ((argc - 1) % c) {
        fprintf(stderr,
                "pargim error: Cannot create a matrix of %d columns out of %d %s.\n",
                c, argc - 1, argc - 1 > 1 ? "numbers" : "number");
        return NULL;
    }

    r = (argc - 1) / c;

    ret = malloc(sizeof *ret * r);
    for (int i = 0; i < r; i++)
        ret[i] = malloc(sizeof **ret * c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ret[i][j] = atoi(argv[1 + i * c + j]);

    return ret;
}

static void printia (const int * nums, int size) {
    for (int i = 0; i < size; i++)
        fprintf(stdout, "nums[%2d] = %d\n", i, nums[i]);
    return;
}

static void printim (int ** matrix, int r, int c) {
    fprintf(stdout, " r\\c");
    for (int j = 0; j < c; j++)
        fprintf(stdout, "  %2d  ", j);
    putchar('\n');

    for (int i = 0; i < r; i++) {
        fprintf(stdout, "%2d  ", i);
        for (int j = 0; j < c; j++)
            fprintf(stdout, "  %4d", matrix[i][j]);
        putchar('\n');
    }

    return;
}
