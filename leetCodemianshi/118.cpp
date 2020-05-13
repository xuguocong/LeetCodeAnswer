// 118. 杨辉三角
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
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
    // vector<vector<int>> res = {{1}, {1,1}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1}}
    vector<vector<int>> res = {{1}, {1,1}};
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};
        if(numRows == 2) return res;
        for(int i = 3; i <= numRows; ++i) {
            vector<int> item(i);
            item[0] = 1;
            item[i-1] = 1;
            for(int j = 1; j < i - 1; ++j) {
                item[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.push_back(item);
        }
        return res;
    }
};


int main() {
    Solution test;
    return 0;
}