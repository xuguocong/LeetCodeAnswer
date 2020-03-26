// 340. 至多包含 K 个不同字符的最长子串
// 给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。

// 示例 1:

// 输入: s = "eceba", k = 2
// 输出: 3
// 解释: 则 T 为 "ece"，所以长度为 3。
// 示例 2:

// 输入: s = "aa", k = 1
// 输出: 2
// 解释: 则 T 为 "aa"，所以长度为 2。
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        unordered_map<char, int> map;
        int count = 0, left = 0, right = 0, res = 0;
        while(left <= right) {
            while (right < s.length() && count <= k) {
                if (map[s[right]] == 0) {
                    map[s[right]] = 1;
                    ++count;
                    ++right;
                } else {
                    ++map[s[right]];
                    ++right;
                }
            }
            if (right >= s.length()) {
                if (count > k) {
                    return max(res, right - left - 1);
                } else {
                    return max(res, right - left);
                }
            }
            res = max(res, right - left - 1);
            while(left <= right && count > k) {
                if (--map[s[left++]] <= 0) {
                    --count;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution test;
    cout << test.lengthOfLongestSubstringKDistinct("eceba", 2);
    return 0;
}