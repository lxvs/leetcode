#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/debug.h"

static void palindromeAround (char * center_left, char * center_right, char * longest, int * max_length, char * s) {
    char * walker = center_right;
    char * back_walker = center_left;
    int length = center_right - center_left + 1;

    dbg ("arguments: %ld, %ld, <longest>, %d, <s>\n", center_left - s, center_right - s, *max_length);
    dbg ("walker: %c\n", *walker);
    dbg ("back_walker: %c\n", *back_walker);
    dbg ("length: %d\n", length);

    while (*walker != '\0' && back_walker >= s && *walker == *back_walker) {
        length += 2;
        walker++;
        back_walker--;
    }
    length -= 2;
    back_walker++;
    if (length > *max_length) {
        *max_length = length;
        strncpy(longest, back_walker, *max_length);
        dbg ("new longest: %s, length: %d\n", longest, length);
    }
}

char * longestPalindrome (char * s) {
    char * longest;
    char * c = s;
    int max_length = 0;

    longest = malloc ((strlen(s) + 1) * sizeof *longest);
    if (longest == NULL) {
        fprintf (stderr, "error: failed to allocate %lu byte(s)\n", (strlen(s) + 1) * sizeof *longest);
        return NULL;
    }

    while (c != NULL && *c != '\0') {
        dbg ("walking to %c\n", *c);
        palindromeAround (c, c, longest, &max_length, s);
        if (*(c + 1) == *c) {
            dbg ("walking to %c%c\n", *c, *(c + 1));
            palindromeAround (c, c + 1, longest, &max_length, s);
        }
        c++;
    }

    return longest;
}
