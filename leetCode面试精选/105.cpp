// 105. 从前序与中序遍历序列构造二叉树
// 根据一棵树的前序遍历与中序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return buildTree(preorder, pos, inorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int& pos, vector<int>& inorder, int left, int right) {
        if(pos >= preorder.size()) return NULL;
        int i = left;
        for(; i <= right; ++i) { // 此处的搜索操作可以使用hash表加速
            if(inorder[i] == preorder[pos]) break;
        }
        TreeNode *node = new TreeNode(preorder[pos]);
        if(left <= i - 1) node->left = buildTree(preorder, ++pos, inorder, left, i-1);
        if(i + 1 <= right) node->right = buildTree(preorder, ++pos, inorder, i+1, right);
        return node;
    }
};


int main() {
    Solution test;
    return 0;
}