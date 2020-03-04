// 41. 缺失的第一个正数
// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

// 示例 1:

// 输入: [1,2,0]
// 输出: 3
// 示例 2:

// 输入: [3,4,-1,1]
// 输出: 2
// 示例 3:

// 输入: [7,8,9,11,12]
// 输出: 1
// 说明:

// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        bool f = true;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i] = 1;
            } else if(nums[i] == 1) {
                f = false;
            }
        }
        if(f) return 1;

        for(i = 0; i < nums.size(); i++) {
            nums[abs(nums[i]) - 1] = - abs(nums[abs(nums[i]) - 1]);
        }
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) return i + 1;
        }
        return nums.size() + 1;
    }
};


int main() {
    Solution test;
    return 0;
}