// 341. 扁平化嵌套列表迭代器
// 给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

// 列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

 

// 示例 1:

// 输入: [[1,1],2,[1,1]]
// 输出: [1,1,2,1,1]
// 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
// 示例 2:

// 输入: [1,[4,[6]]]
// 输出: [1,4,6]
// 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。

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


class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    vector<int> v;
    int ind = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto iter = nestedList.begin(); iter != nestedList.end(); iter++) {
            parseData(*iter);
        }
    }
    void parseData(NestedInteger item) {
        if (item.isInteger()) {
            v.push_back(item.getInteger());
        } else {
            auto list = item.getList();
            for (auto iter = list.begin(); iter != list.end(); iter++) {
                parseData(*iter);
            }
        }
    }

    int next() {
        return v[ind++];
    }

    bool hasNext() {
        if (ind >= v.size()) return false;
        return true;
    }
};
