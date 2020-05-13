// 140. 单词拆分 II
// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

// 说明：

// 分隔时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：

// 输入:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// 输出:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
// 示例 2：

// 输入:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// 输出:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// 解释: 注意你可以重复使用字典中的单词。
// 示例 3：

// 输入:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出:
// []
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
    vector<string> wordBreak_dp(string s, vector<string>& wordDict) {
        if(!wordBreak139(s, wordDict)) return {};
        int validEnd = 0;
        vector<vector<string>> dp(s.length() + 1, vector<string>());
        for(int i = 0; i < s.length(); ++i) {
            if(i != 0 && dp[i].empty()) continue;
            for(auto& word : wordDict) {
                int newEnd = i + word.size();
                if(newEnd > s.size()) continue;
                if(memcmp(&s[i], &word[0], word.size()) != 0) continue;
                validEnd = max(validEnd, newEnd);
                if(i == 0) {
                    dp[newEnd].push_back(word);
                    continue;
                }
                for(auto& w : dp[i]) {
                    dp[newEnd].push_back(w + " " + word);
                }
            }
        }
        return dp.back();
    }

    bool wordBreak139(string &s, vector<string>& wordDict) {
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
    return 0;
}