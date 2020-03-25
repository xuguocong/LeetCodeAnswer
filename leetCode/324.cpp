// 324. 摆动排序 II
// 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

// 示例 1:

// 输入: nums = [1, 5, 1, 1, 6, 4]
// 输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
// 示例 2:

// 输入: nums = [1, 3, 2, 2, 3, 1]
// 输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
// 说明:
// 你可以假设所有输入都会得到有效的结果。

// 进阶:
// 你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
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

#define A(i) nums[(1 + 2 * i) % (len | 1)]
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        quickSelect(nums, 0, len, len / 2);
        auto midptr = nums.begin() + len / 2;
        int mid = *midptr;


        int i = 0, j = 0, k = len - 1;
        while (j <= k) {
            if (A(j) > mid) {
                swap(A(i++) , A(j++));
            } else if (A(j) < mid) {
                swap(A(j), A(k--));
            } else {
                ++j;
            }
        }
    }

private:
    void quickSelect(vector<int>& nums, int begin, int end, int sit) {
        int temp = nums[end - 1];
        int i = begin, j = begin;
        while(j < end) {
            if(nums[j] <= temp) {
                swap(nums[i++], nums[j++]);
            } else {
                ++j;
            }
        }

        if(i - 1 > sit) {
            quickSelect(nums, begin, i - 1, sit);
        } else if (i <= sit) {
            quickSelect(nums, i, end, sit);
        }
    }
};

int main() {
    Solution test;
    vector<int> t = {1,5,1,1,6,4};
    test.wiggleSort(t);
    return 0;
}