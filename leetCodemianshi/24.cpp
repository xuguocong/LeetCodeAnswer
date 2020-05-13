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
        if(head == NULL || head->next == NULL) return head;
        ListNode *ptr = head, *preptr;
        head = head->next;
        ptr->next = head->next;
        head->next = ptr;
        preptr = ptr;
        ptr = ptr->next;
        while(ptr != NULL && ptr->next != NULL) {
            preptr->next = ptr->next;
            ptr->next = ptr->next->next;
            preptr->next->next = ptr;

            preptr = ptr;
            ptr = ptr->next;
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