// 56. 合并区间
// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        int p2 = 1, count = 0;
        intervals[count] = intervals[0];
        while(p2 < intervals.size()) {
            if(intervals[p2][0] <= intervals[count][1]) {
                if(intervals[p2][1] > intervals[count][1]) {
                    intervals[count][1] = intervals[p2][1];
                }
            } else {
                ++count;
                intervals[count][0] = intervals[p2][0];
                intervals[count][1] = intervals[p2][1];
            }
            p2++;
        }
        int len = intervals.size();
        while(++count < len) intervals.pop_back();
        return intervals;
    }
};


int main() {
    Solution test;
    vector<vector<int>> t = {{1,4}, {4,5}};
    vector<vector<int>> t1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    test.merge(t1);
    return 0;
}