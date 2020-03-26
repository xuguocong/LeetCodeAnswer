// 251. 展开二维向量
// 请设计并实现一个能够展开二维向量的迭代器。该迭代器需要支持 next 和 hasNext 两种操作。、

// 示例：

// Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

// iterator.next(); // 返回 1
// iterator.next(); // 返回 2
// iterator.next(); // 返回 3
// iterator.hasNext(); // 返回 true
// iterator.hasNext(); // 返回 true
// iterator.next(); // 返回 4
// iterator.hasNext(); // 返回 false
 

// 注意：

// 请记得 重置 在 Vector2D 中声明的类变量（静态变量），因为类变量会 在多个测试用例中保持不变，影响判题准确。请 查阅 这里。
// 你可以假定 next() 的调用总是合法的，即当 next() 被调用时，二维向量总是存在至少一个后续元素
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
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        v.insert(v.begin(), {0});
        vEnd = v.end();
        curRow = v.begin();
        inner = curRow->begin();
    }

    int next() {
        ++inner;
        while(inner == curRow->end()) {
            ++curRow;
            inner = curRow->begin();
        }
        return *inner;
    }

    bool hasNext() {
        auto tempRow = curRow;
        auto tempInner = inner;

        ++tempInner;
        if(tempInner != tempRow->end()) return true;

        do {
            ++tempRow;
            if(tempRow == vEnd) return false;
            tempInner = tempRow->begin();
        } while(tempInner == tempRow->end());
        return true;
    }
private:
    vector<vector<int>>::iterator vEnd;
    vector<vector<int>>::iterator curRow;
    vector<int>::iterator inner;
};