// 412. Fizz Buzz
// 写一个程序，输出从 1 到 n 数字的字符串表示。

// 1. 如果 n 是3的倍数，输出“Fizz”；

// 2. 如果 n 是5的倍数，输出“Buzz”；

// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

// 示例：

// n = 15,

// 返回:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]
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
    pair<int, string> map[2] = {{3, "Fizz"}, {5, "Buzz"}};
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; ++i) {
            string item= "";
            for(auto m : map) {
                if (i % m.first == 0) item += m.second;
            }
            if (item == "") {
                res.push_back(to_string(i));
            } else {
                res.push_back(item);
            }
        }
        return res;
    }
};