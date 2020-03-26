// 308. 二维区域和检索 - 可变
// 给你一个 2D 矩阵 matrix，请计算出从左上角 (row1, col1) 到右下角 (row2, col2) 组成的矩形中所有元素的和。

// Range Sum Query 2D
// 上述粉色矩形框内的，该矩形由左上角 (row1, col1) = (2, 1) 和右下角 (row2, col2) = (4, 3) 确定。其中，所包括的元素总和 sum = 8。

// 示例：

// 给定 matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
 

// 注意:

// 矩阵 matrix 的值只能通过 update 函数来进行修改
// 你可以默认 update 函数和 sumRegion 函数的调用次数是均匀分布的
// 你可以默认 row1 ≤ row2，col1 ≤ col2
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
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int i = 1; i <= matrix[0].size(); ++i){
            dp[0][i]=dp[0][i-1]+matrix[0][i-1];
        }
        for(int i = 1; i <= matrix.size(); ++i){
            int cur_sum = 0;
            for(int j = 1;j <= matrix[0].size(); ++j){
                cur_sum += matrix[i-1][j-1];
                dp[i][j] = dp[i-1][j] + cur_sum;
            }
        }
    }

    void update(int row, int col, int val) {
        // if(row < 0 || row > dp.size() - 1 || col < 0 || col > dp[0].size() - 1) return;
        int dif = val - (dp[row+1][col+1] - dp[row][col+1] - dp[row+1][col] + dp[row][col]);//差值
        for(int i = row + 1; i < dp.size(); ++i){
            for(int j = col + 1; j < dp[0].size(); ++j){
                dp[i][j] += dif;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (dp.empty()) return 0;
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
};