// 139. 单词拆分
// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

// 说明：

// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：

// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 示例 2：

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。
// 示例 3：

// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<string.h>

#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        unordered_set<string> map(wordDict.begin(), wordDict.end());

        dp[0] = true;
        for(int i = 1; i <= s.length(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && map.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        int validEnd = 0;
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.length(); ++i) {
            if(i == validEnd + 1) return false;
            if(!dp[i]) continue;
            for(auto& word : wordDict) {
                int newEnd = i + word.size();
                if(newEnd > s.size()) continue;
                if(memcmp(&s[i], &word[0], word.size()) == 0) {
                    dp[newEnd] = true;
                    validEnd = max(validEnd, newEnd);
                }
            }
        }
        return dp.back();
    }
};


int main() {
    Solution test;
    string s = "applepenapple";
    vector<string> w = {"apple","pen"};
    test.wordBreak2(s, w);
    return 0;
}