// 面试题06. 从尾到头打印链表
// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

// 示例 1：

// 输入：head = [1,3,2]
// 输出：[2,3,1]
 

// 限制：

// 0 <= 链表长度 <= 10000
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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint_vector(ListNode* head) {
        vector<int> res;
        ListNode *p = head;
        while(p) {
            res.emplace_back(p->val);
            p = p->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> reversePrint_stack(ListNode* head) {
        vector<int> res;
        stack<int> nums;
        ListNode *p = head;
        while(p) {
            nums.push(p->val);
            p = p->next;
        }
        res.reserve(nums.size());
        while(!nums.empty()) {
            res.emplace_back(nums.top());
            nums.pop();
        }
        return res;
    }
};