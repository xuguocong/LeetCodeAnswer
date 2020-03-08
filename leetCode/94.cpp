// 94. 二叉树的中序遍历
// 给定一个二叉树，返回它的中序 遍历。

// 示例:

// 输入: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// 输出: [1,3,2]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal_recursive(TreeNode* root) {
        if(root == NULL) return res;
        inorderTraversal_recursive(root->left);
        res.push_back(root->val);
        inorderTraversal_recursive(root->right);
        return res;
    }
    vector<int> inorderTraversal_iteration(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || s.size()) {
            while(p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
private:
    vector<int> res;
};


int main() {
    Solution test;
    return 0;
}