// 163. 缺失的区间
// 给定一个排序的整数数组 nums ，其中元素的范围在 闭区间 [lower, upper] 当中，返回不包含在数组中的缺失区间。

// 示例：

// 输入: nums = [0, 1, 3, 50, 75], lower = 0 和 upper = 99,
// 输出: ["2", "4->49", "51->74", "76->99"]
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
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int size = nums.size();
        long long left = (long long)lower - 1;
        long long val;
        for (int i = 0; i < size; ++i) {
            val = nums[i] - left;
            if (val == 2) {
                res.push_back(to_string(nums[i] - 1));
            } else if (val > 2) {
                res.push_back(to_string(left + 1) + "->" + to_string(nums[i] - 1));
            }
            left = nums[i];
        }
        val = upper - left;
        if (val == 1) {
            res.push_back(to_string(upper));
        } else if (val > 1) {
            res.push_back(to_string(left + 1) + "->" + to_string(upper));
        }
        return res;
    }
};


int main() {
    Solution test;
    vector<int> num = {0, 1, 3, 50, 75};
    test.findMissingRanges(num, 0, 99);
    return 0;
}