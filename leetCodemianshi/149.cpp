// 149. 直线上最多的点数
// 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

// 示例 1:

// 输入: [[1,1],[2,2],[3,3]]
// 输出: 3
// 解释:
// ^
// |
// |        o
// |     o
// |  o
// +------------->
// 0  1  2  3  4
// 示例 2:

// 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// 输出: 4
// 解释:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3) return points.size();
        int maxP = 2;
        for(int i = 0; i < points.size(); ++i) {
            int same = 1;
            for(int j = i + 1; j < points.size(); ++j) {
                int count = 0;
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++same;
                } else {
                    ++count;
                    long long dx = (long long)(points[i][0] - points[j][0]);
                    long long dy = (long long)(points[i][1] - points[j][1]);
                    for(int k = j + 1; k < points.size(); ++k) {
                        if(dx * (points[i][1] - points[k][1]) == dy * (points[i][0] - points[k][0])) {
                            ++count;
                        }
                    }
                }
                maxP = max(maxP, same + count);
            }
            if(maxP > points.size() / 2) {
                return maxP;
            }
        }
        return maxP;
    }
};


int main() {
    Solution test;
    return 0;
}