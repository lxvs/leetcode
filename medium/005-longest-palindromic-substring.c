#include <string.h>
#include <stdlib.h>
#include "005-longest-palindromic-substring.h"

static int palindromeAround (int center_left, int center_right, const char * const s) {
    int sLength = strlen (s);

    while (center_left >= 0 && center_right < sLength && s[center_left] == s[center_right]) {
        center_left--;
        center_right++;
    }
    return center_right - center_left + 1 - 2;
}

char * longestPalindrome (char * s) {
    char * longest;
    int max_position, length_odd, length_even, length_longer;
    int max_length = 0;
    int sLength = strlen (s);

    for (int center = 0; center < sLength - max_length / 2; center++) {
        length_odd = palindromeAround (center, center, s);
        length_even = palindromeAround (center, center + 1, s);
        if (max_length < (length_longer = max (length_odd, length_even))) {
            max_position = center;
            max_length = length_longer;
        }
    }

    longest = malloc ((max_length + 1) * sizeof *longest);
    strncpy (longest, s + max_position - (max_length - 1) / 2, max_length);
    longest[max_length] = '\0';

    return longest;
}
