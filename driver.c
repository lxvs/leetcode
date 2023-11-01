#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lib/debug.h>
#include <lib/llist.h>
#include <lib/btree.h>
#include <lib/array.h>
#include "easy/001-two-sum.h"
#include "easy/009-palindrome-number.h"
#include "easy/013-roman-to-integer.h"
#include "easy/014-longest-common-prefix.h"
#include "easy/020-valid-parentheses.h"
#include "easy/021-merge-two-sorted-lists.h"
#include "easy/026-remove-duplicates-from-sorted-array.h"
#include "easy/027-remove-element.h"
#include "easy/083-remove-duplicates-from-sorted-list.h"
#include "easy/088-merge-sorted-array.h"
#include "easy/118-pascals-triangle.h"
#include "easy/121-best-time-to-buy-and-sell-stock.h"
#include "easy/206-reverse-linked-list.h"
#include "easy/217-contains-duplicate.h"
#include "easy/234-palindrome-linked-list.h"
#include "easy/242-valid-anagram.h"
#include "easy/350-intersection-of-two-arrays-ii.h"
#include "easy/383-ransom-note.h"
#include "easy/387-first-unique-character-in-a-string.h"
#include "easy/566-reshape-the-matrix.h"
#include "easy/977-squares-of-a-sorted-array.h"
#include "easy/1290-convert-binary-number-in-a-linked-list-to-integer.h"
#include "easy/2078-two-furthest-houses-with-different-colors.h"
#include "medium/002-add-two-numbers.h"
#include "medium/003-longest-substring-without-repeating-characters.h"
#include "medium/005-longest-palindromic-substring.h"
#include "medium/034-find-first-and-last-position-of-element-in-sorted-array.h"
#include "medium/036-valid-sudoku.h"
#include "medium/053-maximum-subarray.h"
#include "medium/074-search-a-2d-matrix.h"
#include "medium/098-validate-binary-search-tree.h"
#include "medium/102-binary-tree-level-order-traversal.h"
#include "medium/2087-minimum-cost-homecoming-of-a-robot-in-a-grid.h"
#include "hard/2092-find-all-people-with-secret.h"

#define EXEC    "lcdriver"

const char * usage_string = EXEC " <id> [<argument> ...]\n";

int lc001_TwoSums (int argc, char ** argv) {
    const char * usage = \
        "usage: " EXEC " 1 <target> <integer> <integer> [<integer> ...]\n" \
        "Return two different indices of the two integers such that they add up to target.\n";
    int * input;
    int * ret;
    int inputSize;
    int retSize[1] = {0};
    int target;

    if (argc < 3) {
        printf ("%s", usage);
        return 0;
    }

    inputSize = argc - 1;
    target = atoi (argv[0]);
    input = parseArgsToIntArray (inputSize, argv + 1);
    printf ("input array:\n");
    printIntArray (input, inputSize);
    ret = twoSum (input, inputSize, target, retSize);
    printf ("returned 2 indices:\n");
    printIntArray (ret, *retSize);

    free (input);
    free (ret);

    return 0;
}

int lc002_AddTwoNumbers (int argc, char ** argv) {
    const char * usage = \
        "usage: " EXEC " 2 <augend> <addend>\n" \
        "Return the sum of the 2 given numbers.\n";
    Node * augend = NULL;
    Node * addend = NULL;
    Node * sum = NULL;

    if (argc != 2) {
        printf ("%s", usage);
        return 0;
    }

    for (int i = 0, length = strlen (argv[0]); argv[0][i] != '\0'; i++) {
        augend = AddValue (augend, argv[0][length - i - 1] - '0');
    }

    for (int i = 0, length = strlen (argv[1]); argv[1][i] != '\0'; i++) {
        addend = AddValue (addend, argv[1][length - i - 1] - '0');
    }

    printf ("augend:\n");
    PrintList (augend);
    printf ("addend:\n");
    PrintList (addend);

    sum = addTwoNumbers (augend, addend);
    printf ("sum:\n");
    PrintList (sum);

    FreeLinkedList (augend);
    FreeLinkedList (addend);
    FreeLinkedList (sum);

    return 0;
}

int lc003_LongestSubstring (int argc, char ** argv) {
    if (argc < 1)
        return -1;
    return lengthOfLongestSubstring(argv[0]);
}

