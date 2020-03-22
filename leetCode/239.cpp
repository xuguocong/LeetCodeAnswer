// 239. 滑动窗口最大值
// 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回滑动窗口中的最大值。

 

// 示例:

// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7] 
// 解释: 

//   滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
 

// 提示：

// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        vector<int> res;
        deque<int> index;
        for(int i = 0; i < k; ++i) {
            while(!index.empty() && nums[i] > nums[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }
        res.push_back(nums[index.front()]);
        for(int i = k; i < nums.size(); ++i) {
            while(!index.empty() && index.front() <= i -k) {
                index.pop_front();
            }
            while(!index.empty() && nums[i] > nums[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
            res.push_back(nums[index.front()]);
        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}