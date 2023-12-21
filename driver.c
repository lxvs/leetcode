#include <stdlib.h>
#include <string.h>
#include <lib/debug.h>
#include <lib/list.h>
#include <lib/bst.h>
#include <lib/array.h>
#include "driver.h"
#include "easy/001-two-sum.h"
#include "easy/009-palindrome-number.h"
#include "easy/013-roman-to-integer.h"
#include "easy/014-longest-common-prefix.h"
#include "easy/020-valid-parentheses.h"
#include "easy/021-merge-two-sorted-lists.h"
#include "easy/026-remove-duplicates-from-sorted-array.h"
#include "easy/027-remove-element.h"
#include "easy/028-find-the-index-of-the-first-occurrence-in-a-string.h"
#include "easy/035-search-insert-position.h"
#include "easy/058-length-of-last-word.h"
#include "easy/066-plus-one.h"
#include "easy/066-plus-one-enhanced.h"
#include "easy/067-add-binary.h"
#include "easy/069-sqrtx.h"
#include "easy/070-climbing-stairs.h"
#include "easy/083-remove-duplicates-from-sorted-list.h"
#include "easy/088-merge-sorted-array.h"
#include "easy/101-symmetric-tree.h"
#include "easy/104-maximum-depth-of-binary-tree.h"
#include "easy/118-pascals-triangle.h"
#include "easy/121-best-time-to-buy-and-sell-stock.h"
#include "easy/144-binary-tree-preorder-traversal.h"
#include "easy/145-binary-tree-postorder-traversal.h"
#include "easy/203-remove-linked-list-elements.h"
#include "easy/206-reverse-linked-list.h"
#include "easy/217-contains-duplicate.h"
#include "easy/226-invert-binary-tree.h"
#include "easy/232-implement-queue-using-stacks.h"
#include "easy/234-palindrome-linked-list.h"
#include "easy/242-valid-anagram.h"
#include "easy/350-intersection-of-two-arrays-ii.h"
#include "easy/383-ransom-note.h"
#include "easy/387-first-unique-character-in-a-string.h"
#include "easy/566-reshape-the-matrix.h"
#include "easy/700-search-in-a-binary-search-tree.h"
#include "easy/977-squares-of-a-sorted-array.h"
#include "easy/1290-convert-binary-number-in-a-linked-list-to-integer.h"
#include "easy/1913-maximum-product-difference-between-two-pairs.h"
#include "easy/2078-two-furthest-houses-with-different-colors.h"
#include "easy/2085-count-common-words-with-one-occurrence.h"
#include "easy/2089-find-target-indices-after-sorting-array.h"
#include "easy/2094-finding-3-digit-even-numbers.h"
#include "easy/2706-buy-two-chocolates.h"
#include "medium/002-add-two-numbers.h"
#include "medium/003-longest-substring-without-repeating-characters.h"
#include "medium/005-longest-palindromic-substring.h"
#include "medium/034-find-first-and-last-position-of-element-in-sorted-array.h"
#include "medium/036-valid-sudoku.h"
#include "medium/053-maximum-subarray.h"
#include "medium/074-search-a-2d-matrix.h"
#include "medium/098-validate-binary-search-tree.h"
#include "medium/102-binary-tree-level-order-traversal.h"
#include "medium/701-insert-into-a-binary-tree.h"
#include "medium/935-knight-dialer.h"
#include "medium/1637-widest-vertical-area-between-two-points-containing-no-points.h"
#include "medium/1743-restore-the-array-from-adjacent-pairs.h"
#include "medium/1759-count-number-of-homogenous-substrings.h"
#include "medium/1887-reduction-operations-to-make-the-array-elements-equal.h"
#include "medium/2086-minimum-number-of-food-buckets-to-feed-the-hamsters.h"
#include "medium/2087-minimum-cost-homecoming-of-a-robot-in-a-grid.h"
#include "medium/2090-k-radius-subarray-averages.h"
#include "medium/2091-removing-minimum-and-maximum-from-array.h"
#include "medium/2095-delete-the-middle-node-of-a-linked-list.h"
#include "hard/2092-find-all-people-with-secret.h"
#include "hard/2147-number-of-ways-to-divide-a-long-corridor.h"

const char * driver_usage =
    "leet-code driver " EXEC_VERSION "\n"
    USAGE_PREFIX "<id> [<argument> ...]\n";

int lc001_TwoSums (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1 <target> <integer> <integer> [<integer> ...]\n"
        "Return two different indices of the two integers such that they add up to target.\n";
    int inputArraySize = argc - 3;
    int * inputArray;
    int * returnArray;
    int returnSize = 0;
    int target;

    if (inputArraySize < 2) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    target = atoi (argv[2]);
    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);

#if DEBUG
    printf ("input array:\n");
    printIntegerArray (inputArray, inputArraySize);
#endif

    returnArray = twoSum (inputArray, inputArraySize, target, &returnSize);

    if (returnArray == NULL) {
        fprintf (stderr, "error: invalid input\n");
        free (inputArray);
        return -1;
    }

    printIntegerArray (returnArray, returnSize);

    free (inputArray);
    free (returnArray);

    return 0;
}

int lc002_AddTwoNumbers (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2 <augend> <addend>\n"
        "Print the sum of the 2 given numbers.\n";
    Node * augend = NULL;
    Node * addend = NULL;
    Node * sum = NULL;

    if (argc != 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    for (int i = 0, length = strlen (argv[2]); argv[2][i] != '\0'; i++) {
        augend = addListNode (augend, argv[2][length - i - 1] - '0');
    }

    for (int i = 0, length = strlen (argv[3]); argv[3][i] != '\0'; i++) {
        addend = addListNode (addend, argv[3][length - i - 1] - '0');
    }

#if DEBUG
    printf ("augend: ");
    printLinkedList (augend);
    printf ("addend: ");
    printLinkedList (addend);
#endif

    printLinkedList (sum = addTwoNumbers (augend, addend));

    freeLinkedList (augend);
    freeLinkedList (addend);
    freeLinkedList (sum);

    return 0;
}

int lc003_LongestSubstring (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "3 <string>\n"
        "Find the length of the longest substring without repeating characters.\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", lengthOfLongestSubstring (argv[2]));

    return 0;
}

