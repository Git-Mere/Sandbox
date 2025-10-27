#include "Array.h"

int Array::maxArea(vector<int>& height) {
    int result = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left != right) {
        int dist = right - left;
        int heigh = min(height[left], height[right]);
        if (result < dist * heigh) {
            result = dist * heigh;
        }
        if (height[left] < height[right]) {
            left++;
        }
        else {
            right--;
        }
    }
    return result;
}