// 384. 打乱数组
// 打乱一个没有重复元素的数组。

// 示例:

// // 以数字集合 1, 2 和 3 初始化数组。
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);

// // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
// solution.shuffle();

// // 重设数组到它的初始状态[1,2,3]。
// solution.reset();

// // 随机返回数组[1,2,3]打乱后的结果。
// solution.shuffle();
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
    vector<int> vec;
public:
    Solution(vector<int>& nums) : vec(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = vec;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }
};