#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *head = NULL, *p;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val) {
            head = l1;
            p1 = l1->next;
        } else {
            head = l2;
            p2 = l2->next;
        }
        p = head;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val <= p2->val) {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        if (p1 == NULL) p->next = p2;
        if (p2 == NULL) p->next = p1;
        return head;
    }
};


int main() {
    Solution test;
    ListNode *p1 = new ListNode(2);
    // p1->next = new ListNode(2);
    // p1->next->next = new ListNode(4);
    ListNode *p2 = new ListNode(1);
    // p2->next = new ListNode(3);
    // p2->next->next = new ListNode(4);

    ListNode* p = test.mergeTwoLists(p1, p2);
    while(p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }
}