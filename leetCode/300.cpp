// 300. 最长上升子序列
// 给定一个无序的整数数组，找到其中最长上升子序列的长度。

// 示例:

// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4 
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
// 说明:

// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
// 你算法的时间复杂度应该为 O(n2) 。
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
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
    int lengthOfLIS_dp(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size() + 1);
        int count = 1;
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]);
            }
            count = max(++dp[i], count);
        }
        return count;
    }

    int lengthOfLIS_greedy(vector<int>& nums) {
        vector<int> tails(nums.size() + 1);
        int res = 0;
        for(int num : nums) {
            int i = 0, j = res;
            while(i < j) {
                int m = (i + j) / 2;
                if(tails[m] < num) i = m + 1;
                else j = m;
            }
            tails[i] = num;
            if(res == j) res++;
        }
        return res;
    }
};

int main() {
    Solution test;
    vector<int> t = {1, 3, 5, 2, 10};
    test.lengthOfLIS_greedy(t);
    return 0;
}