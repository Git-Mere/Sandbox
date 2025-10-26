#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;


int getSum(int a, int b) {
    int xor_v = a ^ b;
    int and_v = a & b;

    if (and_v == 0) {
        return xor_v;
    }
    else if (xor_v == 0) {
        return and_v << 1;
    }

    and_v <<= 1;

    return getSum(xor_v, and_v);
}


int main() {
    getSum(1, 2);
    return 0;
}