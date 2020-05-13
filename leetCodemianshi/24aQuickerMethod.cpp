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
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ( (a = *pp) && (b = a->next)){
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};


int main() {
    Solution test;
    ListNode *p1 = new ListNode(1);
    p1->next = new ListNode(2);
    p1->next->next = new ListNode(3);
    // p1->next->next->next = new ListNode(4);
    ListNode* p = test.swapPairs(p1);
    cout << endl;
    while(p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }
}