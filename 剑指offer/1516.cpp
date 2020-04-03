// 面试题07. 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7
 

// 限制：

// 0 <= 节点个数 <= 5000
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, vector<int>::iterator> map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(vector<int>::iterator it = inorder.begin(); it != inorder.end(); it++) {
            map[*it] = it;
        }
        return buildHelper(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }

    TreeNode* buildHelper(vector<int>::iterator inbegin, vector<int>::iterator inend, vector<int>::iterator prebegin, vector<int>::iterator preend) {
        if (prebegin == preend) { return nullptr; }
        TreeNode *node = new TreeNode(*prebegin);
        if(preend - prebegin == 1) return node;
        vector<int>::iterator temp = map[*prebegin];
        int len = temp - inbegin;
        node->left = buildHelper(inbegin, temp, prebegin + 1, prebegin + 1 + len);
        node->right = buildHelper(temp + 1, inend, prebegin + 1 + len, preend);
        return node;
    }
};