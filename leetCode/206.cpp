// 206. 反转链表
// 反转一个单链表。

// 示例:

// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList_iteration(ListNode* head) {
        if(!head) return head;
        ListNode *newhead = head;
        head = head->next;
        newhead->next = NULL;
        while(head != NULL) {
            ListNode *temp = head->next;
            head->next = newhead;
            newhead = head;
            head = temp;
        }
        return newhead;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *cur = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
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
    test.reverseList(head);
    return 0;
}