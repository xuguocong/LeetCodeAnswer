// 387. 字符串中的第一个唯一字符
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

// 案例:

// s = "leetcode"
// 返回 0.

// s = "loveleetcode",
// 返回 2.
 

// 注意事项：您可以假定该字符串只包含小写字母。
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
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            ++map[c];
        }
        for(int i = 0; i < s.length(); ++i) {
            if(map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution test;
    test.firstUniqChar("leetcode");
    return 0;
}