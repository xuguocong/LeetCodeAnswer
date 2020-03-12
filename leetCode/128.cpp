// 128. 最长连续序列
// 给定一个未排序的整数数组，找出最长连续序列的长度。

// 要求算法的时间复杂度为 O(n)。

// 示例:

// 输入: [100, 4, 200, 1, 3, 2]
// 输出: 4
// 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int n: nums) st.insert(n);
        int ans = 0;
        for(int i: st){
            if(i != INT_MIN && st.count(i-1)){
                continue;
            }
            int cnt = 1;
            while(i!=INT_MAX && st.count(i+1)){
                cnt ++;
                i++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }

    int longestConsecutive_dp(vector<int>& nums) {
        unordered_map<int, int> dp;
        int max_len = 0;
        for(auto &x : nums) {
            if(!dp[x]) {
                int cur_len = dp[x-1] + dp[x+1] + 1;
                if(cur_len > max_len) max_len = cur_len;
                dp[x] = dp[x - dp[x-1]] = dp[x + dp[x+1]] = cur_len;
            }
        }
        return max_len;
    }
};


int main() {
    Solution test;
    vector<int> t = {100, 4, 200, 1, 3, 2};
    test.longestConsecutive_dp(t);
    return 0;
}