// 152. 乘积最大子序列
// 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

// 示例 1:

// 输入: [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:

// 输入: [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSub = 1;
        int minSub = 1;
        int res = nums[0];
        for (auto& n : nums) {
            if (n < 0) {
                swap(maxSub, minSub);
            }
            maxSub = max(n, n * maxSub);
            minSub = min(n, n * minSub);
            res = max(res, maxSub);
        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}