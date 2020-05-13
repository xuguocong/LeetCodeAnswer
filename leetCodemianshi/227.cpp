// 227. 基本计算器 II
// 实现一个基本的计算器来计算一个简单的字符串表达式的值。

// 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

// 示例 1:

// 输入: "3+2*2"
// 输出: 7
// 示例 2:

// 输入: " 3/2 "
// 输出: 1
// 示例 3:

// 输入: " 3+5 / 2 "
// 输出: 5
// 说明：

// 你可以假设所给定的表达式都是有效的。
// 请不要使用内置的库函数 eval。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char sign = '+';
        int num = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ' )|| i == s.size() - 1) {
                int pre;
                switch(sign) {
                    case '+':
                        nums.push(num);
                        break;
                    case '-' :
                        nums.push(-num);
                        break;
                    case '*' :
                        pre = nums.top();
                        nums.pop();
                        pre *= num;
                        nums.push(pre);
                        break;
                    case '/' :
                        pre = nums.top();
                        nums.pop();
                        pre /= num;
                        nums.push(pre);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        while (!nums.empty()) {
            num += nums.top();
            nums.pop();
        }
        return num;
    }
};


int main() {
    Solution test;
    test.calculate("3+2*2");
    return 0;
}