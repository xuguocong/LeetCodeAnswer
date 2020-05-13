// 378. 有序矩阵中第K小的元素
// 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
// 请注意，它是排序后的第k小元素，而不是第k个元素。

// 示例:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// 返回 13。
// 说明:
// 你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),
            left = matrix[0][0],
            right = matrix[n-1][n-1];
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = count(matrix, mid);
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int count(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while(i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                res += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};
