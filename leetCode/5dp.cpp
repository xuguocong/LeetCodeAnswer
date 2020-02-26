#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define max(a,b) a > b ? a : b
int findSubString(string s, int start, int end) {
    while(start >= 0 && end < s.length() && s[end] == s[start]) {
        start--;
        end++;
    }
    return end - start - 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2) return s;
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        int maxLen(1); // 最长子串长度
        int start(0);
        for(int j = 0; j < s.length(); j++) {
            for(int i = 0; i <= j; ++i) {
                if(j - i < 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && maxLen < j - i + 1) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);

    }
};


int main() {
    Solution test;
    string s = "abbassssssssssssssssss";
    cout << test.longestPalindrome(s) << endl;
}