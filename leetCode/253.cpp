// 253. 会议室 II
// 给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

// 示例 1:

// 输入: [[0, 30],[5, 10],[15, 20]]
// 输出: 2
// 示例 2:

// 输入: [[7,10],[2,4]]
// 输出: 1
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

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> p;
        for(auto v : intervals) {
            p.push_back({v[0], 1});
            p.push_back({v[1], -1});
        }
        sort(p.begin(), p.end());

        int res = 0;
        int count = 0;
        for(auto x : p) {
            count += x.second;
            res = res > count ? res : count;
        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}