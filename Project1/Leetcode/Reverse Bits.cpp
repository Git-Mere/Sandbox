#include "Binary.h"

int Binary::reverseBits(int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & (1 << i))) {
            int pos = 31 - i;
            result |= (1 << pos);
        }
    }
    return result;
}