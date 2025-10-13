#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int sum = 0;

    for (int i = 0; i < size - 1; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = size - 1;
        int k = i + 1;
        if ((nums[i] < 0 && nums[j] < 0) || (nums[i] > 0 && nums[j] > 0)) { break; }

        while (j != k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                result.push_back({ nums[i], nums[j], nums[k] });
                while (nums[k] == nums[k - 1] && k < j) {
                    k++;
                }
            }
            else if (sum > 0) { j--; }
            else if (sum < 0) { k++; }
        }

    }

    return result;
}


int main() {
    std::vector<int> test{ 1,2 };
    for (int i = 0; i < test.size(); i++) {
        std::cout << i << std::endl;
        test.pop_back();
    }

    std::vector<int> limits = { 0,0,0,0 };
    threeSum(limits);
    return 0;
}