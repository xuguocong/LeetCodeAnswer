// 46. 全排列
// 给定一个没有重复数字的序列，返回其所有可能的全排列。

// 示例:

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        change(nums.size(), nums, res, 0);
        return res;
    }
private:
    void change(int n, vector<int> nums, vector<vector<int>> &res, int first) {
        if(first == n) res.push_back(nums);
        for(int i = first; i < n; i++) {
            swap(nums[first], nums[i]);
            change(n, nums, res, first + 1);
            swap(nums[first], nums[i]);
        }
    }
};


int main() {
    Solution test;
    return 0;
}