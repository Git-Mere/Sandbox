#include "Dynamic Programming.h"
int DP::mincostTickets(std::vector<int>& days, std::vector<int>& costs) {

    int size = *max_element(days.begin(), days.end());
    std::vector<int> dp(size + 1, size + 1);

    for (int cost : costs) {
        dp[cost] = cost;
    }

    for (int i = 1; i <= size; i++) {
        for (int day : days) {
            if (day == i) {
                for (int cost : costs) {
                    if (i - cost >= 0) {
                        dp[i] = min(dp[i - cost] + cost, dp[i]);
                    }
                }
                break;
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[size];
}