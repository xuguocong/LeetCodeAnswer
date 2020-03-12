// 130. 被围绕的区域
// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

// 示例:

// X X X X
// X O O X
// X X O X
// X O X X
// 运行你的函数后，矩阵变为：

// X X X X
// X X X X
// X X X X
// X O X X
// 解释:

// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i, j;
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        for(i = 0; i < row; ++i) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][col-1] == 'O') dfs(board, i, col-1);
        }
        for(j = 1; j < col - 1; ++j) {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[row-1][j] == 'O') dfs(board, row-1, j);
        }
        for(i = 0; i < row; ++i) {
            for(j = 0; j < col; ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == '1') {
                    board[i][j] = '1';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '1';
        if(i - 1 > 0 && board[i-1][j] == 'O') dfs(board, i-1, j);
        if(i + 1 < board.size() && board[i+1][j] == 'O') dfs(board, i+1, j);
        if(j - 1 > 0 && board[i][j-1] == 'O') dfs(board, i, j-1);
        if(j + 1 < board[0].size() && board[i][j+1] == 'O') dfs(board, i, j+1);
    }
};


int main() {
    Solution test;
    return 0;
}