int lc005_LongestPalindromicSubstring (int argc, char ** argv) {
    char * ret;

    if (argc != 1) {
        fprintf (stderr, "error: it requires exact one argument.\n");
        return -1;
    }
    ret = longestPalindrome(*argv);
    fprintf (stdout, "Longest palindromic substring of `%s' is `%s'\n", *argv, ret);
    free (ret);
    return 0;
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

int lc013_RomanToInteger (int argc, char ** argv) {
    if (argc != 1) {
        return -1;
    }

    fprintf (stdout, "Roman numeral `%s' is integer `%d'\n", *argv, romanToInt (*argv));

    return 0;
}

int lc014_LongestCommonPrefix (int argc, char ** argv) {
    char ** input;
    char * ret;
    const char * usage = \
        "usage: " EXEC " 14 <string> [<string> ...]\n" \
        "\n" \
        "Find the longest common prefix of the strings.\n";

    if (argc < 1) {
        fprintf (stdout, "%s", usage);
        return 0;
    }

    input = parseArgsToStringArray (argc, argv);
    if (input == NULL) {
        return -1;
    }

    ret = longestCommonPrefix (argv, argc);
    fprintf (stdout, "Longest common prefix is `%s'\n", ret);

    free (ret);
    freeStringArray (input, argc);

    return 0;
}

int lc020_ValidParentheses (int argc, char ** argv) {
    if (argc != 1)
        return -1;

    fprintf(stdout, "%s\n", isValid(*argv) ? "Valid" : "Invalid");

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

    FreeLinkedList (ret);
    return 0;
}

int lc026_RmDup(int argc, char ** argv) {
    const char * usage = \
        "usage: " EXEC " 26 <integer> [<integer> ...]\n" \
        "Remove duplicated items from a non-decreasing integer array.\n";
    int * input;
    int newSize;

    if (argc < 1) {
        fprintf (stdout, "%s", usage);
        return 0;
    }

    input = parseArgsToIntArray (argc, argv);

    printf ("input array:\n");
    printIntArray (input, argc);

    newSize = removeDuplicates(input, argc);

    printf ("after removal of duplicated items:\n");
    printIntArray (input, newSize);

    free (input);
    return 0;
}

int lc027_RemoveElement (int argc, char ** argv) {
    const char * usage = \
        "usage: " EXEC " 27 <value> [<integer> ...]\n" \
        "Remove all occurrences of <value> in given integer array.\n" \
        "array size: [0, 100]\n" \
        "array element range: [0, 50]\n" \
        "value range: [0, 100]\n";
    int * input;
    int value;
    int arraySize;

    if (argc < 1) {
        printf ("%s", usage);
        return 0;
    }

    arraySize = argc - 1;
    value = atoi (argv[0]);
    input = parseArgsToIntArray (arraySize, argv + 1);
    printf ("input array:\n");
    printIntArray (input, arraySize);
    arraySize = removeElement (input, arraySize, value);
    printf ("after removal:\n");
    printIntArray (input, arraySize);

    free (input);
    return 0;
}

int lc034_FindPosOfElementsInSortedArray(int argc, char ** argv) {
    int target;
    int * input;
    int * ret;
    int retSize;
    const char * usage = \
        "usage: " EXEC " 34 <target> [<nums> ...]\n" \
        "\n" \
        "Find the starting and ending position of <target> in a non-decreasing sorted integer list.\n";

    if (argc < 1) {
        fprintf(stdout, "%s", usage);
        return 0;
    }

    target = atoi(*argv);
    input = parseArgsToIntArray(argc - 1, argv + 1);
    ret = searchRange(input, argc - 1, target, &retSize);

    printIntArray(ret, retSize);

    free(ret);
    free(input);

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
    int * input = parseArgsToIntArray(argc, argv);
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

    input = parseArgsToIntMatrix(argc - 1, argv + 1);

    if (!input)
        return -1;

    t = atoi(argv[0]);
    c = atoi(argv[1]);
    r = (argc - 2) / c;
    fprintf(stdout, "input matrix:\n");
    printIntMatrix(input, r, c);
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

    FreeLinkedList (ret);
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

    printIntArray(nums1, m + n);

    return 0;
}

int lc098_ValidBST (int argc, char ** argv) {
    tree_t * tree = NewNode(5);
    tree->left = NewNode(4);
    tree->right = NewNode(6);
    tree->right->left = NewNode(3);
    tree->right->right = NewNode(7);

    fprintf(stdout, "%s BST\n", isValidBST(tree) ? "Valid" : "Invalid");

    free(tree->right->right);
    free(tree->right->left);
    free(tree->right);
    free(tree->left);
    free(tree);
    return 0;
}

int lc102_BinTreeLevelTraversal (int argc, char ** argv) {
    tree_t * tree = NewNode(3);
    tree->left = NewNode(9);
    tree->right = NewNode(20);
    tree->right->left = NewNode(15);
    tree->right->right = NewNode(7);
    int retsz[1];
    int * retcsz[1];
    int ** ret = levelOrder(tree, retsz, retcsz);
    for (int i = 0; i < *retsz; i++) {
        for (int j = 0; j < retcsz[0][i]; j++)
            printf("%2d ", ret[i][j]);
        putchar('\n');
    }
    free(tree->right->right);
    free(tree->right->left);
    free(tree->right);
    free(tree->left);
    free(tree);
    free(retcsz[0]);
    free(ret);
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
    int * input = parseArgsToIntArray(argc, argv);
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

    FreeLinkedList (ret);
    return 0;
}

int lc217_ContainsDup (int argc, char ** argv) {
    int * input = parseArgsToIntArray(argc, argv);

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

    FreeLinkedList (input);
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
    int * input = parseArgsToIntArray(argc, argv);
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
    printIntArray(input, argc);
    fprintf(stdout, "nums2:\n");
    printIntArray(nums2, *nums2Size);
    putchar('\n');

    ret = intersect(input, argc, nums2, *nums2Size, retsz);

    fprintf(stdout, "return:\n");
    printIntArray(ret, *retsz);

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

    input = parseArgsToIntMatrix(argc - 2, argv + 2);

    if (!input)
        return -1;

    r = atoi(argv[0]);
    c = atoi(argv[1]);
    n = atoi(argv[2]);
    m = (argc - 3) / n;

    fprintf(stdout, "Input matrix:\n");
    printIntMatrix(input, m, n);

    reshaped = matrixReshape(input, m, &n, r, c, retr, retc);

    fprintf(stdout, "Reshaped:\n");
    printIntMatrix(reshaped, *retr, **retc);

    if (reshaped != input)
        freeIntMatrix (reshaped, *retr);
    if (*retc != &n)
        free (*retc);
    freeIntMatrix (input, m);
    return 0;
}

int lc977_SortSquare (int argc, char ** argv) {
    int * input;
    int * ret;
    int retsz;

    if (argc < 1)
        return -1;

    input = parseArgsToIntArray(argc, argv);
    ret = sortedSquares(input, argc, &retsz);

    printIntArray(ret, retsz);

    free(input);
    free(ret);
    return 0;
}

int lc1290_Bin2Int (int argc, char ** argv) {
    if (!argc)
        return -1;

    Node * head = NULL;

    while (*argv)
        head = AddValue(head, atoi(*argv++));

    return getDecimalValue(head);
}

int lc2087_RobotComingHome (int argc, char ** argv) {
    int start[2] = {1, 0};
    int home[2] = {2, 3};
    int rowCosts[3] = {5, 4, 3};
    int colCosts[4] = {8, 2, 6, 7};

    return minCost(start, 2, home, 2, rowCosts, 3, colCosts, 4);
}

int lc2078_maxDistance (int argc, char ** argv) {
    int * input = parseArgsToIntArray(argc, argv);
    int ret;

    ret = maxDistance(input, argc);
    free(input);

    return ret;
}

int lc2092_Secret (int argc, char ** argv) {
    int ** meetings = malloc(sizeof *meetings * 3);
    int retsz[1];
    int * ret;
    int expected[3] = {0, 1, 3};

    for (int i = 0; i < 3; i++)
        meetings[i] = malloc(sizeof **meetings * 3);
    meetings[0][0] = 3;
    meetings[0][1] = 1;
    meetings[0][2] = 3;
    meetings[1][0] = 1;
    meetings[1][1] = 2;
    meetings[1][2] = 2;
    meetings[2][0] = 0;
    meetings[2][1] = 3;
    meetings[2][2] = 3;

    ret = findAllPeople(4, meetings, 3, NULL, 3, retsz);

    fprintf(stdout, "Expected:\n");
    printIntArray(expected, 3);
    fprintf(stdout, "Got:\n");
    printIntArray(ret, *retsz);

    return 0;
}

int main (int argc, char **argv) {
    int ret;
    int num;

    if (argc < 2) {
        printf("usage: %s", usage_string);
        return 0;
    }

    num = atoi(argv[1]);

    if (num <= 0) {
        fprintf(stderr, "error: ID must be greater than 0.\n");
        return 1;
    }

    switch(num) {
        case 1:
            ret = lc001_TwoSums (argc - 2, argv + 2);
            break;
        case 2:
            ret = lc002_AddTwoNumbers (argc - 2, argv + 2);
            break;
        case 3:
            ret = lc003_LongestSubstring (argc - 2, argv + 2);
            break;
        case 5:
            ret = lc005_LongestPalindromicSubstring (argc - 2, argv + 2);
            break;
        case 9:
            ret = lc009_Palindrome (argc -2, argv + 2);
            break;
        case 13:
            ret = lc013_RomanToInteger (argc -2, argv + 2);
            break;
        case 14:
            ret = lc014_LongestCommonPrefix (argc -2, argv + 2);
            break;
        case 20:
            ret = lc020_ValidParentheses (argc -2, argv + 2);
            break;
        case 21:
            ret = lc021_Merge2LinkedLists (argc - 2, argv + 2);
            break;
        case 26:
            ret = lc026_RmDup (argc - 2, argv + 2);
            break;
        case 27:
            ret = lc027_RemoveElement (argc - 2, argv + 2);
            break;
        case 34:
            ret = lc034_FindPosOfElementsInSortedArray (argc - 2, argv + 2);
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
        case 98:
            ret = lc098_ValidBST (argc - 2, argv + 2);
            break;
        case 102:
            ret = lc102_BinTreeLevelTraversal (argc - 2, argv + 2);
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
        case 977:
            ret = lc977_SortSquare (argc - 2, argv + 2);
            break;
        case 1290:
            ret = lc1290_Bin2Int (argc - 2, argv + 2);
            break;
        case 2087:
            ret = lc2087_RobotComingHome (argc - 2, argv + 2);
            break;
        case 2078:
            ret = lc2078_maxDistance (argc - 2, argv + 2);
            break;
        case 2092:
            ret = lc2092_Secret (argc - 2, argv + 2);
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
