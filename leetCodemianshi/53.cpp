// 53. 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray_Method_GREEDY(vector<int>& nums) {
        int currentmax = nums[0], finalRes = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            currentmax = max(nums[i], nums[i] + currentmax);
            finalRes = max(finalRes, currentmax);
        }
        return finalRes;
    }

    int maxSubArray_Method_DP(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > 0) nums[i] += nums[i-1];
            res = max(res, nums[i]);
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<int> t = {-2,1,-3,4,-1,2,1,-5,4};
    cout << test.maxSubArray_Method_DP(t);
    return 0;
}