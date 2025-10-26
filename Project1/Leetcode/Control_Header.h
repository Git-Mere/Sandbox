#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

namespace Array {
	vector<int> twoSum(vector<int>& nums, int target);
	int maxProfit(vector<int>& prices);
	bool containsDuplicate(vector<int>& nums);
	vector<int> productExceptSelf(vector<int>& nums);
	int maxSubArray(vector<int>& nums);
	int maxProduct(vector<int>& nums);
	int findMin(vector<int>& nums);
	int search(vector<int>& nums, int target);
	vector<vector<int>> threeSum(vector<int>& nums);
	int maxArea(vector<int>& height);
}

namespace Binary {
	int getSum(int a, int b);
	int hammingWeight(int n);
}