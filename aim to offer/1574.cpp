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

#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		: val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return nullptr;
		unordered_map<int, vector<int>::iterator> map;
		for (auto it = inorder.begin(); it != inorder.end(); it++) {
			map[*it] = it;
		}

		return helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), map);
	}

	TreeNode* helper(vector<int>::iterator preStart, vector<int>::iterator preEnd, vector<int>::iterator inStart, vector<int>::iterator inEnd, unordered_map<int, vector<int>::iterator>& map) {
		if (preStart == preEnd) {
			return nullptr;
		}

		TreeNode* cur = new TreeNode(*preStart);
		if (preEnd - preStart == 1) return cur;
		vector<int>::iterator temp = map[*preStart];
		int len = temp - inStart;
		cur->left = helper(preStart + 1, preStart + 1 + len, inStart, temp, map);
		cur->right = helper(preStart + 1 + len, preEnd, temp + 1, inEnd, map);
		return cur;
	}
};

int main() {
	Solution test;
	vector<int> p = {2, 1};
	vector<int> i = {1, 2};

	test.buildTree(p, i);
	return 0;
}
