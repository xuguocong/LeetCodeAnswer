// 200. 岛屿数量
// 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

// 示例 1:

// 输入:
// 11110
// 11010
// 11000
// 00000

// 输出: 1
// 示例 2:

// 输入:
// 11000
// 11000
// 00100
// 00011

// 输出: 3

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int numIslands_dfs(vector<vector<char>>& grid) {
        int res = 0;
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty()) {
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        if(r - 1 >= 0 && grid[r-1][c] == '1') {
                            q.push({r - 1, c});
                            grid[r-1][c] = '0';
                        }
                        if(r +1 < nr && grid[r+1][c] == '1') {
                            q.push({r + 1, c});
                            grid[r+1][c] = '0';
                        }
                        if(c - 1 >= 0 && grid[r][c-1] == '1') {
                            q.push({r, c - 1});
                            grid[r][c-1] = '0';
                        }
                        if(c + 1 < nc && grid[r][c+1] == '1') {
                            q.push({r, c + 1});
                            grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }

    int numIslands_bfs(vector<vector<char>>& grid) {
        int res = 0;
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();


        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if(r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if(r +1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if(c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if(c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }
};


int main() {
    Solution test;
    return 0;
}