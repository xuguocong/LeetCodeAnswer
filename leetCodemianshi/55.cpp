// 55. 跳跃游戏
// 给定一个非负整数数组，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个位置。

// 示例 1:

// 输入: [2,3,1,1,4]
// 输出: true
// 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
// 示例 2:

// 输入: [3,2,1,0,4]
// 输出: false
// 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        for(int i = nums.size() - 2; i >= 0; --i) {
            for(int j = i + 1; j <= i + nums[i]; ++j) {
                if(j >= nums.size()) {
                    dp[i] = 1;
                    break;
                } else if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }

    bool canJump_greedy(vector<int>& nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};


int main() {
    Solution test;
    vector<int> t = {2,3,1,1,4};
    test.canJump(t);
    return 0;
}