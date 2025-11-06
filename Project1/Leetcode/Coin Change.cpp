#include "Dynamic Programming.h"

///////////////////////// Brute-Force Recursion (Top-Down)
int coinChange(vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;

    int min_count = INT_MAX;

    for (int coin : coins) {
        int res = coinChange(coins, amount - coin);
        // If a solution exists for the subproblem
        if (res >= 0 && res < min_count) {
            min_count = 1 + res;
        }
    }

    return (min_count == INT_MAX) ? -1 : min_count;
}


///////////////////////// Top-Down Dynamic Programming with Memoization

int solve(vector<int>& coins, int rem, vector<int>& memo) {
    if (rem < 0) return -1; // Invalid state
    if (rem == 0) return 0;  // Base case: amount is 0
    if (memo[rem] != -2) return memo[rem]; // Return cached result

    int min_count = INT_MAX;

    for (int coin : coins) {
        int res = solve(coins, rem - coin, memo);
        if (res >= 0 && res < min_count) {
            min_count = 1 + res;
        }
    }

    // Cache the result before returning
    memo[rem] = (min_count == INT_MAX) ? -1 : min_count;
    return memo[rem];
}

int coinChange2(vector<int>& coins, int amount) {
    // memo[i] will store the min coins for amount i.
    // Initialize with -2 to indicate "not computed yet".
    vector<int> memo(amount + 1, -2);
    return solve(coins, amount, memo);
}

///////////////////////// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
int coinChange3(vector<int>& coins, int amount) {
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