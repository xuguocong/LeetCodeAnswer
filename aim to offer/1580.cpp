// 面试题13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

// 示例 1：

// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：

// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：

// 1 <= n,m <= 100
// 0 <= k <= 20

#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
	int getNum(int i) {
		if (i >= 0) {
			i = i / 10 + i % 10;
		}
		return i;
	}

public:
	int movingCount(int m, int n, int k) {
		int res = 0;
		queue<pair<int, int>> q;
		q.push({0, 0});
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		visited[0][0] = true;
		while (!q.empty()) {
			int len = q.size();

			for (int i = 0; i < len; ++i) {
				pair<int, int> temp = q.front();
				q.pop();
				if (getNum(temp.first) + getNum(temp.second) <= k) {
					++res;
					if (temp.first < m - 1 && visited[temp.first + 1][temp.second] == false) {
						visited[temp.first + 1][temp.second] = true;
						q.push({temp.first + 1, temp.second});
					}
					if (temp.second < n - 1 && visited[temp.first][temp.second + 1] == false) {
						visited[temp.first][temp.second + 1] = true;
						q.push({temp.first, temp.second + 1});
					}
				}
			}
		}
		return res;
	}
};

int main() {
	Solution test;
	test.movingCount(3, 2, 17);
	return 0;
}

