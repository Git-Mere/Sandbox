#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"

int coinChange(vector<int>& coins, int amount) {
    // dp[i] will be storing the minimum number of coins required for amount i.
    // We use amount + 1 as an "infinity" value.
    vector<int> dp(amount + 1, amount + 1);

    // Base case: 0 coins are needed for amount 0.
    dp[0] = 0;

    // Iterate through all amounts from 1 to the target amount.
    for (int i = 1; i <= amount; ++i) {
        // For each amount, check each coin.
        for (int coin : coins) {
            if (i - coin >= 0) {
                // If we can use this coin, update the dp table for the current amount.
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    // If dp[amount] is still the "infinity" value, it means the amount cannot be formed.
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> a{ 2};
    int test = 3;
    cout << coinChange(a, test);
    return 0;
}