// 79. 单词搜索
// 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 示例:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// 给定 word = "ABCCED", 返回 true.
// 给定 word = "SEE", 返回 true.
// 给定 word = "ABCB", 返回 false.

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool exist_dfs(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(bfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool bfs(vector<vector<char>>& board, string &word, int i, int j, int length) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || length >= word.length() || word[length] != board[i][j]) {
            return false;
        }
        if(length == word.length() - 1 && word[length] == board[i][j]) {
            return true;
        }
        int temp = board[i][j];
        board[i][j] = '0';
        bool flag = bfs(board, word, i-1, j, length+1) || bfs(board, word, i+1, j, length+1) || bfs(board, word, i, j-1, length+1) || bfs(board, word, i, j+1, length+1);
        board[i][j] = temp;
        return flag;
    }
};


int main() {
    Solution test;
    vector<int> nums = {1,2,3};
    return 0;
}