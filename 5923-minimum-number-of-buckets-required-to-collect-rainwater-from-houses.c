int minimumBuckets (char * street) {
    char ch;
    int i = -1;
    int houses = 0;
    int clearing = 0;
    int ret = 0;

    while ((ch = street[++i])) {
        if (ch == 'H') {
            houses++;
            if (i > 0 && street[i - 1] == 'B')
                continue;
            if (street[i + 1] == 'H' || !street[i + 1]) {
                if (i > 0 && street[i - 1] == '.') {
                    street[i - 1] = 'B';
                    ret++;
                    continue;
                } else {
                    return -1;
                }
            }
            street[i + 1] = 'B';
            ret++;
        } else {
            clearing++;
        }
    }

    if (!houses)
        return 0;

    if (!clearing)
        return -1;

    return ret;
}
