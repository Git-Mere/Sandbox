#include "Dynamic Programming.h"

int DP::climbStairs(int n) {
    if (n <= 3) {
        return n;
    }
    int prev1 = 3;
    int prev2 = 2;
    int cur = 0;

    for (int i = 3; i < n; i++) {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    return cur;
}




// recursive version
void recur(int n, int& count) {
    if (n == 0) {
        count++;
        return;
    }


    if (n - 2 >= 0) {
        recur(n - 2, count);
    }
    recur(n - 1, count);

}

int climbStairs_recur(int n) {
    int count = 0;
    recur(n, count);
    return count;
}