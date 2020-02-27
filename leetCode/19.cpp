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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int p = 1;
        ListNode *ptr = head, *del = head, *predel = head;
        while(ptr -> next != NULL) {
            if(p == n) {
                ptr = ptr->next;
                del = del->next;
            } else if(p > n) {
                ptr = ptr->next;
                del = del->next;
                predel = predel->next;
            } else {
                ptr = ptr->next;
            }
            ++p;
        }

        if(del == head) {
            return head->next;
        }

        predel->next = del->next;
        return head;
    }
};


int main() {
    Solution test;
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    test.removeNthFromEnd(head, 4);
}