#include "Control_Header.h"

vector<int> Array::productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    vector<int> prefix(nums.size(), 0);
    vector<int> suffix(nums.size(), 0);

    int size = nums.size();
    int help = 1;

    for (int i = 0; i < size; i++) {
        help *= nums[i];
        prefix[i] = help;
    }

    int help2 = 1;
    for (int i = size - 1; i >= 0; i--) {
        help2 *= nums[i];
        suffix[i] = help2;
    }

    for (int i = 0; i < size; i++) {
        if (i + 1 == size) {
            result[i] = prefix[i - 1];
        }
        else if (i == 0) {
            result[i] = suffix[i + 1];
        }
        else {
            result[i] = prefix[i - 1] * suffix[i + 1];
        }
    }
    return result;
}