// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 如果数组中不存在目标值，返回 [-1, -1]。

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if(left == right) break;
            int mid = (left + right) / 2;
            if(target >= nums[mid]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if(nums[left] != target) return {-1, 1};
        while(nums[left--] == target);
        while(nums[right++] == target);
        return {left + 1, right - 1};
    }
};


int main() {
    Solution test;
    return 0;
}