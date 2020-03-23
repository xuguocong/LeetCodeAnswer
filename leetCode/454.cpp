// 454. 四数相加 II
// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

// 例如:

// 输入:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]

// 输出:
// 2

// 解释:
// 两个元组如下:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty()) return 0;
        int n = A.size();
        unordered_map<int, int> AB;
        unordered_map<int, int> CD;
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ++AB[A[i]+B[j]];
                ++CD[C[i]+D[j]];
            }
        }
        int res = 0;
        for (auto m : AB) {
            if (CD.find(-m.first) != CD.end()) {
                res += (CD[-m.first] * m.second);
            }
        }
        return res;
    }
};