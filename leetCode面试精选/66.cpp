// 66. 加一
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 示例 1:

// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123。
// 示例 2:

// 输入: [4,3,2,1]
// 输出: [4,3,2,2]
// 解释: 输入数组表示数字 4321。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag =true;
        for(int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += 1;
            if(digits[i] > 9) {
                digits[i] %= 10;
            } else {
                return digits;
            }
        }
        vector<int>::iterator it = digits.begin();
        digits.insert(it, 1);
        return digits;
    }
};


int main() {
    Solution test;
    return 0;
}