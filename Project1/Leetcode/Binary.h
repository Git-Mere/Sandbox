#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <bit>
#include <bitset>
#include <numeric>

using namespace std;

namespace Binary {
	int getSum(int a, int b);
	int hammingWeight(int n);
	vector<int> countBits(int n);
	int missingNumber(vector<int>& nums);
}