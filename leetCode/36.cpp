// 36. 有效的数独
// 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


// 上图是一个部分填充的有效的数独。

// 数独部分空格内已填入了数字，空白格用 '.' 表示。

// 示例 1:

// 输入:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// 输出: true
// 示例 2:

// 输入:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// 输出: false
// 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//      但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
// 说明:

// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 给定数独序列只包含数字 1-9 和字符 '.' 。
// 给定数独永远是 9x9 形式的。
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={0};
        int column[9][10]={0};
        int sbox[9][10]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               if(board[i][j] == '.') continue;

               int value=board[i][j]-'0';
               if(row[i][value])    return false;
               if(column[j][value]) return false;
               int k=i/3*3+j/3;
               if(sbox[k][value])   return false;
               row[i][value]++;
               column[j][value]++;
               sbox[k][value]++;
            }
        }
        return true;
    //     unordered_map<int, bool> row[9];
    //     unordered_map<int, bool> col[9];
    //     unordered_map<int, bool> box[9];
    //     for(int i = 0; i < 9; i++) {
    //         for(int j = 0; j < 9; j++) {
    //             if(board[i][j] >= '1' && board[i][j] <= '9') {
    //                 int num = int(board[i][j] - '0');
    //                 if(row[i][num] == false) {
    //                     row[i].insert({num, true});
    //                 } else {
    //                     return false;
    //                 }
    //                 if(col[j][num] == false) {
    //                     col[j].insert({num, true});
    //                 } else {
    //                     return false;
    //                 }
    //                 if(box[i / 3 * 3 + j / 3][num] == false) {
    //                     box[i / 3 * 3 + j / 3].insert({num, true});
    //                 } else {
    //                     return false;
    //                 }
    //             }
    //         }
    //     }
    //     return true;
    }
};


int main() {
    Solution test;
    return 0;
}