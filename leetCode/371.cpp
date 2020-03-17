// 371. 两整数之和
// 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

// 示例 1:

// 输入: a = 1, b = 2
// 输出: 3
// 示例 2:

// 输入: a = -2, b = 3
// 输出: 1
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
    int getSum(int a, int b) {
        while(b) {
            int carry = (unsigned int)(a&b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};


int main() {
    Solution test;
    return 0;
}