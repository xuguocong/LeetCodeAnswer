// 面试题03. 数组中重复的数字
// 找出数组中重复的数字。


// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

// 示例 1：

// 输入：
// [2, 3, 1, 0, 2, 5, 3]
// 输出：2 或 3 
 

// 限制：

// 2 <= n <= 100000
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
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> n;

        for(auto i : nums) {
            if(n.find(i) != n.end()) {
                return i;
            } else {
                n.insert(i);
            }
        }
        return -1;
    }
};