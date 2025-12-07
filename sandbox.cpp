#include <vector>

//Fibonacci
int body(int n){
    std::vector<int> memo(n + 1, -1);
    return fib(n, memo);
}

int fib(int n, std::vector<int>& memo){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

    return memo[n];
}

int fib(int n){
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

//Coin changer
int coinChange(std::vector<int>& coins, int amount){
    //동전은 1,2,5원짜리만 있음.
    if(amount < 0){
        return -1;
    }
    if(amount == 0){
        return 0;
    }

    int next = 1'000'000;
    for(int coin : coins){
        if(amount - coin >= 0){
            int test = coinChange(coins, amount - coin);
            if(test != -1){
                next = std::min(next, test + 1);
            }
        }
    }

    return next == 1000000 ? -1 : next;
}

//memoization
int coinChange(std::vector<int>& coins, int amount, std::vector<int>& memo){
    //동전은 1,2,5원짜리만 있음.
    if(amount < 0){
        return -1;
    }
    if(amount == 0){
        return 0;
    }
    if(memo[amount] != INT_MAX){
        return memo[amount];
    }

    for(int coin : coins){
        if(amount - coin >= 0){
            int test = coinChange(coins, amount - coin, memo);
            if(test >= 0){
                memo[amount] = std::min(memo[amount], test + 1);
            }
        }
    }

    return memo[amount] == INT_MAX ? -1 : memo[amount];
}

//dp
int coinChange(std::vector<int>& coins, int amount){
    //동전은 1,2,5원짜리만 있음.
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++){
        for(int coin : coins){
            if(i - coin >= 0){
                dp[i] = std::min(dp[i - coin] + 1, dp[i]);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int tiling(int n){
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}