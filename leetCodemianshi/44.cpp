// 44. 通配符匹配
// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符串（包括空字符串）。
// 两个字符串完全匹配才算匹配成功。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
// 示例 1:

// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。
// 示例 2:

// 输入:
// s = "aa"
// p = "*"
// 输出: true
// 解释: '*' 可以匹配任意字符串。
// 示例 3:

// 输入:
// s = "cb"
// p = "?a"
// 输出: false
// 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 示例 4:

// 输入:
// s = "adceb"
// p = "*a*b"
// 输出: true
// 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 示例 5:

// 输入:
// s = "acdcb"
// p = "a*c?b"
// 输入: false
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isMatch_dp(string s, string p) {
        if (p == s || p == "*") return true;
        if (p.empty() || s.empty()) return false;
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.length(); ++i){
            if(p[i - 1] == '*' && dp[0][i - 1]) dp[0][i] = dp[0][i - 1];
        }
        for(int i = 1; i <= s.length(); ++i) {
            for(int j = 1; j <= p.length(); ++j) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[s.length()][p.length()];
    }

    bool isMatch_greedy(string s, string p) {
        int i = 0, j = 0, sLen = s.length(), pLen = p.length(), iStar = -1, jStar = -1;
        while(i < sLen) {
            if(j < pLen && (s[i] == p[j] || p[j] == '?')) {
                ++i;
                ++j;
            } else if(j < pLen && p[j] == '*') {
                iStar = i;
                jStar = j++;
            } else if(iStar >= 0) {
                i = ++iStar;
                j = jStar + 1;
            } else {
                return false;
            }
        }
        while (j < pLen && p[j] == '*') ++j;
        return j == pLen;
    }
};


int main() {
    Solution test;
    return 0;
}