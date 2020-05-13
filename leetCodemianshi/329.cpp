// 329. 矩阵中的最长递增路径
// 给定一个整数矩阵，找出最长递增路径的长度。

// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

// 示例 1:

// 输入: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// 输出: 4 
// 解释: 最长递增路径为 [1, 2, 6, 9]。
// 示例 2:

// 输入: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// 输出: 4 
// 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
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
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int> > memo;
    int dfs(vector<vector<int> >& matrix, int r, int c, int R, int C) {
        if (memo[r][c] != 0) {
            return memo[r][c];
        }
        int t = 0;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && matrix[nr][nc] > matrix[r][c]) {
                t = max(t, dfs(matrix, nr, nc, R, C));
            }
        }
        memo[r][c] = 1 + t;
        return memo[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int R = matrix.size();
        int C = matrix[0].size();
        memo = vector<vector<int> >(R, vector<int>(C, 0));
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res = max(res, dfs(matrix, i, j, R, C));
            }
        }
        return res;
    }

};
