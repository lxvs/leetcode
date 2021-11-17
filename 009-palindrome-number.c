#include "009-palindrome-number.h"

bool isPalindrome (int x) {
    int reversed = 0;

    if (x < 0 || x && !(x % 10))
        return false;

    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return x == reversed || x == reversed / 10;
}
