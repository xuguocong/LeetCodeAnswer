// 33. 搜索旋转排序数组
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 示例 1:

// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:

// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(left == right) return (nums[left] == target ? left : -1);
            int mid = (left + right) / 2;
            if(nums[left] < nums[mid]) {
                if(nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if(nums[right] >= target && nums[mid] <= target) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution test;
    return 0;
}