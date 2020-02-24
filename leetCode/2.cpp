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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int l, r, sum;
        ListNode *head = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *curr = head;
        while(p1 != NULL || p2 != NULL || carry != 0) {
            if(p1 == NULL) {
                l = 0;
            } else {
                l = p1->val;
                p1 = p1->next;
            }
            if(p2 == NULL) {
                r = 0;
            } else {
                r = p2->val;
                p2 = p2->next;
            }
            sum = l + r + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return head->next;
    }
};


int main() {
    Solution test;
}