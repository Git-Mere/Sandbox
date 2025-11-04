#include "Dynamic Programming.h"

void recur(vector<int>& coins, int current, int result, int& best) {
    if (current <= 0) {
        if (best > result) { best = result; }
        return;
    }
    result++;
    bool flag = false;
    for (int coin : coins) {
        if (current - coin >= 0) {
            flag = true;
            recur(coins, current - coin, result, best);
        }
    }
    if (!flag) { best = -1; return; }
}
//int DP::coinChange(vector<int>& coins, int amount) {
//    if (amount == 0) { return 0; }
//
//    //sort(coins.begin(), coins.end(), greater<int>());
//    int result = 0;
//    int best = numeric_limits<int>::max();
//    recur(coins, amount, 0, best);
//
//    return best;
//}

int DP::coinChange(vector<int>& coins, int amount) {
    if (amount < 0) 
        return -1;
    if (amount == 0) 
        return 0;

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

//int DP::coinChange(vector<int>& coins, int amount) {
//    if (amount == 0) { return 0; }
//
//    int result = 0;
//    int start = amount;
//    std::sort(coins.begin(), coins.end(), std::greater<int>());
//
//    while (start > 0) {
//        bool flag = false;
//        for (int coin : coins) {
//            if (start - coin >= 0) {
//                start -= coin;
//                result++;
//                flag = true;
//                break;
//            }
//        }
//        if (flag == false) {
//            return -1;
//        }
//    }
//
//
//    return result;
//}