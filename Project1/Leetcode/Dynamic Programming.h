#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>


using namespace std;

namespace DP {
	int climbStairs(int n);
	int coinChange(vector<int>& coins, int amount); //recursive
	int coinChange2(vector<int>& coins, int amount); //recursive + memoization
	int coinChange3(vector<int>& coins, int amount); //dynamic programming
}