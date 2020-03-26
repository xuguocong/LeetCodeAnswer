// 155. 最小栈
// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) -- 将元素 x 推入栈中。
// pop() -- 删除栈顶的元素。
// top() -- 获取栈顶元素。
// getMin() -- 检索栈中的最小元素。
// 示例:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<unordered_set>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int x) {
        if(minValue > x) {
            minValue = x;
        }
        min_stack.push({minValue, x});
    }

    void pop() {
        min_stack.pop();
        if(min_stack.empty()) {
            minValue = INT_MAX;
        } else if (min_stack.top().first > minValue) {
            minValue = min_stack.top().first;
        }
    }

    int top() {
        return min_stack.top().second;
    }

    int getMin() {
        return min_stack.top().first;
    }
private:
    int minValue = INT_MAX;
    stack<pair<int, int>> min_stack;
};


int main() {
    return 0;
}