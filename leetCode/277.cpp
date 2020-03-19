// 277. 搜寻名人
// 假设你是一个专业的狗仔，参加了一个 n 人派对，其中每个人被从 0 到 n - 1 标号。在这个派对人群当中可能存在一位 “名人”。所谓 “名人” 的定义是：其他所有 n - 1 个人都认识他/她，而他/她并不认识其他任何人。

// 现在你想要确认这个 “名人” 是谁，或者确定这里没有 “名人”。而你唯一能做的就是问诸如 “A 你好呀，请问你认不认识 B呀？” 的问题，以确定 A 是否认识 B。你需要在（渐近意义上）尽可能少的问题内来确定这位 “名人” 是谁（或者确定这里没有 “名人”）。

// 在本题中，你可以使用辅助函数 bool knows(a, b) 获取到 A 是否认识 B。请你来实现一个函数 int findCelebrity(n)。

// 派对最多只会有一个 “名人” 参加。若 “名人” 存在，请返回他/她的编号；若 “名人” 不存在，请返回 -1。

 

// 示例 1:



// 输入: graph = [
//   [1,1,0],
//   [0,1,0],
//   [1,1,1]
// ]
// 输出: 1
// 解析: 有编号分别为 0、1 和 2 的三个人。graph[i][j] = 1 代表编号为 i 的人认识编号为 j 的人，而 graph[i][j] = 0 则代表编号为 i 的人不认识编号为 j 的人。“名人” 是编号 1 的人，因为 0 和 2 均认识他/她，但 1 不认识任何人。
// 示例 2:



// 输入: graph = [
//   [1,0,1],
//   [1,1,0],
//   [0,1,1]
// ]
// 输出: -1
// 解析: 没有 “名人”
 

// 注意:

// 该有向图是以邻接矩阵的形式给出的，是一个 n × n 的矩阵， a[i][j] = 1 代表 i 与 j 认识，a[i][j] = 0 则代表 i 与 j 不认识。
// 请记住，您是无法直接访问邻接矩阵的。
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


vector<vector<bool>> tt = {{1,1,0}, {0,1,0}, {1,1,1}};
bool knows(int a, int b) {
    if(tt[a][b])return true;
    return false;
}
class Solution {
public:
    int findCelebrity(int n) {
        unordered_map<int, int> know;
        unordered_map<int, int> beKnowed;
        for(int i = 0; i < n ; ++i) {
            for(int j = 0; j < n; ++j) {
                if (knows(i,j)) {
                    ++know[i];
                    ++beKnowed[j];
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if(know[i] == 1 && beKnowed[i] == n) return i;
        }
        return -1;
    }

    int findCelebrity2(int n){
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(res, i)) {
                res = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i == res) continue;
            if (knows(res, i)) return -1;
            if (!knows(i, res)) return -1;
        }
        return res;
    }
};


int main() {
    Solution test;
    test.findCelebrity(3);
    return 0;
}