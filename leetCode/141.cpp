// 141. 环形链表
// 给定一个链表，判断链表中是否有环。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

// 示例 1：

// 输入：head = [3,2,0,-4], pos = 1
// 输出：true
// 解释：链表中有一个环，其尾部连接到第二个节点。


// 示例 2：

// 输入：head = [1,2], pos = 0
// 输出：true
// 解释：链表中有一个环，其尾部连接到第一个节点。


// 示例 3：

// 输入：head = [1], pos = -1
// 输出：false
// 解释：链表中没有环。

// 进阶：

// 你能用 O(1)（即，常量）内存解决此问题吗？

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
    bool hasCycle_hash(ListNode *head) {
        unordered_map<ListNode *, bool> map;
        while(head) {
            if(map.count(head) == 0) {
                map[head] = true;
            } else {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *slow = head, *fast = head->next;
        while(slow != fast) {
            if(fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};


int main() {
    Solution test;
    return 0;
}