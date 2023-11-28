#include <string.h>
#include "2147-number-of-ways-to-divide-a-long-corridor.h"

#define RETURN_VALUE_MODULO     1000000007

int numberOfWays (char * corridor) {
    int answer = 1;
    int i = -1;
    int seatCount = 0;
    int lastSeat = -1;

    while (corridor[++i] != '\0') {
        if (corridor[i] != 'S') {
            continue;
        }
        if (seatCount == 0 && lastSeat != -1) {
            answer = (answer * (i - lastSeat)) % RETURN_VALUE_MODULO;
        }
        if (++seatCount == 2) {
            seatCount = 0;
            lastSeat = i;
        }
    }

    if (seatCount != 0 || lastSeat == -1) {
        return 0;
    }

    return answer % RETURN_VALUE_MODULO;
}
