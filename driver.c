#include <stdio.h>
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
    int * returnedArray;
    int returnedArraySize[1] = {0};
    int target;

    if (inputArraySize < 2) {
        printf ("%s", usage);
        return 0;
    }

    target = atoi (argv[2]);
    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    printf ("input array:\n");
    printIntArray (inputArray, inputArraySize);
    returnedArray = twoSum (inputArray, inputArraySize, target, returnedArraySize);

    if (returnedArray == NULL) {
        printf ("invalid input for this problem\n");
        free (inputArray);
        return 0;
    }

    printf ("returned 2 indices:\n");
    printIntArray (returnedArray, *returnedArraySize);

    free (inputArray);
    free (returnedArray);

    return 0;
}

int lc002_AddTwoNumbers (int argc, char ** argv) {
    const char * usage = \
        USAGE_PREFIX "2 <augend> <addend>\n" \
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
    argv += 2;

    while (*argv != NULL) {
        num = atoi (*argv++);
        printf ("%d %s a palindrome number.\n", num, isPalindrome (num) ? "is" : "isn't");
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
    const char * usage = USAGE_PREFIX "14 <string> [<string> ...]\n"
        "Find the longest common prefix of the given strings.\n";
    int inputSize = argc - 2;
    char ** input;
    char * returnedString;

    if (inputSize < 1) {
        printf ("%s", usage);
        return 0;
    }

    input = parseArgsToStringArray (argc, argv, argc - inputSize, inputSize);

    returnedString = longestCommonPrefix (input, inputSize);
    printf ("Longest common prefix is `%s'\n", returnedString);

    free (returnedString);
    freeStringArray (input, inputSize);

    return 0;
}

int lc020_ValidParentheses (int argc, char ** argv) {
    if (argc != 1)
        return -1;

    fprintf(stdout, "%s\n", isValid(*argv) ? "Valid" : "Invalid");

    return 0;
}

int lc021_Merge2LinkedLists (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "21 <l1.len> <l2.len> [<l1.val> ...] [<l2.val> ...]\n"
        "Merge 2 non-decreasing linked lists.\n";
    Node * l1 = NULL;
    Node * l2 = NULL;
    Node * ret;
    int len1, len2;

    if (argc < 2) {
        printf ("%s", usage);
        return 0;
    }

    len1 = atoi (argv[2]);
    len2 = atoi (argv[3]);

    if (len1 + len2 != argc - 2)
        return -1;

    for (int i = 0; i < len1 + len2; i++) {
        if (i < len1)
            l1 = AddValue (l1, atoi (argv[4 + i]));
        else
            l2 = AddValue (l2, atoi (argv[4 + i]));
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

int lc026_RmDup (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "26 <integer> [<integer> ...]\n"
        "Remove duplicated items from a non-decreasing integer array.\n";
    int inputArraySize = argc - 2;
    int * inputArray;
    int newSize;

    if (inputArraySize < 1) {
        printf ("%s", usage);
        return 0;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);

    printf ("input array:\n");
    printIntArray (inputArray, inputArraySize);

    newSize = removeDuplicates (inputArray, inputArraySize);

    printf ("after removal of duplicated items:\n");
    printIntArray (inputArray, newSize);

    free (inputArray);
    return 0;
}

int lc027_RemoveElement (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "27 <value> [<integer> ...]\n"
        "Remove all occurrences of <value> in given integer array.\n"
        "array size: [0, 100]\n"
        "array element range: [0, 50]\n"
        "value range: [0, 100]\n";
    int inputArraySize = argc - 3;
    int * inputArray;
    int value;

    if (inputArraySize < 0) {
        printf ("%s", usage);
        return 0;
    }

    value = atoi (argv[2]);
    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);

    printf ("input array:\n");
    printIntArray (inputArray, inputArraySize);

    inputArraySize = removeElement (inputArray, inputArraySize, value);
    printf ("after removal:\n");
    printIntArray (inputArray, inputArraySize);

    free (inputArray);
    return 0;
}

int lc028_FindNeedleInHaystack (int argc, char ** argv) {
    const char * usage =
        USAGE_PREFIX "28 <haystack> <needle>\n"
        "Return the index of the first occurrence of needle in haystack.\n";

    if (argc != 2) {
        printf ("%s", usage);
        return 0;
    }

    return strStr (argv[0], argv[1]);
}

int lc034_FindPosOfElementsInSortedArray (int argc, char ** argv) {
    int target;
    int inputArraySize = argc - 3;
    int * inputArray;
    int * returnedArray;
    int returnedArraySize;
    const char * usage = USAGE_PREFIX "34 <target> [<integer> ...]\n"
        "Find the starting and ending position of <target> in a non-decreasing integer array.\n";

    if (inputArraySize < 0) {
        printf ("%s", usage);
        return 0;
    }

    target = atoi (argv[2]);
    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnedArray = searchRange(inputArray, inputArraySize, target, &returnedArraySize);

    printIntArray (returnedArray, returnedArraySize);

    free (returnedArray);
    free (inputArray);

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
    const char * usage = USAGE_PREFIX "53 <integer> [<integer> ...]\n"
        "Find the sub-array with the largest sum, and return the sum.\n";
    int inputArraySize = argc - 2;
    int * inputArray;
    int returnedSum;

    if (inputArraySize < 1) {
        printf ("%s", usage);
        return 0;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnedSum = maxSubArray (inputArray, inputArraySize);
    free (inputArray);
    return returnedSum;
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
        printf ("%s", usage);
        return 0;
    }

    target = atoi (argv[2]);
    column = atoi (argv[3]);

    input = parseArgsToIntMatrix (argc, argv, argc - inputElementCount, inputElementCount, column);

    row = matrixGetRow (inputElementCount, column);
    printf ("input matrix:\n");
    printIntMatrix (input, row, column);
    printf ("\n");

    columnSize = malloc (sizeof *columnSize * row);
    for (int i = 0; i < row; i++)
        columnSize[i] = column;

    printf ("%s target %d\n.", searchMatrix (input, row, columnSize, target) ? "Found" : "Couldn't find", target);

    free (columnSize);
    freeIntMatrix (input, row);
    return 0;
}

int lc083_RemoveDupFromSortedList (int argc, char ** argv) {
    Node * input;
    Node * afterDeletion;

    input = parseArgsToLinkedList (argv + 2);
    afterDeletion = deleteDuplicates (input);
    PrintList (afterDeletion);
    FreeLinkedList (afterDeletion);
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
    tree_t * tree = NewTreeNode(5);
    tree->left = NewTreeNode(4);
    tree->right = NewTreeNode(6);
    tree->right->left = NewTreeNode(3);
    tree->right->right = NewTreeNode(7);

    fprintf(stdout, "%s BST\n", isValidBST(tree) ? "Valid" : "Invalid");

    free(tree->right->right);
    free(tree->right->left);
    free(tree->right);
    free(tree->left);
    free(tree);
    return 0;
}

int lc101_SymmetricTree (int argc, char ** argv) {
    const char * usage = \
        USAGE_PREFIX "101\n" \
        "Check if given tree is symmetric.\n" \
        "Currently there is only fixed test cases.\n";
    tree_t * testCasePass;
    tree_t * testCaseFail;

    if (argc != 0) {
        printf ("%s", usage);
        return 0;
    }

    testCasePass = NewTreeNode (1);
    testCasePass->left = NewTreeNode (5);
    testCasePass->left->left = NewTreeNode (3);
    testCasePass->left->right = NewTreeNode (4);
    testCasePass->right = NewTreeNode (5);
    testCasePass->right->left = NewTreeNode (4);
    testCasePass->right->right = NewTreeNode (3);
    printf ("input tree:\n");
    printTree (testCasePass, 0);
    printf ("This tree is %s\n", isSymmetric (testCasePass) ? "symmetric" : "asymmetric");

    testCaseFail = NewTreeNode (1);
    testCaseFail->left = NewTreeNode (5);
    testCaseFail->left->left = NewTreeNode (3);
    testCaseFail->left->right = NewTreeNode (8);
    testCaseFail->right = NewTreeNode (5);
    testCaseFail->right->left = NewTreeNode (4);
    testCaseFail->right->right = NewTreeNode (3);
    printf ("input tree:\n");
    printTree (testCaseFail, 0);
    printf ("This tree is %s\n", isSymmetric (testCaseFail) ? "symmetric" : "asymmetric");

    freeTree (testCasePass);
    freeTree (testCaseFail);
    return 0;
}

int lc102_BinTreeLevelTraversal (int argc, char ** argv) {
    tree_t * tree = NewTreeNode(3);
    tree->left = NewTreeNode(9);
    tree->right = NewTreeNode(20);
    tree->right->left = NewTreeNode(15);
    tree->right->right = NewTreeNode(7);
    int retSize[1];
    int * retColumnSize[1];
    int ** ret = levelOrder(tree, retSize, retColumnSize);
    for (int i = 0; i < *retSize; i++) {
        for (int j = 0; j < retColumnSize[0][i]; j++)
            printf("%2d ", ret[i][j]);
        putchar('\n');
    }
    freeTree (tree);
    free(retColumnSize[0]);
    freeIntMatrix (ret, *retSize);
    return 0;
}

int lc104_MaxDepthOfBinaryTree (int argc, char ** argv) {
    const char * usage = \
        USAGE_PREFIX "104\n" \
        "Get maximum depth of a binary tree.\n" \
        "Currently there is only fixed test cases.\n";
    tree_t * testCaseOne;
    tree_t * testCaseTwo;

    if (argc != 0) {
        printf ("%s", usage);
        return 0;
    }

    testCaseOne = NewTreeNode (1);
    testCaseOne->left = NewTreeNode (1);
    testCaseOne->left->left = NewTreeNode (1);
    printf ("test case 1:\n");
    printTree (testCaseOne, 0);
    printf ("The maximum depth of this tree is %d\n", maxDepth (testCaseOne));

    testCaseTwo = NewTreeNode (2);
    testCaseTwo->left = NewTreeNode (2);
    testCaseTwo->left->left = NewTreeNode (2);
    testCaseTwo->left->right = NewTreeNode (2);
    testCaseTwo->left->left->left = NewTreeNode (2);
    testCaseTwo->right = NewTreeNode (2);
    testCaseTwo->right->left = NewTreeNode (2);
    testCaseTwo->right->right = NewTreeNode (2);
    testCaseTwo->right->right->right = NewTreeNode (2);
    printf ("test case 2:\n");
    printTree (testCaseTwo, 0);
    printf ("The maximum depth of this tree is %d\n", maxDepth (testCaseTwo));

    freeTree (testCaseOne);
    freeTree (testCaseTwo);
    return 0;
}

int lc118_PascalsTriangle (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "118 <row>\n"
        "Generate a Pascal's triangle of given row(s).\n"
        "row range: [1, 20]\n";
    int row;
    int retRow[1];
    int * retCols[1];
    int ** ret;

    if (argc != 3) {
        printf ("%s", usage);
        return 0;
    }

    ret = generate (row = atoi (argv[2]), retRow, retCols);

    for (int i = 0; i < *retRow; i++) {
        for (int j = *retRow - (i + 1); j > 0; j--) {
            printf ("%3s", "");
        }
        for (int j = 0; j < (*retCols)[i]; j++) {
            printf ("%5d ", ret[i][j]);
        }
        printf ("\n");
    }

    freeIntMatrix (ret, *retRow);
    free (*retCols);
    return 0;
}

int lc121_MaxProfit (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "121 <integer> [<integer> ...]\n"
        "Given an array where the i-th element is the price of a stock on the i-th day.\n"
        "Return the maximum profit to buy and sell the stock.\n";
    int inputArraySize = argc - 2;
    int * inputArray;
    int returnedProfit;

    if (inputArraySize < 1) {
        printf ("%s", usage);
        return 0;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnedProfit = maxProfit (inputArray, inputArraySize);
    free (inputArray);
    return returnedProfit;
}

int lc144_BinaryTreePreorderTraversal (int argc, char ** argv) {
    printf ("driver not ready\n");
    return 0;
}

int lc145_BinaryTreePostorderTraversal (int argc, char ** argv) {
    printf ("driver not ready\n");
    return 0;
}

int lc203_RemoveLinkedListElements (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "203 <value> [<integer> ...]\n"
        "Remove all occurrences of value for given linked list.\n";
    int value;
    Node * input;

    if (argc < 3) {
        printf ("%s", usage);
        return 0;
    }
    value = atoi (argv[2]);
    input = parseArgsToLinkedList (argv + 3);
    printf ("input list:\n");
    PrintList (input);
    input = removeElements (input, value);
    printf ("after removal of all %d:\n", value);
    PrintList (input);

    FreeLinkedList (input);
    return 0;
}

int lc206_ReverseLinkedList (int argc, char ** argv) {
    Node * input = NULL;
    Node * reversed;

    input = parseArgsToLinkedList (argv + 2);
    reversed = reverseList (input);
    PrintList (reversed);
    FreeLinkedList (reversed);
    return 0;
}

int lc217_ContainsDup (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "217 <integer> [<integer> ...]\n"
        "Check if the given array contains any duplicate.\n";
    int inputArraySize = argc - 2;
    int * inputArray;
    int returnedValue;

    if (inputArraySize < 1) {
        printf ("%s", usage);
        return 0;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnedValue = containsDuplicate (inputArray, inputArraySize) ? 0 : 1;

    free(inputArray);
    return returnedValue;
}

int lc226_InvertBinaryTree (int argc, char ** argv) {
    printf ("driver not ready\n");
    return 0;
}

int lc232_ImplementQueueUsingStacks (int argc, char ** argv) {
    printf ("driver 232 not ready yet\n");
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
    int inputArraySize = argc - 2;
    int * inputArray;
    int * nums2;
    int nums2Size[1];
    int * returnedArray;
    int returnedArraySize[1];

    if (inputArraySize < 0) {
        return -1;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);

    printf ("How many numbers in nums2? ");
    scanf ("%d", nums2Size);
    nums2 = malloc(sizeof *nums2 * *nums2Size);
    printf ("Input nums2, separated with spaces: ");
    for (int i = 0; i < *nums2Size; i++)
        if (scanf ("%d", nums2 + i) != 1) {
            fprintf (stderr, "Error in parsing input.\n");
            return -1;
        }

    printf ("nums1:\n");
    printIntArray (inputArray, inputArraySize);
    printf ("nums2:\n");
    printIntArray (nums2, *nums2Size);
    printf ("\n");

    returnedArray = intersect (inputArray, inputArraySize, nums2, *nums2Size, returnedArraySize);

    printf ("return:\n");
    printIntArray (returnedArray, *returnedArraySize);

    free (inputArray);
    free (returnedArray);

    return 0;
}

int lc383_RansomNote (int argc, char ** argv) {
    const char * usage = \
        USAGE_PREFIX "383 <note> <magazine>\n" \
        "Check if a complete ransom note can be made by characters in given magazine.\n";

    if (argc < 2) {
        printf ("%s", usage);
        return 0;
    }

    printf("%s\n", canConstruct(argv[0], argv[1]) ? "True" : "False");

    return 0;
}

int lc387_FirstUniqueChar (int argc, char ** argv) {
    const char * usage = \
        USAGE_PREFIX "387 <string>\n" \
        "Return the index of the first non-repeating character in given string.\n" \
        "If it does not exist, return -1.\n";

    if (argc != 1) {
        printf ("%s", usage);
        return 0;
    }

    return firstUniqChar (*argv);
}

int lc566_MatrixReshape (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "566 <new-row> <new-column> <column> <integer> [<integer> ...]\n"
        "Reshape the given matrix.\n";
    int elementCount = argc - 5;
    int ** inputMatrix;
    int newRow, newColumn, row, column;
    int ** reshaped;
    int returnedRow[1];
    int * returnedColumn[1];

    if (elementCount < 1) {
        printf ("%s", usage);
        return 0;
    }

    newRow = atoi (argv[2]);
    newColumn = atoi (argv[3]);
    column = atoi (argv[4]);
    row = matrixGetRow (elementCount, column);

    inputMatrix = parseArgsToIntMatrix (argc, argv, argc - elementCount, elementCount, column);

    printf ("Input matrix:\n");
    printIntMatrix (inputMatrix, row, column);

    reshaped = matrixReshape (inputMatrix, row, &column, newRow, newColumn, returnedRow, returnedColumn);

    printf ("Reshaped:\n");
    printIntMatrix (reshaped, *returnedRow, **returnedColumn);

    if (reshaped != inputMatrix) {
        freeIntMatrix (reshaped, *returnedRow);
    }
    if (*returnedColumn != &column) {
        free (*returnedColumn);
    }
    freeIntMatrix (inputMatrix, row);
    return 0;
}

int lc700_SearchBst (int argc, char ** argv) {
    printf ("driver not ready\n");
    return 0;
}

int lc701_InsertIntoABinaryTree (int argc, char ** argv) {
    printf ("driver not ready\n");
    return 0;
}

int lc977_SortSquare (int argc, char ** argv) {
    int inputArraySize = argc - 2;
    int * inputArray;
    int * returnedValue;
    int returnedArraySize;

    if (inputArraySize < 0) {
        return -1;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnedValue = sortedSquares (inputArray, inputArraySize, &returnedArraySize);

    printIntArray (returnedValue, returnedArraySize);

    free (inputArray);
    free (returnedValue);
    return 0;
}

int lc1290_Bin2Int (int argc, char ** argv) {
    Node * inputList = parseArgsToLinkedList (argv + 2);
    return getDecimalValue (inputList);
}

int lc2078_maxDistance (int argc, char ** argv) {
    int inputArraySize = argc - 2;
    int * inputArray;
    int returnedValue;

    if (inputArraySize < 0) {
        return -1;
    }

    inputArray = parseArgsToIntArray (argc, argv, argc - inputArraySize, inputArraySize);
    returnedValue = maxDistance (inputArray, inputArraySize);
    free (inputArray);

    return returnedValue;
}

int lc2085_CountCommonWordsWithOneOccurrence (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2085 <words1size> <words2size> <string> [<string> ...] <string> [<string> ...]\n"
        "Count strings that appear exactly once in both string arrays.\n";
    int words1Size;
    int words2Size;
    char ** words1;
    char ** words2;
    int returnValue;

    if (argc < 6) {
        printf ("%s", usage);
        return 0;
    }

    words1Size = atoi (argv[2]);
    words2Size = atoi (argv[3]);

    if (words1Size + words2Size + 4 != argc) {
        fprintf (stderr,
            "error: invalid number of arguments\n"
            "Provided sizes are %d and %d (total %d), but the real total size is %d.\n",
            words1Size,
            words2Size,
            words1Size + words2Size,
            argc - 4);
        return -1;
    }

    words1 = parseArgsToStringArray (argc, argv, 4, words1Size);
    words2 = parseArgsToStringArray (argc, argv, 4 + words1Size, words2Size);
    returnValue = countWords (words1, words1Size, words2, words2Size);

    freeStringArray (words1, words1Size);
    freeStringArray (words2, words2Size);
    return returnValue;
}

int lc2086_FeedTheHamsters (int argc, char ** argv) {
    const char * usage =
        USAGE_PREFIX "2086 <string>\n"
        "Return the minimum number of food buckets to feed the hamsters.\n"
        "String can only contain `H', representing a hamster, or `.', representing a place to put a bucket.\n";

    if (argc != 1) {
        printf ("%s", usage);
        return 0;
    }

    return minimumBuckets (*argv);
}

int lc2087_RobotComingHome (int argc, char ** argv) {
    int start[2] = {1, 0};
    int home[2] = {2, 3};
    int rowCosts[3] = {5, 4, 3};
    int colCosts[4] = {8, 2, 6, 7};

    return minCost(start, 2, home, 2, rowCosts, 3, colCosts, 4);
}

int lc2089_FindTargetIndicesAfterSortingArray (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2089 <target> <integer> [<integer> ...]\n"
        "Return the indices of all occurrences of target integer after sorting the given\n"
        "array in non-decreasing order.  The returned array must be sorted in increasing\n"
        "order.\n";
    int target;
    int inputSize = argc - 3;
    int * input;
    int * returnedValues;
    int returnedSize[1];

    if (inputSize < 1) {
        printf ("%s", usage);
        return 0;
    }

    target = atoi (argv[2]);
    input = parseArgsToIntArray (argc, argv, argc - inputSize, inputSize);

    printf ("input array:\n");
    printIntArray (input, inputSize);

    returnedValues = targetIndices (input, inputSize, target, returnedSize);
    printf ("returned array:\n");
    printIntArray (returnedValues, *returnedSize);

    free (input);
    free (returnedValues);
    return 0;
}

int lc2090_KRadiusSubarrayAverages (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2090 <k> <integer> [<integer> ...]\n"
        "Return a integer array containing the average values of range [i - k, i + k] of\n"
        "the given array.  If i - k < 0 or i + k > array size, the average is -1.\n";
    int k;
    int inputSize = argc - 3;
    int * input;
    int * returnedArray;
    int returnedSize[1];

    if (inputSize < 1) {
        printf ("%s", usage);
        return 0;
    }

    k = atoi (argv[2]);
    input = parseArgsToIntArray (argc, argv, argc - inputSize, inputSize);

    printf ("input array:\n");
    printIntArray (input, inputSize);

    returnedArray = getAverages (input, inputSize, k, returnedSize);
    printf ("returned array:\n");
    printIntArray (returnedArray, *returnedSize);

    free (input);
    free (returnedArray);
    return 0;
}

int lc2091_RemovingMinumumAndMaximumFromArray (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2091 <integer> [<integer> ...]\n"
        "Return the minimum number of deletions it would take to remove the both the\n"
        "minimum and maximum element from the given array of *distinct* integers.\n"
        "A deletion is removing an element from either the front or the back of the\n"
        "array.\n";
    int inputSize = argc - 2;
    int * input;
    int returnedValue;

    if (inputSize < 1) {
        printf ("%s", usage);
        return 0;
    }

    inputSize = argc;
    input = parseArgsToIntArray (argc, argv, argc - inputSize, inputSize);
    printf ("input array:\n");
    printIntArray (input, inputSize);

    returnedValue = minimumDeletions (input, inputSize);
    free (input);
    return returnedValue;
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

int lc2094_Finding3DigitEvenNumbers (int argc, char ** argv) {
    const char * usage = USAGE_PREFIX "2094 <digit> <digit> <digit> [<digit> ...]\n"
        "Find all 3-digit even numbers that consist of 3 elements from given array.\n";
    int inputSize = argc - 2;
    int * input;
    int * returnedValues;
    int returnedSize[1];

    if (inputSize < 3) {
        printf ("%s", usage);
        return 0;
    }

    input = parseArgsToIntArray (argc, argv, argc - inputSize, inputSize);
    returnedValues = findEvenNumbers (input, inputSize, returnedSize);
    printIntArray (returnedValues, *returnedSize);

    free (input);
    free (returnedValues);
    return 0;
}

int lc2095_DeleteTheMiddleNodeOfALinkedList (int argc, char ** argv) {
    const char * usage =
        USAGE_PREFIX "2095 <integer> [<integer>]\n"
        "Delete the middle node of given linked list.\n"
        "The middle node of linked list of size N is the N/2-th (0-based) node.\n";
    Node * input;

    if (argc < 1) {
        printf ("%s", usage);
        return 0;
    }

    input = parseArgsToLinkedList (argv);
    PrintList (deleteMiddle (input));
    FreeLinkedList (input);
    return 0;
}

int main (int argc, char **argv) {
    int returnedValue;
    int problemNumber;

    if (argc < 2) {
        printf("%s", driver_usage);
        return 0;
    }

    problemNumber = atoi (argv[1]);

    if (problemNumber <= 0) {
        printf("%s", driver_usage);
        return 0;
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
        case 36:
            returnedValue = lc036_ValidSudoku (argc, argv);
            break;
        case 53:
            returnedValue = lc053_MaxSubarray (argc, argv);
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
            returnedValue = lc234_Palindrome_ll (argc, argv);
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
            returnedValue = lc1290_Bin2Int (argc, argv);
            break;
        case 2078:
            returnedValue = lc2078_maxDistance (argc, argv);
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
            returnedValue = lc2090_KRadiusSubarrayAverages (argc, argv);
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
            returnedValue = 1;
            break;
    }

    if (returnedValue != 0) {
        fprintf(stderr, "warning: Return value is %d\n", returnedValue);
    }
    return returnedValue;
}
