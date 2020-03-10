// 108. 将有序数组转换为二叉搜索树
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

// 示例:

// 给定有序数组: [-10,-3,0,5,9],

// 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

//       0
//      / \
//    -3   9
//    /   /
//  -10  5
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 双向队列更优
class Solution {
public:
    vector<int> num;
    TreeNode* sortedArrayToBST_recursive(vector<int>& nums) {
        if(!nums.size()) return NULL;
        TreeNode *node = new TreeNode(nums[nums.size()/2]);
        vector<int> left(nums.begin(), nums.begin()+ nums.size()/2);
        vector<int> right(nums.begin() + nums.size()/2 + 1, nums.end());
        node->left = sortedArrayToBST_recursive(left);
        node->right = sortedArrayToBST_recursive(right);
        return node;
    }

    TreeNode* build(int left, int right) {
        if(left > right) return NULL;
        int p = (left + right) / 2;
        TreeNode *root = new TreeNode(num[p]);
        root->left = build(left, p - 1);
        root->right = build(p + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        num = nums;
        return build(0, nums.size() - 1);
    }
};


int main() {
    Solution test;
    return 0;
}