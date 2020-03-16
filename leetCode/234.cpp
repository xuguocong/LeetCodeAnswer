// 234. 回文链表
// 请判断一个链表是否为回文链表。

// 示例 1:

// 输入: 1->2
// 输出: false
// 示例 2:

// 输入: 1->2->2->1
// 输出: true

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
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        vector<int> vals;
        while(p) {
            vals.push_back(p->val);
            p = p->next;
        }
        int p1 = 0, p2 = vals.size() - 1;
        while (p1 <= p2) {
            if(vals[p1] == vals[p2]) {
                ++p1;
                --p2;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome_reverse(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = reverseList(slow->next);
        slow = head;
        bool result = true;
        while(result && second != nullptr) {
            if(slow->val != second->val) return false;
            slow = slow->next;
            second = second->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};


int main() {
    Solution test;
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    for(int i = 1; i < nums.size(); ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return 0;
}