#include "Array.h"

int Array::maxProduct(vector<int>& nums) {
    int size = nums.size();
    int current = nums[0];
    int max_value1 = nums[0];
    for (int i = 1; i < size; i++) {
        //max_value = max(abs(current * nums[i]), abs(nums[i]));
        if (abs(current * nums[i]) < abs(nums[i])) {
            current = nums[i];
        }
        else {
            current = current * nums[i];
        }

        if (max_value1 < current) {
            max_value1 = current;
        }
    }

    current = nums[size - 1];
    int max_value2 = nums[size - 1];

    for (int i = size - 2; i >= 0; i--) {
        if (abs(current * nums[i]) < abs(nums[i])) {
            current = nums[i];
        }
        else {
            current = current * nums[i];
        }

        if (max_value1 < current) {
            max_value1 = current;
        }
    }

    return max(max_value1, max_value2);
}