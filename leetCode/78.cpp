// 78. 子集
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

// 示例:

// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets_recursive(vector<int>& nums) {
        vector<int> item;
        addLetter(nums, item, true, 0);
        addLetter(nums, item, false, 0);
        return res;
    }
    vector<vector<int>> subsets_bitwise(vector<int>& nums) {
        for(int i = 0; i < (1 << nums.size()); ++i) {
            vector<int> item;
            for(int j = 0; j < nums.size(); ++j) {
                if((i >> j & 1) == 1) item.emplace_back(nums[j]);
            }
            res.emplace_back(item);
        }
        return res;
    }
private:
    vector<vector<int>> res;
    void addLetter(vector<int>& nums, vector<int> item, bool flag, int n) {
        if(n >= nums.size()) {
            if(flag) res.push_back(item);
            return;
        }
        if(flag) item.push_back(nums[n]);
        addLetter(nums, item, true, n+1);
        addLetter(nums, item, false, n+1);
    }
};


int main() {
    Solution test;
    vector<int> nums = {1,2,3};
    return 0;
}