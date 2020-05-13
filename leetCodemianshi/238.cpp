// 238. 除自身以外数组的乘积
// 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

// 示例:

// 输入: [1,2,3,4]
// 输出: [24,12,8,6]
 

// 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

// 进阶：
// 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<unordered_set>
#include<bitset>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1;
        vector<int> res(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i) {
            res[i] *= left;
            left *= nums[i];

            res[nums.size()-i-1] *= right;
            right *= nums[nums.size()-i-1];

        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}