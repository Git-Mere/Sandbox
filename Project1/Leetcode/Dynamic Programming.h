#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

namespace DP {
	int climbStairs(int n);
	int coinChange(vector<int>& coins, int amount); //recursive
	int coinChange2(vector<int>& coins, int amount); //recursive + memoization
	int coinChange3(vector<int>& coins, int amount); //dynamic programming
	int lengthOfLIS(vector<int>& nums);
	int longestCommonSubsequence(string text1, string text2);
}