// 269. 火星词典
// 现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。

// 假设，您并不知道其中字母之间的先后顺序。但是，会收到词典中获得一个 不为空的 单词列表。因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。

// 您需要根据这个输入的列表，还原出此语言中已知的字母顺序。

// 示例 1：

// 输入:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]

// 输出: "wertf"
// 示例 2：

// 输入:
// [
//   "z",
//   "x"
// ]

// 输出: "zx"
// 示例 3：

// 输入:
// [
//   "z",
//   "x",
//   "z"
// ] 

// 输出: "" 

// 解释: 此顺序是非法的，因此返回 ""。
// 注意：

// 你可以默认输入的全部都是小写字母
// 假如，a 的字母排列顺序优先于 b，那么在给定的词典当中 a 定先出现在 b 前面
// 若给定的顺序是不合法的，则返回空字符串即可
// 若存在多种可能的合法字母顺序，请返回其中任意一种顺序即可
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
    Solution(): count(0), indgreed(26, -1), graph(26), flag(true) {};
    bool init(vector<string>& words) {
        for(char c : words[0]) {
            if(indgreed[c - 'a'] == -1) {
                ++count;
                indgreed[c - 'a'] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; ++i) {
            for(char c : words[i+1]) {
                if(indgreed[c - 'a'] == -1) {
                    ++count;
                    indgreed[c - 'a'] = 0;
                }
            }
            int size = max(words[i].size(), words[i+1].size());
            for (int j = 0; j < size; ++j) {
                if(j >= words[i+1].size()) {
                    return false;
                }
                if(j >= words[i].size()) {
                    break;
                }
                char from = words[i][j], to = words[i + 1][j];
                if (from == to) continue;
                graph[from - 'a'].push_back(to - 'a');
                ++indgreed[to - 'a'];
                break;
            }
        }
        return true;
    }

    string topology_sort() {
        string res = "";

        queue<int> q;
        for(int i = 0; i < 26; ++i) {
            if (indgreed[i] > 0 || indgreed[i] == -1) {
                continue;
            }
            q.push(i);
            res += (i + 'a');
        }

        while(!q.empty()) {
            for(int i = q.size(); i > 0; --i) {
                int from = q.front();
                q.pop();
                for(int to : graph[from]) {
                    if (indgreed[to] == 1) {
                        q.push(to);
                        res += (to + 'a');
                    }
                    --indgreed[to];
                }
            }
        }

        if(count == res.size()) {
            return res;
        }
        return "";
    }
    string alienOrder(vector<string>& words) {
        if (init(words) == false) {
            return "";
        }
        return topology_sort();
    }
private:
    vector<int> indgreed;
    vector<vector<int>> graph;
    int count;
    bool flag;
};


int main() {
    Solution test();
    return 0;
}