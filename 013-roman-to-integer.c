int romanToInt (char * s) {
    int roman_symbols[26] = {0};
    char * p = s;
    int result = 0;

    roman_symbols['I' - 'A'] = 1;
    roman_symbols['V' - 'A'] = 5;
    roman_symbols['X' - 'A'] = 10;
    roman_symbols['L' - 'A'] = 50;
    roman_symbols['C' - 'A'] = 100;
    roman_symbols['D' - 'A'] = 500;
    roman_symbols['M' - 'A'] = 1000;

    while (*p != '\0') {
        if (*(p + 1) != '\0') {
            if (roman_symbols[(unsigned)(*p - 'A')] < roman_symbols[(unsigned)(*(p + 1) - 'A')]) {
                result += roman_symbols[(unsigned)(*(p + 1) - 'A')] - roman_symbols[(unsigned)(*p - 'A')];
                p += 2;
                continue;
            } else {
                result += roman_symbols[(unsigned)(*p - 'A')];
                p++;
                continue;
            }
        } else {
            result += roman_symbols[(unsigned)(*p - 'A')];
            break;
        }
    }

    return result;
}