int lc005_LongestPalindromicSubstring (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "5 <string>\n"
        "Get the longest palindromic substring.\n";
    char * input;
    char * returnString;

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = argv[2];
    returnString = longestPalindrome (input);

    printf ("%s\n", returnString);

    free (returnString);
    return 0;
}

int lc009_Palindrome (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "9 <integer> [<integer> ...]\n"
        "Check if a integer is palindromic.\n";

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    argv += 2;
    while (*argv != NULL) {
        int num = atoi (*argv++);
        printf ("%d: %s\n", num, isPalindrome (num) ? "true" : "false");
    }

    return 0;
}

int lc013_RomanToInteger (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "13 <roman-numeral> [<roman-numeral> ...]\n"
        "Convert a roman numeral to an integer.\n";

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    argv += 2;
    while (*argv != NULL) {
        printf ("%s: %d\n", *argv, romanToInt (*argv));
        argv++;
    }

    return 0;
}

int lc014_LongestCommonPrefix (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "14 <string> [<string> ...]\n"
        "Find the longest common prefix of the given strings.\n";
    int inputSize = argc - 2;
    char ** input;
    char * returnString;

    if (inputSize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToStringArray (argc, argv, argc - inputSize, inputSize);

    printf ("%s\n", returnString = longestCommonPrefix (input, inputSize));

    free (returnString);
    freeStringArray (input, inputSize);

    return 0;
}

int lc020_ValidParentheses (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "20 <parentheses> [<parentheses> ...]\n"
        "Check if parentheses are valid.\n";

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    argv += 2;

    while (*argv != NULL) {
        printf ("%s: %s\n", *argv, isValid (*argv) ? "true" : "false");
        argv++;
    }

    return 0;
}

int lc021_Merge2LinkedLists (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "21 <l1.len> <l2.len> [<l1.val> ...] [<l2.val> ...]\n"
        "Merge 2 non-decreasing linked lists into a sorted list.\n";
    Node * l1 = NULL;
    Node * l2 = NULL;
    Node * merged;
    int len1, len2;

    if (argc < 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    len1 = atoi (argv[2]);
    len2 = atoi (argv[3]);

    if (len1 + len2 != argc - 4) {
        errorInputSizeMismatch (len1, len2, argc - 4);
        return -1;
    }

    for (int i = 0; i < len1 + len2; i++) {
        if (i < len1) {
            l1 = addListNode (l1, atoi (argv[4 + i]));
        } else {
            l2 = addListNode (l2, atoi (argv[4 + i]));
        }
    }

#if DEBUG
    printf ("input 1: ");
    printLinkedList (l1);
    printf ("input 2: ");
    printLinkedList (l2);
#endif

    merged = mergeTwoLists (l1, l2);

    printLinkedList (merged);

    freeLinkedList (merged);
    return 0;
}

int lc026_RmDup (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "26 <integer> [<integer> ...]\n"
        "Remove duplicated items from a non-decreasing integer array.\n";
    int inputArraySize = argc - 2;
    int * inputArray;
    int newSize;

    if (inputArraySize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (inputArray, inputArraySize);
#endif

    newSize = removeDuplicates (inputArray, inputArraySize);
    printIntegerArray (inputArray, newSize);

    free (inputArray);
    return 0;
}

int lc027_RemoveElement (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "27 <value> [<integer> ...]\n"
        "Remove all occurrences of <value> in given integer array.\n";
    int inputArraySize = argc - 3;
    int * inputArray;
    int value;

    if (inputArraySize < 0) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    value = atoi (argv[2]);
    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (inputArray, inputArraySize);
#endif

    inputArraySize = removeElement (inputArray, inputArraySize, value);
    printIntegerArray (inputArray, inputArraySize);

    free (inputArray);
    return 0;
}

int lc028_FindNeedleInHaystack (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "28 <haystack> <needle>\n"
        "Print the index of the first occurrence of needle in haystack.\n";

    if (argc != 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", strStr (argv[2], argv[3]));

    return 0;
}

int lc034_FindPosOfElementsInSortedArray (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "34 <target> [<integer> ...]\n"
        "Find the starting and ending position of <target> in a non-decreasing integer array.\n";
    int target;
    int inputArraySize = argc - 3;
    int * inputArray;
    int * returnValues;
    int returnSize;

    if (inputArraySize < 0) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    target = atoi (argv[2]);
    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnValues = searchRange(inputArray, inputArraySize, target, &returnSize);

    printIntegerArray (returnValues, returnSize);

    free (returnValues);
    free (inputArray);

    return 0;
}

int lc035_SearchInsertPosition (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "35 <target> <integer> [<integer> ...]\n"
        "Print the index of target (or the expected index) in a ascending sorted array\n"
        "of distinct integers.\n";
    int target;
    int inputSize = argc - 3;
    int * input;

    if (argc < 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    target = atoi (argv[2]);
    input = parseArgsToIntegerArray (argc, argv, 3, inputSize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (input, inputSize);
#endif

    printf ("%d\n", searchInsert (input, inputSize, target));

    free (input);
    return 0;
}

int lc036_ValidSudoku (int argc, char ** argv) {
    char ** input = malloc (sizeof *input * 9);
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
        input[i] = malloc (sizeof **input * 9);
        for (int j = 0; j < 9; j++)
            input[i][j] = valid[i][j];
    }

    printf ("Expected: true. Got: %s\n", isValidSudoku (input, 9, NULL) ? "true" : "false");

    input[0][0] = '8';

    printf ("Expected: false. Got: %s\n", isValidSudoku (input, 9, NULL) ? "true" : "false");

    freeStringArray (input, 9);
    return 0;
}

int lc053_MaxSubArray (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "53 <integer> [<integer> ...]\n"
        "Find the sub-array with the largest sum, and print the sum.\n";
    int inputArraySize = argc - 2;
    int * inputArray;

    if (inputArraySize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);
    printf ("%d\n", maxSubArray (inputArray, inputArraySize));

    free (inputArray);
    return 0;
}

int lc058_LengthOfLastWord (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "58 <string>\n"
        "Get the length of last word in string, which contains only words and spaces.\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", lengthOfLastWord (argv[2]));

    return 0;
}

int lc066_PlusOne (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "66 <digit> [<digit> ...]\n"
        "Input a integer array, each element represents a digit of an integer, ordered\n"
        "from most significant to least significant, no leading zeros.  Print a array\n"
        "that represents the input integer plus one.\n";
    int inputSize = argc - 2;
    int * digits;
    int returnSize;

    if (inputSize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    digits = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (digits, inputSize);
#endif

    digits = (getenv("LCD_66_ENHANCED") != NULL) ?
        plusOneEnhanced (digits, inputSize, &returnSize) :
        plusOne (digits, inputSize, &returnSize);

    printIntegerArray (digits, returnSize);

    free (digits);
    return 0;
}

int lc067_AddBinary (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "67 <binary> <binary>\n"
        "Add two binary numbers, whose lengths are both in range [1, 10000]\n";
    char * augend;
    char * addend;
    char * sum;

    if (argc != 4) {
        fprintf (stderr, usage);
        return -1;
    }

    augend = argv[2];
    addend = argv[3];

    if ((sum = addBinary (augend, addend)) == NULL) {
        return 1;
    }

    printf ("%s\n", sum);
    free (sum);
    return 0;
}

int lc069_SquareRoot (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "69 <integer>\n"
        "Get square root of given integer, which is in range [0, 2^31 - 1].\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", mySqrt (atoi (argv[2])));

    return 0;
}

int lc070_ClimbingStairs (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "70 <n>\n"
        "You are climbing a staircase.  It takes n steps to reach the top.\n"
        "Each time you can either climb 1 or 2 steps.  In how many distinct ways can\n"
        "you climb to the top? (1 <= n <= 45)\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", climbStairs (atoi (argv[2])));

    return 0;
}

int lc074_Search2dMatrix (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "74 <target> <column> <integer> [<integer> ...]\n"
        "Search the given matrix of given column(s) for given target.\n";
    int inputElementCount = argc - 4;
    int ** input;
    int target;
    int column;
    int row;
    int * columnSize;

    if (inputElementCount < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    target = atoi (argv[2]);
    column = atoi (argv[3]);

    input = parseArgsToIntegerMatrix (argc, argv, argc - inputElementCount, inputElementCount, column);
    row = matrixGetRow (inputElementCount, column);

#if DEBUG
    printf ("input:\n");
    printIntegerMatrix (input, row, column);
#endif

    columnSize = malloc (sizeof *columnSize * row);
    for (int i = 0; i < row; i++) {
        columnSize[i] = column;
    }

    printf ("%s\n.", searchMatrix (input, row, columnSize, target) ? "true" : "false");

    free (columnSize);
    freeIntegerMatrix (input, row);
    return 0;
}

int lc083_RemoveDupFromSortedList (int argc, char ** argv) {
    Node * input;
    Node * afterDeletion;

    input = parseArgsToLinkedList (argv, 2);
    printLinkedList (afterDeletion = deleteDuplicates (input));

    freeLinkedList (afterDeletion);
    return 0;
}

int lc088_MergeNums (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "88 <nums1-size> <nums2-size> <integer> [<integer> ...]\n"
        "Merge 2 non-decreasing sorted array into a single non-decreasing sorted array.\n"
        "One of nums1-size and nums2-size can be 0, but not both.\n";
    int nums1Size, nums2Size;
    int * nums1;
    int * nums2;
    int * nums1Realloc;

    if (argc < 5) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    nums1Size = atoi (argv[2]);
    nums2Size = atoi (argv[3]);

    if (nums1Size + nums2Size != argc - 4) {
        errorInputSizeMismatch (nums1Size, nums2Size, argc - 4);
        return -1;
    }

    nums1 = parseArgsToIntegerArray (argc, argv, argc - nums1Size - nums2Size, nums1Size);
    nums2 = parseArgsToIntegerArray (argc, argv, argc - nums2Size, nums2Size);

    if ((nums1Realloc = realloc (nums1, sizeof *nums1 * (nums1Size + nums2Size))) != NULL) {
        nums1 = nums1Realloc;
    } else {
        fprintf (stderr, "error: memory reallocation failed\n");
        free (nums1);
        free (nums2);
        return 1;
    }

    for (int i = nums1Size; i < nums1Size + nums2Size; i++) {
        nums1[i] = 0;
    }

    merge (nums1, nums1Size + nums2Size, nums1Size, nums2, nums2Size, nums2Size);

    printIntegerArray (nums1, nums1Size + nums2Size);

    free (nums1);
    free (nums2);
    return 0;
}

int lc098_ValidBST (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc101_SymmetricTree (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc102_BinTreeLevelTraversal (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc104_MaxDepthOfBinaryTree (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc118_PascalsTriangle (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "118 <row>\n"
        "Generate a Pascal's triangle of given row(s).\n"
        "row range: [1, 20]\n";
    int row;
    int returnRow;
    int * returnColumns;
    int ** returnMatrix;

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    returnMatrix = generate (row = atoi (argv[2]), &returnRow, &returnColumns);

    printIntegerArrays (returnMatrix, returnRow, returnColumns);

    freeIntegerMatrix (returnMatrix, returnRow);
    free (returnColumns);
    return 0;
}

int lc121_MaxProfit (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "121 <integer> [<integer> ...]\n"
        "Given an array where the i-th element is the price of a stock on the i-th day.\n"
        "Print the maximum profit to buy and sell the stock.\n";
    int inputArraySize = argc - 2;
    int * inputArray;

    if (inputArraySize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);
    printf ("%d\n", maxProfit (inputArray, inputArraySize));

    free (inputArray);
    return 0;
}

int lc144_BinaryTreePreorderTraversal (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc145_BinaryTreePostorderTraversal (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc203_RemoveLinkedListElements (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "203 <value> [<integer> ...]\n"
        "Remove all occurrences of value for given linked list.\n";
    int value;
    Node * input;

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }
    value = atoi (argv[2]);
    input = parseArgsToLinkedList (argv, 3);

#if DEBUG
    printf ("input: ");
    printLinkedList (input);
#endif

    printLinkedList (input = removeElements (input, value));

    freeLinkedList (input);
    return 0;
}

int lc206_ReverseLinkedList (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "206 <integer> [<integer> ...]\n"
        "Reverse the given linked list.\n";
    Node * input = NULL;
    Node * reversed;

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToLinkedList (argv, 2);
    reversed = reverseList (input);
    printLinkedList (reversed);
    freeLinkedList (reversed);
    return 0;
}

int lc217_ContainsDup (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "217 <integer> [<integer> ...]\n"
        "Check if the given array contains any duplicate.\n";
    int inputArraySize = argc - 2;
    int * inputArray;

    if (inputArraySize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);
    printf ("%s\n", containsDuplicate (inputArray, inputArraySize) ? "true" : "false");

    free (inputArray);
    return 0;
}

int lc226_InvertBinaryTree (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc232_ImplementQueueUsingStacks (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc234_PalindromeLinkedList (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "234 <integer> [<integer> ...]\n"
        "Check if the given linked list is palindromic.\n";
    Node * input = NULL;

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    argv += 2;
    while (*argv) {
        input = addListNode (input, atoi (*argv++));
    }

#if DEBUG
    printf ("input: ");
    printLinkedList (input);
#endif

    printf ("%s\n", isPalindrome_ll (input) ? "true" : "false");

    freeLinkedList (input);
    return 0;
}

int lc242_ValidAnagram (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "242 <string> <string>\n"
        "Check if a string is an anagram of the other.\n"
        "An Anagram is a word or phrase formed by rearranging the letters of a different\n"
        "word or phrase, typically using all the original letters exactly once.\n";
    char * str1;
    char * str2;

    if (argc != 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    str1 = argv[2];
    str2 = argv[3];

    printf ("%s\n", isAnagram (str1, str2) ? "true" : "false");

    return 0;
}

int lc350_Intersection (int argc, char ** argv) {
    const char * usage =
        USAGE_PREFIX "350 <nums1-size> <nums2-size> <integer> [<integer> ...] <integer> [<integer> ...]\n"
        "Get the intersection of two given arrays.\n";
    int nums1Size, nums2Size;
    int * nums1;
    int * nums2;
    int * returnArray;
    int returnArraySize;

    if (argc < 6) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    nums1Size = atoi (argv[2]);
    nums2Size = atoi (argv[3]);

    if (nums1Size + nums2Size != argc - 4) {
        errorInputSizeMismatch (nums1Size, nums2Size, argc - 4);
        return -1;
    }

    nums1 = parseArgsToIntegerArray (argc, argv, argc - nums2Size - nums1Size, nums1Size);
    nums2 = parseArgsToIntegerArray (argc, argv, argc - nums2Size, nums2Size);

#if DEBUG
    printf ("nums1: ");
    printIntegerArray (nums1, nums1Size);
    printf ("nums2: ");
    printIntegerArray (nums2, nums2Size);
#endif

    returnArray = intersect (nums1, nums1Size, nums2, nums2Size, &returnArraySize);
    printIntegerArray (returnArray, returnArraySize);

    free (nums1);
    free (nums2);
    free (returnArray);

    return 0;
}

int lc383_RansomNote (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "383 <note> <magazine>\n"
        "Check if a complete ransom note can be made by characters in given magazine.\n";
    char * note;
    char * magazine;

    if (argc != 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    note = argv[2];
    magazine = argv[3];

    printf ("%s\n", canConstruct (note, magazine) ? "true" : "false");

    return 0;
}

int lc387_FirstUniqueChar (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "387 <string>\n"
        "Print the index of the first non-repeating character in given string.\n"
        "If it does not exist, print -1.\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", firstUniqChar (argv[2]));

    return 0;
}

int lc566_MatrixReshape (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "566 <new-row> <new-column> <column> <integer> [<integer> ...]\n"
        "Reshape the given matrix.\n";
    int elementCount = argc - 5;
    int ** inputMatrix;
    int newRow, newColumn, row, column;
    int ** reshaped;
    int returnRow;
    int * returnColumn;

    if (elementCount < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    newRow = atoi (argv[2]);
    newColumn = atoi (argv[3]);
    column = atoi (argv[4]);
    row = matrixGetRow (elementCount, column);

    inputMatrix = parseArgsToIntegerMatrix (argc, argv, argc - elementCount, elementCount, column);

#if DEBUG
    printf ("input:\n");
    printIntegerMatrix (inputMatrix, row, column);
    printf ("\n");
#endif

    reshaped = matrixReshape (inputMatrix, row, &column, newRow, newColumn, &returnRow, &returnColumn);
    printIntegerMatrix (reshaped, returnRow, *returnColumn);

    if (reshaped != inputMatrix) {
        freeIntegerMatrix (reshaped, returnRow);
    }
    if (returnColumn != &column) {
        free (returnColumn);
    }
    freeIntegerMatrix (inputMatrix, row);
    return 0;
}

int lc700_SearchBst (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc701_InsertIntoABinaryTree (int argc, char ** argv) {
    fprintf (stderr, "driver not ready\n");
    return -1;
}

int lc935_KnightDialer (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "935 <integer>\n"
        "The chess knight has a unique movement, it may move two squares vertically and\n"
        "one square horizontally, or two squares horizontally and one square vertically\n"
        "(with both forming the shape of an L).\n"
        "We have a chess knight and a phone pad as shown below, the knight can only\n"
        "stand on a numeric cell.\n"
        "Given an integer n, return how many distinct phone numbers of length n we can\n"
        "dial.\n"
        "You are allowed to place the knight on any numeric cell initially and then you\n"
        "should perform n - 1 jumps to dial a number of length n.  All jumps should be\n"
        "valid knight jumps.\n"
        "As the answer may be very large, return the answer modulo 109 + 7.\n"
        "Range of n: [1, 5000]\n";
    int input;

    if (argc != 3 || (input = atoi (argv[2])) == 0) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", knightDialer (input));
    return 0;
}

int lc977_SortSquare (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "977 <integer> [<integer> ...]\n"
        "Given an integer array nums sorted in non-decreasing order, print an array of\n"
        "the squares of each number sorted in non-decreasing order.\n";
    int inputArraySize = argc - 2;
    int * inputArray;
    int * returnArray;
    int returnArraySize;

    if (inputArraySize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    inputArray = parseArgsToIntegerArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnArray = sortedSquares (inputArray, inputArraySize, &returnArraySize);

    printIntegerArray (returnArray, returnArraySize);

    free (inputArray);
    free (returnArray);
    return 0;
}

int lc1290_Binary2Decimal (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1290 <binary>\n"
        "Convert binaries to decimals.\n";
    Node * inputList = NULL;

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    for (int i = 0; argv[2][i] != '\0'; i++) {
        inputList = addListNode (inputList, argv[2][i] - '0');
    }

#if DEBUG
    printf ("input: ");
    printLinkedList (inputList);
#endif

    printf ("%d\n", getDecimalValue (inputList));

    freeLinkedList (inputList);
    return 0;
}

int lc1637_WidestVerticalArea (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1637 <x1> <y1> <x2> <y2> [<x> <y> ...]]\n";
    int ** points;
    int * pointsColSize;
    int pointsSize = (argc - 2) / 2;

    if (pointsSize < 2 || pointsSize * 2 != argc - 2) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    pointsColSize = malloc (sizeof *pointsColSize * pointsSize);
    for (int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;
    }

    points = parseArgsToIntegerMatrix (argc, argv, argc - pointsSize * 2, pointsSize * 2, 2);

#if DEBUG
    printf ("input matrix:\n");
    printIntegerMatrix (points, pointsSize, 2);
#endif

    printf ("%d\n", maxWidthOfVerticalArea (points, pointsSize, pointsColSize));

    free (pointsColSize);
    freeIntegerMatrix (points, pointsSize);
    return 0;
}

int lc1743_RestoreTheArrayFromAdjacentPairs (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1743 <integer> <integer> [<integer> <integer> ...]\n"
        "There is an integer array `nums' that consists of n unique elements, but you\n"
        "have forgotten it.  However, you do remember every pair of adjacent elements in\n"
        "nums.\n"
        "You are given a 2D integer array adjacentPairs of size (n - 1) where each\n"
        "adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent\n"
        "in nums.\n"
        "It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1]\n"
        "will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1],\n"
        "nums[i]]. The pairs can appear in any order.\n"
        "Return the original array nums. If there are multiple solutions, return any of\n"
        "them.\n";
    int ** input;
    int inputColSize = 2;
    int inputSize = (argc - 2) / inputColSize;
    int * restored;
    int restoredSize = 0;

    if (inputSize < 1 || argc % 2 != 0) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToIntegerMatrix (argc, argv, argc - inputSize * inputColSize, inputSize * inputColSize, inputColSize);

#if DEBUG
    printf ("input matrix:\n");
    printIntegerMatrix (input, inputSize, inputColSize);
#endif

    restored = restoreArray (input, inputSize, &inputColSize, &restoredSize);
    printIntegerArray (restored, restoredSize);

    free (restored);
    freeIntegerMatrix (input, inputSize);
    return 0;
}

int lc1759_CountNumberOfHomogenousSubstrings (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1759 <string>\n"
        "Given a string s, return the number of homogenous substrings of s.  Since the\n"
        "answer may be too large, return it modulo (10^9 + 7).\n"
        "A string is homogenous if all the characters of the string are the same.\n"
        "A substring is a contiguous sequence of characters within a string.\n"
        "The given string contains only lowercase letters, length ranging in [1, 10^5].\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", countHomogenous (argv[2]));

    return 0;
}

int lc1887_ReductionOperationToMakeTheArrayElementsEqual (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1887 <integer> [<integer> ...]\n"
        "Given an integer array nums, your goal is to make all elements in nums equal.\n"
        "To complete one operation, follow these steps:\n"
        "Find the largest value in nums.  Let its index be i (0-indexed) and its value\n"
        "be largest.  If there are multiple elements with the largest value, pick the\n"
        "smallest i.  Find the next largest value in nums strictly smaller than largest.\n"
        "Let its value be nextLargest.  Reduce nums[i] to nextLargest.\n"
        "Return the number of operations to make all elements in nums equal.\n"
        "Ranges of input integer and input size are both [1, 50000]\n";
    int * input;
    int inputSize = argc - 2;
    int operations;

    if (inputSize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);
    operations = reductionOperations (input, inputSize);
    printf ("%d\n", operations);

    free (input);
    return 0;
}

int lc1913_MaxProductDifference (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "1913 <int> <int> <int> <int> [<int> ...]\n"
        "The product difference between two pairs (a, b) and (c, d) is defined as\n"
        "(a * b) - (c * d).  For example, the product difference between (5, 6) and\n"
        "(2, 7) is (5 * 6) - (2 * 7) = 16.  Given an integer array nums, choose four\n"
        "distinct indices w, x, y, and z such that the product difference between pairs\n"
        "(nums[w], nums[x]) and (nums[y], nums[z]) is maximized.  Return the maximum\n"
        "such product difference.\n"
        "\n"
        "The length of nums ranges in [4, 10^4]\n"
        "The elements of nums range in [1, 10^4]\n";
    int * input;
    int inputSize = argc - 2;

    if (inputSize < 4) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);
#if DEBUG
    printf ("input array: ");
    printIntegerArray (input, inputSize);
#endif

    printf ("%d\n", maxProductDifference (input, inputSize));
    free (input);
    return 0;
}

int lc2078_TwoFurthestHousesWithDifferentColors (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2078 <integer> <integer> [<integer> ...]\n"
        "Each different integer represents a different color.  Find the maximum\n"
        "distance of different colors.\n";
    int colorsSize = argc - 2;
    int * colors;

    if (colorsSize < 2) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    colors = parseArgsToIntegerArray (argc, argv, argc - colorsSize, colorsSize);

#if DEBUG
    printf ("colors: ");
    printIntegerArray (colors, colorsSize);
#endif

    printf ("%d\n", maxDistance (colors, colorsSize));

    free (colors);
    return 0;
}

int lc2085_CountCommonWordsWithOneOccurrence (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2085 <words1size> <words2size> <string> [<string> ...] <string> [<string> ...]\n"
        "Count strings that appear exactly once in both string arrays.\n";
    int words1Size;
    int words2Size;
    char ** words1;
    char ** words2;

    if (argc < 6) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    words1Size = atoi (argv[2]);
    words2Size = atoi (argv[3]);

    if (words1Size + words2Size != argc - 4) {
        errorInputSizeMismatch (words1Size, words2Size, argc - 4);
        return -1;
    }

    words1 = parseArgsToStringArray (argc, argv, 4, words1Size);
    words2 = parseArgsToStringArray (argc, argv, 4 + words1Size, words2Size);

#if DEBUG
    printf ("words1: ");
    printStringArray (words1, words1Size);
    printf ("words2: ");
    printStringArray (words2, words2Size);
#endif

    printf ("%d\n", countWords (words1, words1Size, words2, words2Size));

    freeStringArray (words1, words1Size);
    freeStringArray (words2, words2Size);
    return 0;
}

int lc2086_FeedTheHamsters (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2086 <string>\n"
        "Print the minimum number of food buckets to feed the hamsters.\n"
        "String can only contain `H', representing a hamster, or `.', representing a place to put a bucket.\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", minimumBuckets (argv[2]));

    return 0;
}

int lc2087_RobotComingHome (int argc, char ** argv) {
    const char * usage =
        USAGE_PREFIX "2087 <start.x> <start.y> <home.x> <home.y> <row> <column> <rowCost> [<rowCost> ...] <colCost> [<colCost> ...]\n"
        "Get the minimum total cost to travel from start position to home.\n";
    int start[2], home[2];
    int row;
    int column;
    int * rowCosts;
    int * colCosts;

    if (argc < 10) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    start[0] = atoi (argv[2]);
    start[1] = atoi (argv[3]);
    home[0] = atoi (argv[4]);
    home[1] = atoi (argv[5]);
    row = atoi (argv[6]);
    column = atoi (argv[7]);

    if (row + column != argc - 8) {
        errorInputSizeMismatch (row, column, argc - 8);
        return -1;
    }

    rowCosts = parseArgsToIntegerArray (argc, argv, argc - column - row, row);
    colCosts = parseArgsToIntegerArray (argc, argv, argc - column, column);

    printf ("%d\n", minCost (start, 2, home, 2, rowCosts, row, colCosts, column));

    free (rowCosts);
    free (colCosts);
    return 0;
}

int lc2089_FindTargetIndicesAfterSortingArray (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2089 <target> <integer> [<integer> ...]\n"
        "Get the indices of all occurrences of target integer after sorting the given\n"
        "array in non-decreasing order.  The returned array must be sorted in increasing\n"
        "order.\n";
    int target;
    int inputSize = argc - 3;
    int * input;
    int * returnValues;
    int returnSize;

    if (inputSize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    target = atoi (argv[2]);
    input = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (input, inputSize);
#endif

    returnValues = targetIndices (input, inputSize, target, &returnSize);
    printIntegerArray (returnValues, returnSize);

    free (input);
    free (returnValues);
    return 0;
}

int lc2090_KRadiusSubArrayAverages (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2090 <k> <integer> [<integer> ...]\n"
        "Print a integer array containing the average values of range [i - k, i + k] of\n"
        "the given array.  If i - k < 0 or i + k > array size, the average is -1.\n";
    int k;
    int inputSize = argc - 3;
    int * input;
    int * returnArray;
    int returnSize;

    if (inputSize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    k = atoi (argv[2]);
    input = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (input, inputSize);
#endif

    returnArray = getAverages (input, inputSize, k, &returnSize);
    printIntegerArray (returnArray, returnSize);

    free (input);
    free (returnArray);
    return 0;
}

int lc2091_RemovingMinumumAndMaximumFromArray (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2091 <integer> [<integer> ...]\n"
        "Print the minimum number of deletions it would take to remove the both the\n"
        "minimum and maximum element from the given array of *distinct* integers.\n"
        "A deletion is removing an element from either the front or the back of the\n"
        "array.\n";
    int inputSize = argc - 2;
    int * input;

    if (inputSize < 1) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);

#if DEBUG
    printf ("input: ");
    printIntegerArray (input, inputSize);
#endif

    printf ("%d\n", minimumDeletions (input, inputSize));

    free (input);
    return 0;
}

int lc2092_Secret (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2092 <n> <firstPerson> <meetingCount> <x> <y> <time> [<x> <y> <time> ...]\n"
        "You are given an integer `n' indicating there are n people numbered from `0' to\n"
        "`n - 1'.  You are also given a 0-indexed 2D integer array `meetings' where\n"
        "meetings[i] = [x_i, y_i, time_i] indicates that person x_i and person y_i have\n"
        "a meeting at time_i.  A person may attend multiple meetings at the same time.\n"
        "Finally, you are given an integer `firstPerson'.\n"
        "\n"
        "Person 0 has a secret and initially shares the secret with a person firstPerson\n"
        "at time 0.  This secret is then shared every time a meeting takes place with a\n"
        "person that has the secret.  More formally, for every meeting, if a person x_i\n"
        "has the secret at time_i, then they will share the secret with person y_i, and\n"
        "vice versa.\n"
        "\n"
        "The secrets are shared instantaneously.  That is, a person may receive the\n"
        "secret and share it with people in other meetings within the same time frame.\n"
        "\n"
        "Return a list of all the people that have the secret after all the meetings have\n"
        "taken place.  You may return the answer in any order.\n";
    int n, firstPerson, meetingCount;
    int ** meetings;
    int * returnArray;
    int returnSize;

    if (argc < 8) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    n = atoi (argv[2]);
    firstPerson = atoi (argv[3]);
    meetingCount = atoi (argv[4]);

    if ((argc - 5) % 3 != 0 || (argc - 5) / 3 != meetingCount) {
        fprintf (stderr, "error: meeting count and meeting elements mismatch\n");
        return -1;
    }

    meetings = malloc (sizeof *meetings * meetingCount);
    for (int i = 0; i < meetingCount; i++) {
        meetings[i] = malloc (sizeof *meetings[i] * 3);
    }
    for (int j = 0; j < argc - 5; j++) {
        meetings[j / 3][j % 3] = atoi (argv[5 + j]);
    }

#if DEBUG
    printf ("meetings:\n");
    printIntegerMatrix (meetings, meetingCount, 3);
    printf ("\n");
#endif

    returnArray = findAllPeople (n, meetings, meetingCount, NULL, firstPerson, &returnSize);
    printIntegerArray (returnArray, returnSize);

    free (returnArray);
    freeIntegerMatrix (meetings, meetingCount);
    return 0;
}

int lc2094_Finding3DigitEvenNumbers (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2094 <digit> <digit> <digit> [<digit> ...]\n"
        "Find all 3-digit even numbers that consist of 3 elements from given array.\n";
    int inputSize = argc - 2;
    int * input;
    int * returnValues;
    int returnSize;

    if (inputSize < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToIntegerArray (argc, argv, argc - inputSize, inputSize);
    returnValues = findEvenNumbers (input, inputSize, &returnSize);
    printIntegerArray (returnValues, returnSize);

    free (input);
    free (returnValues);
    return 0;
}

int lc2095_DeleteTheMiddleNodeOfALinkedList (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2095 <integer> [<integer> ...]\n"
        "Delete the middle node of given linked list.\n"
        "The middle node of linked list of size N is the N/2-th (0-based) node.\n";
    Node * input;

    if (argc < 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    input = parseArgsToLinkedList (argv, 2);
    printLinkedList (input = deleteMiddle (input));
    freeLinkedList (input);
    return 0;
}

int lc2147_DivideALongCorridor (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2147 <corridor>\n"
        "Along a long library corridor, there is a line of seats and decorative plants.\n"
        "You are given a 0-indexed string corridor of length n consisting of letters 'S'\n"
        "and 'P' where each 'S' represents a seat and each 'P' represents a plant.\n"
        "\n"
        "One room divider has already been installed to the left of index 0, and another\n"
        "to the right of index n - 1. Additional room dividers can be installed. For\n"
        "each position between indices i - 1 and i (1 <= i <= n - 1), at most one\n"
        "divider can be installed.\n"
        "\n"
        "Divide the corridor into non-overlapping sections, where each section has\n"
        "exactly two seats with any number of plants.  There may be multiple ways to\n"
        "perform the division.  Two ways are different if there is a position with a\n"
        "room divider installed in the first way but not in the second way.\n"
        "\n"
        "Return the number of ways to divide the corridor.  Since the answer may be\n"
        "very large, return it modulo 109 + 7.  If there is no way, return 0.\n"
        "\n"
        "<corridor> contains only 'S' or 'P', and its length ranges in [1, 10^5].\n";

    if (argc != 3) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    printf ("%d\n", numberOfWays (argv[2]));

    return 0;
}

int lc2706_BuyTwoChocolates (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2706 <money> <price> <price> [<price> ...]\n"
        "You are given an integer array prices representing the prices of various\n"
        "chocolates in a store.  You are also given a single integer money, which\n"
        "represents your initial amount of money.\n"
        "\n"
        "You must buy exactly two chocolates in such a way that you still have some\n"
        "non-negative leftover money. You would like to minimize the sum of the prices\n"
        "of the two chocolates you buy.\n"
        "\n"
        "Return the amount of money you will have leftover after buying the two\n"
        "chocolates.  If there is no way for you to buy two chocolates without ending up\n"
        "in debt, return money.  Note that the leftover must be non-negative.\n"
        "\n"
        "The number of prices ranges in [2, 50].\n"
        "The price and money range in [1, 100].\n";
    int money;
    int * prices;
    int pricesSize = argc - 3;

    if (pricesSize < 2) {
        fprintf (stderr, "%s", usage);
        return -1;
    }

    money = atoi (argv[2]);
    prices = parseArgsToIntegerArray (argc, argv, argc - pricesSize, pricesSize);
    printf ("%d\n", buyChoco (prices, pricesSize, money));

    free (prices);
    return 0;
}

int main (int argc, char **argv) {
    int returnedValue;
    int problemNumber;

    if (argc < 2) {
        fprintf (stderr, "%s", driver_usage);
        return -1;
    }

    problemNumber = atoi (argv[1]);

    if (problemNumber <= 0) {
        fprintf (stderr, "%s", driver_usage);
        return -1;
    }

    switch (problemNumber) {
        case 1:
            returnedValue = lc001_TwoSums (argc, argv);
            break;
        case 2:
            returnedValue = lc002_AddTwoNumbers (argc, argv);
            break;
        case 3:
            returnedValue = lc003_LongestSubstring (argc, argv);
            break;
        case 5:
            returnedValue = lc005_LongestPalindromicSubstring (argc, argv);
            break;
        case 9:
            returnedValue = lc009_Palindrome (argc, argv);
            break;
        case 13:
            returnedValue = lc013_RomanToInteger (argc, argv);
            break;
        case 14:
            returnedValue = lc014_LongestCommonPrefix (argc, argv);
            break;
        case 20:
            returnedValue = lc020_ValidParentheses (argc, argv);
            break;
        case 21:
            returnedValue = lc021_Merge2LinkedLists (argc, argv);
            break;
        case 26:
            returnedValue = lc026_RmDup (argc, argv);
            break;
        case 27:
            returnedValue = lc027_RemoveElement (argc, argv);
            break;
        case 28:
            returnedValue = lc028_FindNeedleInHaystack (argc, argv);
            break;
        case 34:
            returnedValue = lc034_FindPosOfElementsInSortedArray (argc, argv);
            break;
        case 35:
            returnedValue = lc035_SearchInsertPosition (argc, argv);
            break;
        case 36:
            returnedValue = lc036_ValidSudoku (argc, argv);
            break;
        case 53:
            returnedValue = lc053_MaxSubArray (argc, argv);
            break;
        case 58:
            returnedValue = lc058_LengthOfLastWord (argc, argv);
            break;
        case 66:
            returnedValue = lc066_PlusOne (argc, argv);
            break;
        case 67:
            returnedValue = lc067_AddBinary (argc, argv);
            break;
        case 69:
            returnedValue = lc069_SquareRoot (argc, argv);
            break;
        case 70:
            returnedValue = lc070_ClimbingStairs (argc, argv);
            break;
        case 74:
            returnedValue = lc074_Search2dMatrix (argc, argv);
            break;
        case 83:
            returnedValue = lc083_RemoveDupFromSortedList (argc, argv);
            break;
        case 88:
            returnedValue = lc088_MergeNums (argc, argv);
            break;
        case 98:
            returnedValue = lc098_ValidBST (argc, argv);
            break;
        case 101:
            returnedValue = lc101_SymmetricTree (argc, argv);
            break;
        case 102:
            returnedValue = lc102_BinTreeLevelTraversal (argc, argv);
            break;
        case 104:
            returnedValue = lc104_MaxDepthOfBinaryTree (argc, argv);
            break;
        case 118:
            returnedValue = lc118_PascalsTriangle (argc, argv);
            break;
        case 121:
            returnedValue = lc121_MaxProfit (argc, argv);
            break;
        case 144:
            returnedValue = lc144_BinaryTreePreorderTraversal (argc, argv);
            break;
        case 145:
            returnedValue = lc145_BinaryTreePostorderTraversal (argc, argv);
            break;
        case 203:
            returnedValue = lc203_RemoveLinkedListElements (argc, argv);
            break;
        case 206:
            returnedValue = lc206_ReverseLinkedList (argc, argv);
            break;
        case 217:
            returnedValue = lc217_ContainsDup (argc, argv);
            break;
        case 226:
            returnedValue = lc226_InvertBinaryTree (argc, argv);
            break;
        case 232:
            returnedValue = lc232_ImplementQueueUsingStacks (argc, argv);
            break;
        case 234:
            returnedValue = lc234_PalindromeLinkedList (argc, argv);
            break;
        case 242:
            returnedValue = lc242_ValidAnagram (argc, argv);
            break;
        case 350:
            returnedValue = lc350_Intersection (argc, argv);
            break;
        case 383:
            returnedValue = lc383_RansomNote (argc, argv);
            break;
        case 387:
            returnedValue = lc387_FirstUniqueChar (argc, argv);
            break;
        case 566:
            returnedValue = lc566_MatrixReshape (argc, argv);
            break;
        case 700:
            returnedValue = lc700_SearchBst (argc, argv);
            break;
        case 701:
            returnedValue = lc701_InsertIntoABinaryTree (argc, argv);
            break;
        case 935:
            returnedValue = lc935_KnightDialer (argc, argv);
            break;
        case 977:
            returnedValue = lc977_SortSquare (argc, argv);
            break;
        case 1290:
            returnedValue = lc1290_Binary2Decimal (argc, argv);
            break;
        case 1637:
            returnedValue = lc1637_WidestVerticalArea (argc, argv);
            break;
        case 1743:
            returnedValue = lc1743_RestoreTheArrayFromAdjacentPairs (argc, argv);
            break;
        case 1759:
            returnedValue = lc1759_CountNumberOfHomogenousSubstrings (argc, argv);
            break;
        case 1887:
            returnedValue = lc1887_ReductionOperationToMakeTheArrayElementsEqual (argc, argv);
            break;
        case 1913:
            returnedValue = lc1913_MaxProductDifference (argc, argv);
            break;
        case 2078:
            returnedValue = lc2078_TwoFurthestHousesWithDifferentColors (argc, argv);
            break;
        case 2085:
            returnedValue = lc2085_CountCommonWordsWithOneOccurrence (argc, argv);
            break;
        case 2086:
            returnedValue = lc2086_FeedTheHamsters (argc, argv);
            break;
        case 2087:
            returnedValue = lc2087_RobotComingHome (argc, argv);
            break;
        case 2089:
            returnedValue = lc2089_FindTargetIndicesAfterSortingArray (argc, argv);
            break;
        case 2090:
            returnedValue = lc2090_KRadiusSubArrayAverages (argc, argv);
            break;
        case 2091:
            returnedValue = lc2091_RemovingMinumumAndMaximumFromArray (argc, argv);
            break;
        case 2092:
            returnedValue = lc2092_Secret (argc, argv);
            break;
        case 2094:
            returnedValue = lc2094_Finding3DigitEvenNumbers (argc, argv);
            break;
        case 2095:
            returnedValue = lc2095_DeleteTheMiddleNodeOfALinkedList (argc, argv);
            break;
        case 2147:
            returnedValue = lc2147_DivideALongCorridor (argc, argv);
            break;
        case 2706:
            returnedValue = lc2706_BuyTwoChocolates (argc, argv);
            break;
        default:
            fprintf (stderr, "no driver for %d\n", problemNumber);
            returnedValue = -1;
            break;
    }

    return returnedValue;
}
