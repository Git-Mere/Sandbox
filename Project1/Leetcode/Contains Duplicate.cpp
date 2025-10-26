#include "Control_Header.h"

bool Array::containsDuplicate(vector<int>& nums) {
    std::map<int, int> help2;
    for (int i = 0; i < nums.size(); i++) {
        if (!help2.count(nums[i])) {
            help2[nums[i]] = i;
        }
        else {
            return true;
        }


    }
    return false;
}