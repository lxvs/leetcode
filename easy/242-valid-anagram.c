#include "242-valid-anagram.h"

bool isAnagram (char * s, char * t) {
    int letters[26] = {0};
    int i = 0;

    for (; s[i] != '\0' && t[i] != '\0'; i++) {
        letters[s[i] - 'a']++;
        letters[t[i] - 'a']--;
    }

    if (s[i] != '\0' || t[i] != '\0') {
        return false;
    }

    for (i = 0; i < 26; i++) {
        if (letters[i]) {
            return false;
        }
    }

    return true;
}
