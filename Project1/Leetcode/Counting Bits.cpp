#include "Binary.h"

void make_vector(vector<int>& vec, int n, int start) {
    if (start > n) {
        return;
    }
    copy(vec.begin(), vec.begin() + start, vec.begin() + start);
    for_each(vec.begin() + start, vec.begin() + (start * 2), [](int& x) {
        x++;
        });
    make_vector(vec, n, start * 2);
}

vector<int> Binary::countBits(int n) {
    vector<int> result(1 + n * 2, 0);
    if (n == 0) {
        return result;
    }
    result[1] = 1;
    make_vector(result, n, 2);
    result.resize(n + 1);
    return result;
}