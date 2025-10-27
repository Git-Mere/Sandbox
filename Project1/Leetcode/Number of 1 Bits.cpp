#include "Binary.h"

int Binary::hammingWeight(int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            result++;
        }
    }
    return result;
}