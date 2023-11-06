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
#include "easy/2078-two-furthest-houses-with-different-colors.h"
#include "easy/2085-count-common-words-with-one-occurrence.h"
#include "easy/2089-find-target-indices-after-sorting-array.h"
#include "easy/2094-finding-3-digit-even-numbers.h"
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
#include "medium/2086-minimum-number-of-food-buckets-to-feed-the-hamsters.h"
#include "medium/2087-minimum-cost-homecoming-of-a-robot-in-a-grid.h"
#include "medium/2090-k-radius-subarray-averages.h"
#include "medium/2091-removing-minimum-and-maximum-from-array.h"
#include "medium/2095-delete-the-middle-node-of-a-linked-list.h"
#include "hard/2092-find-all-people-with-secret.h"

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
        case 977:
            returnedValue = lc977_SortSquare (argc, argv);
            break;
        case 1290:
            returnedValue = lc1290_Binary2Decimal (argc, argv);
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
        default:
            fprintf (stderr, "no driver for %d\n", problemNumber);
            returnedValue = -1;
            break;
    }

    return returnedValue;
}
