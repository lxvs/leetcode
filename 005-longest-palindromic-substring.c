#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/debug.h"

#define MAX_VALUE(a, b)     (a > b ? a : b)

static int palindromeAround (int center_left, int center_right, const char * const s) {
    int s_length = strlen (s);

    while (center_left >= 0 && center_right < s_length && s[center_left] == s[center_right]) {
        center_left--;
        center_right++;
    }
    return center_right - center_left + 1 - 2;
}

char * longestPalindrome (char * s) {
    char * longest;
    int max_position, length_odd, length_even, length_longer;
    int max_length = 0;
    int s_length = strlen (s);

    for (int center = 0; center < s_length - max_length; center++) {
        dbg ("walking to s[%d]: %c\n", center, s[center]);
        length_odd = palindromeAround (center, center, s);
        length_even = palindromeAround (center, center + 1, s);
        if (max_length < (length_longer = MAX_VALUE (length_odd, length_even))) {
            max_position = center;
            max_length = length_longer;
        }
    }

    longest = malloc ((max_length + 1) * sizeof *longest);
    strncpy (longest, s + max_position - (max_length - 1) / 2, max_length);
    longest[max_length] = '\0';

    return longest;
}
