// 204. 计数质数
// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
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
    int countPrimes(int n) {
        int count = 0;
        vector<bool> signs(n, true);
        for (int i = 2; i < n; i++) {
            if (signs[i]) {
                count++;
                for (int j = i + i; j < n; j += i) {
                    signs[j] = false;
                }
            }
        }
        return count;
    }
};


int main() {
    Solution test;
    return 0;
}
