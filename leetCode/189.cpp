// 189. 旋转数组
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

// 示例 1:

// 输入: [1,2,3,4,5,6,7] 和 k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右旋转 1 步: [7,1,2,3,4,5,6]
// 向右旋转 2 步: [6,7,1,2,3,4,5]
// 向右旋转 3 步: [5,6,7,1,2,3,4]
// 示例 2:

// 输入: [-1,-100,3,99] 和 k = 2
// 输出: [3,99,-1,-100]
// 解释: 
// 向右旋转 1 步: [99,-1,-100,3]
// 向右旋转 2 步: [3,99,-1,-100]
// 说明:

// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 要求使用空间复杂度为 O(1) 的 原地 算法。
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
    void rotate_reverse(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        k %= nums.size();
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void rotate_swap(vector<int>& nums, int k) {
        k %= nums.size();
        int count = 0;
        for(int i = 0; count < nums.size(); ++i) {
            int cur = i;
            int tmp = nums[cur];
            do {
                int next = (cur + k) % nums.size();
                int pre = nums[next];
                nums[next] = tmp;
                tmp = pre;
                cur = next;
                ++count;
            } while(cur != i);
        }
    }
};


int main() {
    Solution test;
    vector<int> n = {1,2,3,4,5,6,7};
    test.rotate_swap(n, 3);
    return 0;
}