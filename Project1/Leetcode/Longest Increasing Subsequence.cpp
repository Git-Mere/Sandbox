#include "Dynamic Programming.h"

int DP::lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    dp[0] = 1;

    for (int i = 1; i < nums.size(); i++) {
        int max_dp = -1;
        int max_index = -1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && max_dp < dp[j]) {
                max_dp = dp[j];
                max_index = j;
            }
        }

        if (max_index != -1) {
            dp[i] = dp[max_index] + 1;
        }

    }

    return *max_element(dp.begin(), dp.end());


}