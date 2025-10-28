#include "Binary.h"

int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

int Binary::missingNumber(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    return sum_to_n(nums.size()) - sum;
}