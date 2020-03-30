// 面试题05. 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

// 示例 1：

// 输入：s = "We are happy."
// 输出："We%20are%20happy."
 

// 限制：

// 0 <= s 的长度 <= 10000
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
    string replaceSpace(string s) {
        string res;
        for (char c : s) {
            if (c == ' ') {
                res += "%20";
            } else {
                res += c;
            }
        }
        return res;
    }
};