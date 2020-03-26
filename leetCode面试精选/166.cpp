// 166. 分数到小数
// 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

// 如果小数部分为循环小数，则将循环的部分括在括号内。

// 示例 1:

// 输入: numerator = 1, denominator = 2
// 输出: "0.5"
// 示例 2:

// 输入: numerator = 2, denominator = 1
// 输出: "2"
// 示例 3:

// 输入: numerator = 2, denominator = 3
// 输出: "0.(6)"
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
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        if(numerator == 0) return "0";
        long num = long(numerator);
        long den = long(denominator);
        string res;
        if (num < 0 ^ den < 0) res += "-";
        num = abs(num);
        den = abs(den);
        res += to_string(num / den);
        num %= den;
        if (num == 0) {
            return res;
        }
        res += ".";
        int loop_ind = -1;
        unordered_map<long, long> m;
        while (num != 0) {
            if (m.count(num)) {
                loop_ind = m[num];
                break;
            } else {
                m[num] = res.size();
            }
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        if (num == 0) {
            return res;
        }
        return res.substr(0, loop_ind) + "(" + res.substr(loop_ind) + ")";
    }
};


int main() {
    Solution test;
    return 0;
}