// 148. 排序链表
// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

// 示例 1:

// 输入: 4->2->1->3
// 输出: 1->2->3->4
// 示例 2:

// 输入: -1->5->3->4->0
// 输出: -1->0->3->4->5
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList_iteration(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *p = head;
        int length = 0;
        while(p) {
            ++length;
            p = p->next;
        }

        for(int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;

            while(cur) {
                auto left = cur;
                auto right = cut(left, size);
                cur = cut(right, size);

                tail->next = merge(left, right);
                while(tail->next) tail = tail->next;
            }
        }
        return dummyHead.next;
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }

    ListNode* cut(ListNode *head, int n) {
        auto p = head;
        while(--n && p) p = p->next;
        if(!p) return NULL;
        auto next = p->next;
        p->next = NULL;
        return next;
    }

    ListNode* sortList_recursive(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeTwoList(sortList_recursive(head), sortList_recursive(slow));
    }

    ListNode* mergeTwoList(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoList(l2->next, l1);
            return l2;
        }
    }
};


int main() {
    Solution test;
    return 0;
}