// 101. 对称二叉树
// 给定一个二叉树，检查它是否是镜像对称的。

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3
// 说明:

// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

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
    bool isSymmetric_iteration(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode *> quk;
        quk.push(root->left);
        quk.push(root->right);
        while (!quk.empty()) {
            TreeNode *t1 = quk.front();
            quk.pop();
            TreeNode *t2 = quk.front();
            quk.pop();
            if (t1 == nullptr && t2 == nullptr) continue;
            if (t1 == nullptr || t2 == nullptr) return false;
            if (t1->val != t2->val) return false;
            quk.push(t1->left);
            quk.push(t2->right);
            quk.push(t1->right);
            quk.push(t2->left);
        }
        return true;
    }
    bool isSymmetric_recursive(TreeNode* root) {
        return symmetric(root, root);
    }
private:
    bool symmetric(TreeNode *p1, TreeNode *p2) {
        if(p1 == NULL && p2 == NULL) return true;
        if(p1 == NULL || p2 == NULL) return false;
        return (p1->val == p2->val) && symmetric(p1->left, p2->right) && symmetric(p2->left, p1->right);
    }
};


int main() {
    Solution test;
    return 0;
}