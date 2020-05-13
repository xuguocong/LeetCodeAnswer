// 315. 计算右侧小于当前元素的个数
// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

// 示例:

// 输入: [5,2,6,1]
// 输出: [2,1,1,0] 
// 解释:
// 5 的右侧有 2 个更小的元素 (2 和 1).
// 2 的右侧仅有 1 个更小的元素 (1).
// 6 的右侧有 1 个更小的元素 (1).
// 1 的右侧有 0 个更小的元素.
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

struct SegmentTree {
public:
    int start;
    int end;
    int count;

    SegmentTree *left;
    SegmentTree *right;

    SegmentTree(int _start, int _end) : start(_start), end(_end), count(0), left(nullptr), right(nullptr) {

    }
};

SegmentTree* build(int start, int end) {
        if (start > end) {
            return NULL;
        }

        SegmentTree *root = new SegmentTree(start, end);

        if (start == end) {
            root->count = 0;
        } else {
            int mid = start + (end - start) / 2;
            root->left = build(start, mid);
            root->right = build(mid + 1, end);
        }
        return root;
    }

    int count(SegmentTree *root, int start, int end) {
        if (root == nullptr || start > end) {
            return 0;
        }
        if (start == root->start && end == root->end) {
            return root->count;
        }

        int mid = root->start + (root->end - root->start) / 2;
        int leftCount = 0, rightCount = 0;

        if (start <= mid) {
            if (mid < end) {
                leftCount = count(root->left, start, mid);
            } else {
                leftCount = count(root->left, start, end);
            }
        }

        if (mid < end) {
            if (start <= mid) {
                rightCount = count(root->right, mid + 1, end);
            } else {
                rightCount = count(root->right, start, end);
            }
        }
        return leftCount + rightCount;
    }

    void insert(SegmentTree *root, int index, int val) {
        if(root->start == index && root->end == index) {
            root->count += val;
            return;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (index >= root->start && index <= mid) {
            insert(root->left, index, val);
        }
        if (index > mid && index <= root->end) {
            insert(root->right, index, val);
        }

        root->count = root->left->count + root->right->count;
    }
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> res(nums.size());
        int start = nums[0];
        int end = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            start = min(start, nums[i]);
            end = max(end, nums[i]);
        }

        SegmentTree *root = build(start, end);

        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = count(root, start, nums[i] - 1);
            insert(root, nums[i], 1);
        }

        return res;
    }
};