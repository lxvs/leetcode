#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int letters[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++)
        letters[magazine[i] - 'a']++;

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (letters[ransomNote[i] - 'a'] > 0)
            letters[ransomNote[i] - 'a']--;
        else
            return false;
    }

    return true;
}
