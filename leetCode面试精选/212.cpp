// 212. 单词搜索 II
// 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

// 示例:

// 输入: 
// words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]

// 输出: ["eat","oath"]
// 说明:
// 你可以假设所有输入都由小写字母 a-z 组成。

// 提示:

// 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
// 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
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
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        for(int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string &word) {
        Trie *s = this;
        for(char c : word) {
            if(!s->child[c - 'a']) {
                s->child[c - 'a'] = new Trie();
            }
            s = s->child[c - 'a'];
        }
        s->str = word;
        s->isWord = true;
    }

    /** Returns if the word is in the trie. */
    void search(vector<string> &res , vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                findWords(res, board, this, i, j);
            }
        }
    }

    void findWords(vector<string> &res , vector<vector<char>>& board, Trie *p, int i, int j) {
        if(p->isWord) {
            p->isWord = false;
            res.push_back(p->str);
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(board[i][j] == '#'|| p->child[board[i][j]-'a'] == nullptr)return;
        p = p->child[board[i][j]-'a'];
        char temp = board[i][j];
        board[i][j] = '#';
        findWords(res, board, p, i+1, j);
        findWords(res, board, p, i-1, j);
        findWords(res, board, p, i, j+1);
        findWords(res, board, p, i, j-1);
        board[i][j] = temp;
    }

private:
    Trie *child[26];
    string str;
    bool isWord;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie w;
        vector<string> res;
        for(string &s : words) w.insert(s);
        w.search(res, board);
        return res;
    }
};

int main() {
    return 0;
}