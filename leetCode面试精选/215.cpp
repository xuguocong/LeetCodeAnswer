// 215. 数组中的第K个最大元素
// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 示例 1:

// 输入: [3,2,1,5,6,4] 和 k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
// 输出: 4
// 说明:

// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
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
    int findKthLargest_sort(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    int findKthLargest_heap(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if(q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};

int main() {
    Solution test;
    return 0;
}
