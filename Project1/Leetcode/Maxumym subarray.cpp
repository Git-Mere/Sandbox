#include "Control_Header.h"

int Array::maxSubArray(vector<int>& nums) {
    int size = nums.size();

    int current = nums[0];
    int max = current;
    for (int i = 1; i < size; i++) {
        int add = current + nums[i];
        if (add < nums[i]) {
            current = nums[i];
        }
        else {
            current = add;
        }

        if (max < current) {
            max = current;
        }
    }

    return max;
}