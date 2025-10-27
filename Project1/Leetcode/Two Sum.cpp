#include "Array.h"

vector<int> Array::twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int one, two;
    for (int i = 0; i < nums.size(); i++) {
        one = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            two = nums[j];
            if (target - one == two || target - two == one) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}