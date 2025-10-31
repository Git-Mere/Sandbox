#include "Array.h"

int Array::search(vector<int>& nums, int target) {
    int size = nums.size();
    int first_v = 0, mid = size / 2, last = size - 1;
    if (size <= 3) {
        if (nums[mid] == target) { return mid; }
        else if (nums[first_v] == target) { return first_v; }
        else if (nums[last] == target) { return last; }
        else { return -1; }
    }
    else {
        while (first_v != mid) {
            if (nums[mid] == target) { return mid; }
            else if (nums[first_v] == target) { return first_v; }
            else if (nums[last] == target) { return last; }

            if (nums[first_v] < nums[mid] && nums[mid] < nums[last]) {
                if (nums[first_v] < target && target < nums[mid]) {
                    last = mid;
                    mid = (first_v + last) / 2;
                }
                else {
                    first_v = mid;
                    mid = (first_v + last) / 2;
                }
            }
            else if (nums[first_v] < nums[mid] && nums[mid] > nums[last]) {
                if (nums[first_v] < target && target < nums[mid]) {
                    last = mid;
                    mid = (first_v + last) / 2;
                }
                else {
                    first_v = mid;
                    mid = (first_v + last) / 2;
                }
            }
            else if (nums[first_v] > nums[mid] && nums[mid] < nums[last]) {
                if (nums[mid] < target && target < nums[last]) {
                    first_v = mid;
                    mid = (first_v + last) / 2;
                }
                else {
                    last = mid;
                    mid = (first_v + last) / 2;
                }
            }
        }
    }

    return -1;
}