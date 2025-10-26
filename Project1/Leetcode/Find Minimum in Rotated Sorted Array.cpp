#include "Control_Header.h"

int Array::findMin(vector<int>& nums) {
    int size = nums.size() / 2;
    int index = nums.size() / 2;

    int first = nums[0];
    int mid = nums[index];

    while (mid != first) {
        if (mid < first) {
            index -= size / 2 < 1 ? 1 : size / 2;
            if (index == -1) { index++; }

        }
        else if (mid > first) {
            first = nums[index];
            index += size / 2 < 1 ? 1 : size / 2;
            if (index == nums.size()) { index--; }
        }
        mid = nums[index];
        size /= 2;
    }


    return index == (nums.size() - 1) ? nums[0] : nums[index + 1];
};