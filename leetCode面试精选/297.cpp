// 297. 二叉树的序列化与反序列化
// 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

// 示例: 

// 你可以将以下二叉树：

//     1
//    / \
//   2   3
//      / \
//     4   5

// 序列化为 "[1,2,3,null,null,4,5]"
// 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

// 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<set>
#include<bitset>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *temp = q.front(); q.pop();
            if(temp) {
                res += to_string(temp->val) + ' ';
                q.push(temp->left);
                q.push(temp->right);
            } else {
                res += "null ";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> list;
        for(int l = 0, r = 0; l < data.size(); ) {
            r = l;
            while(data[r] != ' ') ++r;
            if(data[l] == 'n') {
                l = r + 1;
                list.push_back(NULL);
                continue;
            }
            list.push_back(new TreeNode(stoi(data.substr(l, r - l))));
            l = r + 1;
        }
        TreeNode *head = list[0], *cur = head;
        for(int i = 1, j = 1; j < list.size() && i < list.size(); ++j) {
            if (!cur) {
                cur = list[j];
                continue;
            }
            cur->left = list[i];
            cur->right = list[i+1];
            cur = list[j];
            i += 2;
        }
        return head;
    }
};

int main() {
    Codec c;
    c.deserialize("1 2 3 null null 4 5 ");
    return 0;
}