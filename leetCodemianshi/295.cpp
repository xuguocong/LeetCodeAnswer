// 295. 数据流的中位数
// 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

// 例如，

// [2,3,4] 的中位数是 3

// [2,3] 的中位数是 (2 + 3) / 2 = 2.5

// 设计一个支持以下两种操作的数据结构：

// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。
// 示例：

// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
// 进阶:

// 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
// 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<set>
#include<bitset>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> data;
    multiset<int>::iterator mid;
    MedianFinder(): mid(data.end()) {

    }

    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        if (n == 0) {
            mid = data.begin();
        } else if (num < *mid) {
            mid = (n & 1 ? mid : prev(mid));
        } else {
            mid = (n & 1 ? next(mid) : mid);
        }
    }

    double findMedian() {
        return (data.size() & 1) ? double(*mid) : (double)(*mid + *prev(mid)) * 0.5;
    }
};