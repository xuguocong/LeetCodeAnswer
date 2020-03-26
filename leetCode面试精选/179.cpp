// 179. 最大数
// 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

// 示例 1:

// 输入: [10,2]
// 输出: 210
// 示例 2:

// 输入: [3,30,34,5,9]
// 输出: 9534330
// 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
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

bool cmp(string &a, string &b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> tmp;
        for(int n : nums) {
            tmp.push_back(to_string(n));
        }

        sort(tmp.begin(), tmp.end(), cmp);
        if(tmp[0] == "0") return "0";
        string res = "";
        for(string &s : tmp) {
            res += s;
        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}