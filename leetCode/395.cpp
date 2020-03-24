// 395. 至少有K个重复字符的最长子串
// 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

// 示例 1:

// 输入:
// s = "aaabb", k = 3

// 输出:
// 3

// 最长子串为 "aaa" ，其中 'a' 重复了 3 次。
// 示例 2:

// 输入:
// s = "ababbc", k = 2

// 输出:
// 5

// 最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
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
    int longestSubstring(string s, int k) {
        if(s.empty()) return 0;
        unordered_map<int, int> map;
        for (auto c : s) {
            auto it = map.find(c);
            if (it == map.end()) {
                map[c] = 1;
            } else {
                map[c]++;
            }
        }

        bool isAll = true;
        for(auto it = map.begin(); it != map.end(); it++) {
            if (it->second < k) {
                isAll = false;
                break;
            }
        }
        if(isAll) return s.size();

        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            int start = i, num = 0;
            while (i < s.size() && map[s[i]] >= k) {
                ++i;
                ++num;
            }
            if (num > 0) res = max(longestSubstring(s.substr(start, num), k), res);
        }
        return res;
    }
};

int main() {
    Solution test;
    return 0;
}