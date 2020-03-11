// 124. 二叉树中的最大路径和
// 给定一个非空二叉树，返回其最大路径和。

// 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

// 示例 1:

// 输入: [1,2,3]

//        1
//       / \
//      2   3

// 输出: 6
// 示例 2:

// 输入: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// 输出: 42
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

class Solution {
public:
    int sum = INT_MIN;
    int maxSubTree(TreeNode* root) {
        if(root == NULL) return 0;

        int max_left = max (maxSubTree(root->left), 0);
        int max_right = max (maxSubTree(root->right), 0);

        sum = max(sum, sum + max_left + max_right);
        return root->val + max(max_left, max_right);
    }

    int maxPathSum(TreeNode* root) {
        maxSubTree(root);
        return sum;
    }
};


int main() {
    Solution test;
    return 0;
}