#include <stdbool.h>

bool isValid (char * s) {
    char stack[5001];
    int top = 0;

    for (int i = 0; s[i] != '\0'; i++)
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                if (top > 5000)
                    return false;
                stack[top++] = s[i];
                break;

            case ')':
                if (!top || stack[--top] != '(')
                    return false;
                break;

            case ']':
                if (!top || stack[--top] != '[')
                    return false;
                break;

            case '}':
                if (!top || stack[--top] != '{')
                    return false;
                break;

            default:
                return false;
                break;
        }

    if (top)
        return false;

    return true;
}
